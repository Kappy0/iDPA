// Ryan Klaproth
//
// Homework 2
// 
// Due 4/12/12
// 
// Linked Lists

#ifndef SLLIST_H
#define SLLIST_H


#include <iostream>
using namespace std;


//=======================================================================
// Template class SLList
//  A singly linked list implemented with a header node, but no tail node.
//  It also maintains only a pointer to the header node.
//=======================================================================
template<typename T>
class SLList
{
private:
  /*-------------------------------------------------------
   * Class Node (as a nested class)
   * ------------------------------
   * It is in the private section of the SLList, so only the members
   * in SLList can use 'Node' as a data type.
   * However the members in Node are public (because struct), so
   * SLList can access members in a Node object freely.
   *------------------------------------------------------*/
  struct Node
  {
    // constructor
    Node(const T& val= T(), Node* next_ptr=NULL) : data(val), next(next_ptr) { }
 
    // data members
    T data;
    Node *next;
  };


public:
  SLList();
  SLList(const SLList & lst2);
  ~SLList();
  const SLList& operator=(const SLList & rhs);


  int size() const;
  void print() const;
  bool find(const T& val) const;
  void add(const T& val);
  void remove(const T& val);


  // Some helper functions.  They are made public because
  // they are rather convenient.
  void clear();


private:
  Node *head;


  // This function is private, because it involves Nodes.
  static void copyNodeList(const Node* from, Node *&to);


};


template<typename T>
SLList<T>::SLList()
{
	// Creates a dummy header node.
	head = new Node;
}


template<typename T>
SLList<T>::SLList(const SLList &lst2)
{
	copyNodeList(lst2.head, head);
}

template<typename T>
void SLList<T>::copyNodeList(const Node *from, Node *&to)
{
	// Build a list to 'to' from copying values from 'from'.
	// 'from' is supposed to point to the header node of the list.
	// 'to' is assumed to be a null pointer (to which a new list is built).

	// First create a dummy header node for 'to'.
	// Assigning it to 'to' works, because it is passed by reference.
	to = new Node;

	// Set up two Node pointers -- one is used to traverse this list,
	// and another is used to traverse the parameter list.
	Node *p1, *p2;
	p1 = to;
	p2 = from->next;

	// Traverse the 'from' list by using p2.  For each node, create a new node 
	// and append to 'to' through p1.
	while (p2 != NULL) 
	{
		p1->next = new Node(p2->data);
		p1 = p1->next;
		p2 = p2->next;
	}
}  


template<typename T>
SLList<T>::~SLList()
{
	// Delete all nodes including the dummy header node.
	// First call clear() to delete all nodes except for the dummy header.
	clear();
	// Then delete the header node.
	delete head;
}


template<typename T>
void SLList<T>::clear()
{
	// Deletes all nodes in the list except for the dummy header.
	Node* temp;

	// Always delete the first node (after the dummy) for efficiency.
	while (head->next != NULL) 
	{
		temp = head->next;
		cout << "Deleting Node " << temp->data << endl;
		head->next = temp->next; // jump over the node pointed by temp
		delete temp;
	}
	// Finally null-out the head->next.
	head->next = NULL;
}


template<typename T>
const SLList<T>& SLList<T>::operator=(const SLList &rhs)
{
	if (this != &rhs)
	{
		clear();
		// Then delete the header node.
		delete head;
		// Then copy the list from rhs.
		copyNodeList(rhs.head, head);
	}
	return *this;
}


template<typename T>
int SLList<T>::size() const
{
	int count = 0;
	for (Node *ptr = head->next; ptr != NULL; count++, ptr = ptr->next);
	return count;
}


template<typename T>
void SLList<T>::print() const
{
	Node *ptr = head->next;
	cout << "[" << ptr->data;


	for (ptr = ptr->next; ptr != NULL; ptr = ptr->next)
	cout << ", " << ptr->data;
  
	cout << "]" << endl;
}


template<typename T>
bool SLList<T>::find(const T& val) const
{
	for (Node *ptr = head->next; ptr != NULL; ptr = ptr->next) 
	{
		if (ptr->data == val)
		{
			return true;
		}
	}
	return false;
}


template<typename T>
void SLList<T>::add(const T& val)
{
	if (!find(val)) 
	{
		// Add a new node in front of the list
		head->next = new Node(val, head->next);
	}
}


template<typename T>
void SLList<T>::remove(const T& val)
{
	// Remove all occurrences of val in the list.
	// But this SLList doesn't allow duplicate elements, so
	// we can exit early after deletion...
	Node *ptr = head;
	while (ptr->next != NULL) 
	{
		if (ptr->next->data == val) 
		{
			Node *temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
			return; // early exit
		}
		else
		{
			// This 'else' is critical in case the last node is deleted.
			ptr = ptr->next;
		}
	}
}


#endif
#-------------------------------------------------------------------------------
# Name:        Stacks
# Purpose:      Shows how stacks are used in Python
#
# Author:      Kappy
#
# Created:     18/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import random

def peek(hand) :
    topCard = hand.pop()
    hand.append(topCard)
    return topCard

def main():
    class card :
        def __init__(self, suit, value) :
            self.suit = suit
            self.value = value

        def getSuit(self) :
            return self.suit

        def getValue(self) :
            return self.value

        def __str__(self) :
            card = self.value + ' of ' + self.suit
            return card


    suits = ['Clubs', 'Diamonds', 'Hearts', 'Spades']
    faces = ['Jack', 'Queen', 'King', 'Ace']

    values = []

    for value in range(2, 11) :
        values.append(str(value))

    values.extend(faces)

    deck = []

    for i in suits :
        for j in values :
            newCard = card(i, j)
            deck.append(newCard)

    hand = []
    for i in range(0, 5) :
        hand.append(random.choice(deck))

    topCard = peek(hand)
    print(topCard)


if __name__ == '__main__':
    main()

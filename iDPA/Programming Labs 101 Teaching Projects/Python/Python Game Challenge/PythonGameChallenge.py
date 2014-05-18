#-------------------------------------------------------------------------------
# Name:        Python Game Challenge
# Purpose:      The Python Game Challenge
#
# Author:      Kappy
#
# Created:     18/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import random

#Asks the player if they want to stack the current card
def ask() :
    print('Do you want to stack this card?')
    return input().lower().startswith('y')

#Asks the player if they'd like to play again
def playAgain() :
    print('Do you want to play again? (Yes or No)')
    return input().lower().startswith('y')
    print()

#Class to create a card
class Card :
    def __init__(self, rank, suit) :
        self.rank = rank
        self.suit = suit

    def Rank(self) :
        return "Ace Two Three Four Five Six Seven Eight Nine Ten Jack Queen King".split()[self.rank]

    def Suit(self) :
        return "Hearts Spades Clubs Diamonds".split()[self.suit]

    def __str__(self) :
        return self.Rank() + " of " + self.Suit()

#Class to create a hand
class Hand :
    def __init__(self) :
        self.cards = []

    def add(self, card) :
        self.cards.append(card)

    def Rank(self) :
        cardRank = 0
        for card in self.cards :
            cardRank = card.rank
        return cardRank

    def Show(self, show_only = None) :
        if not show_only :
            for k in self.cards :
                print (k)
        else :
            if isinstance(show_only, int) :
                print (self.cards[show_only])
            elif isinstance(show_only, (list,tuple)) :
                for idx in show_only :
                    print (self.cards[idx])

    def pop(self) :
        return self.cards.pop()

#Class for card stacks (discard pile and the stack you're using
class cardStack :
    def __init__(self) :
        self.cards = []

    def add(self, card) :
        self.cards.append(card)

    def Rank(self) :
        cardRank = 0
        for card in self.cards :
            cardRank = card.rank
        return cardRank

    def Show(self, show_only = None) :
        if not show_only :
            for k in self.cards :
                print (k)
        else :
            if isinstance(show_only, int) :
                print (self.cards[show_only])
            elif isinstance(show_only, (list,tuple)) :
                for idx in show_only :
                    print (self.cards[idx])

#Creates the deck the player will use
class deck :
    def __init__(self ):
        self.cards = []
        for i in range(4) :
            for j in range(13) :
                self.cards.append(Card(j, i))
        random.shuffle(self.cards)

    def shuffle(self ) :
        random.shuffle(self.cards)

    def pop(self) :
        return self.cards.pop()

d = deck()
stack = cardStack()
discardPile = cardStack()
playerHand = Hand()
playerHand.add(d.pop())
playerHand.Show()
drawCount = 0
stackCount = 0
finished = False

while True :
    #If the card in hand is larger than the card currently on top of the stack,
    #add it to the stack. Otherwise, send it to the discard pile. If the user
    #chooses not to stack, then the card is automatically sent to the discard
    #pile
    if(ask()) :
        if(stack) :
            if(playerHand.Rank() > stack.Rank()) :
                print(playerHand.Rank(),"added to the stack")
                print()
                stack.add(playerHand.pop())
                stackCount += 1
                #Aces can be stacked onto Kings
            elif(playerHand.Rank() == 0 and stack.Rank() == 12) :
                print(playerHand.Rank(),"added to the stack")
                print()
                stack.add(playerHand.pop())
                stackCount += 1
            else :
                print("You can't stack that card!")
                print()
                discardPile.add(playerHand.pop())
        else :
            print(playerHand.Rank(),"added to the stack")
            print()
            stack.add(playerHand.pop())
            stackCount += 1


    else :
        print('Drawing another card...')
        print()
        discardPile.add(playerHand.pop())

    print('Discard Pile')
    discardPile.Show()
    print()

    print('Stack:')
    stack.Show()
    print()

    playerHand.add(d.pop())
    drawCount += 1
    print("Hand:")
    playerHand.Show()
    print()

    if drawCount > 20 :
        finished = True
        print("You have exceeded the draw limit")
        if stackCount >= 10 :
            print("You have 10 or more cards stacked. You win!")
        else :
            print("You have less than 10 cards stacked. You lose...")

    #Reset the game if the player wishes
    if(finished) :
        if(playAgain()) :
            finished = False
            d = deck()
            drawCount = 0
            stackCount = 0
            stack = cardStack()
            discardPile = cardStack()
            playerHand = Hand()
            playerHand.add(d.pop())
            playerHand.Show()
        else :
            break









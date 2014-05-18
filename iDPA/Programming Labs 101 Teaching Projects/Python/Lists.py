#-------------------------------------------------------------------------------
# Name:        Lists
# Purpose:      Demonstrates lists in Python
#
# Author:      Kappy
#
# Created:     18/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import random

def compareCards(card1, card2) :

    value1 = card1.value
    value2 = card2.value

    if(value1 == 'Jack') :
        value1 = str(11)
    elif(value1 == 'Queen') :
        value1 = str(12)
    elif(value1 == 'King') :
        value1 = str(13)
    elif(value1 == 'Ace') :
        value1 = str(14)

    if(value2 == 'Jack') :
        value2 = str(11)
    elif(value2 == 'Queen') :
        value2 = str(12)
    elif(value2 == 'King') :
        value2 = str(13)
    elif(value2 == 'Ace') :
        value2 = str(14)

    if (int(value2) > int(value1)) :
        print(card1, 'is less than', card2)
    elif (int(value1) > int(value2)) :
        print(card2, 'is less than', card1)
    else :
        print(card1, 'and', card2, 'are equal')

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

    cardPicked1 = random.choice(deck)
    cardPicked2 = random.choice(deck)

    print(cardPicked1, ",", cardPicked2)

    compareCards(cardPicked1, cardPicked2)


if __name__ == '__main__':
    main()

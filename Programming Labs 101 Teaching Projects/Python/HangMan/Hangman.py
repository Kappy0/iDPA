#-------------------------------------------------------------------------------
# Name:        Hangman
# Purpose:      Simplified version of Hangman
#
# Author:      Kappy
#
# Created:     17/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

#User inputs what the word to be guessed is
def getWord() :
    word = input("Enter a word to guess:")
    return word;

#Displays the board
def display(missedLetters, correctLetters, word) :
    print('Missed letters:', end = ' ')
    print()

    #Print out incorrectly guessed letters
    for letter in missedLetters :
        print(letter, end = ' ')
    print()

    #Create the blanks for the word to be guessed
    blank = '_' * len(word)

    #Replace blanks with correct letters
    for letter in range(len(word)) :
        if(word[letter] in correctLetters) :
            blank = blank[:letter] + word[letter] + blank[letter + 1:]

    #Print letters and blanks
    for letter in blank :
        print(letter, end = ' ')
    print()

#Returns letter the player guessed
def getGuess(guessed) :

    #Ensures that only one letter is guessed and keeps track of previous guesses
    while True :
        print('Guess a letter.')
        guess = input()
        guess = guess.lower()
        if len(guess) != 1 :
            print('Please enter a single letter.')
        elif guess in guessed :
            print('You have already guessed that letter. Guess another.')
        elif guess not in 'abcdefghijklmnopqrstuvwxyz' :
            print('Please enter a letter.')
        else :
            return guess

#Asks the user to play again
def playAgain() :
    print('Do you want to play again? (Yes or No)')
    return input().lower().startswith('y')

print('H A N G M A N')
missedLetters = ''
correctLetters = ''
word = getWord()
finished = False

while True :
    display(missedLetters, correctLetters, word)

    guess = getGuess(missedLetters + correctLetters)
    print()
    print()

    if guess in word :
        correctLetters = correctLetters + guess

        #Check if the player has won
        foundAllLetters = True
        for letter in range(len(word)) :
            if word[letter] not in correctLetters :
                foundAllLetters = False
                break
            if foundAllLetters :
                print('Yes! The word is "' + word + '"! You have won!')
                finished = True
    else :
        missedLetters = missedLetters + guess

        #Check if player has guessed too many times and lost
        if len(missedLetters) == len(word) :
            display(missedLetters, correctLetters, word)
            print('You have run out of guesses!\nAfter ' + str(len(missedLetters)) + ' missed guesses and ' + str(len(correctLetters)) + ' correct guesses, the word was "' + word + '"')
            finished = True


    # Ask the player if they want to play again (but only if the game is done).
    if finished :
        if playAgain() :
            missedLetters = ''
            correctLetters = ''
            finished = False
            word = getWord()
        else :
            break




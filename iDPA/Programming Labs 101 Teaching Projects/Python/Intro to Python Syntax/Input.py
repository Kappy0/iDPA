#-------------------------------------------------------------------------------
# Name:        Input
# Purpose:      Shows how to implement user input in Python
#
# Author:      Kappy
#
# Created:     17/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    userVal = input()
    userVal = int(userVal)
    print(userVal)

    userVal2 = 5
    print(userVal2)

    userVal3 = 6
    print(userVal + userVal2 - userVal3)

if __name__ == '__main__':
    main()
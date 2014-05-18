#-------------------------------------------------------------------------------
# Name:        Statements
# Purpose:      Shows if statments in Python
#
# Author:      Kappy
#
# Created:     17/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    i = 0
    x = 5
    y = input("Enter a number: ")
    y = int(y)

    if(y > x) :
        print(y, "is greater than", x)
    elif(y < x) :
        print(y, "is less than", x)
    else :
        print(y, "is equal to", x)

if __name__ == '__main__':
    main()
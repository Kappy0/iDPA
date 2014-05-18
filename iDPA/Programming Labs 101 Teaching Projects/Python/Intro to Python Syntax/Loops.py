#-------------------------------------------------------------------------------
# Name:        Loops
# Purpose:      Shows loops in Python
#
# Author:      Kappy
#
# Created:     17/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    i = 0
    while(i <= 5) :
        print("i is", i)
        i += 1

    list1 = [0, 5, 6, 2]
    list2 = range(4)
    list3 = range(10, 15)

    for x in list1:
        x *= 2
        print(x)

if __name__ == '__main__':
    main()
#-------------------------------------------------------------------------------
# Name:        Class
# Purpose:      Shows classes in Python
#
# Author:      Kappy
#
# Created:     18/06/2013
# Copyright:   (c) Kappy 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    class Pet :
        def __init__(self, name, age) :
            self.name = name
            self.age = age

    class Cat(Pet) :
        def _init__(self, name, age) :
            self.name = name
            self.age = age

        def meow(self) :
            print("Meow")


    ginger = Cat('Ginger', 10)
    ginger.meow()

if __name__ == '__main__':
    main()

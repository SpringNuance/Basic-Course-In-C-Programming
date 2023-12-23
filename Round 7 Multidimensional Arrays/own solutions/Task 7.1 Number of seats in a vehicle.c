/*
Below, you can find the main function that will need a **num_seats** enumeration to compile.
Your task is to implement this enumeration according to the main function and the
expected output that you can find below. Using these, you should figure what
elements there should be in the enumeration and what are their values.

When the program works correctly, it should print out the following:

    We have a variable test of type enum num_seats
    and it has an integer value of 1!!
    
    Number of seats in a bike is 1 
    Number of seats in a motorcycle is 2 
    Number of seats in a van is 3 
    Number of seats in a car is 5 
    Number of seats in a minivan is 7
*/

#include <stdio.h>

// STUDENT //define enumeration num_seats here
int main(void)
{
    enum num_seats{
		BIKE = 1,
		MOTORCYCLE = 2,
		VAN = 3,
		CAR = 5,
		MINIVAN = 7,
	};

    enum num_seats test = BIKE;
    printf("We have a variable test of type enum num_seats\n"
            "and it has an integer value of %d!!\n\n", test);
    
    for (unsigned int i = 0; i <= 10; i++) {
	switch(i) {
	   case BIKE: // = 1
		printf("Number of seats in a bike is %d\n", BIKE);
		break;
	   case MOTORCYCLE: // = 2
		printf("Number of seats in a motorcycle is %d\n", MOTORCYCLE);
		break;
	   case VAN: // = 3
		printf("Number of seats in a van is %d\n", VAN);
		break;
	   case CAR: // = 5
		printf("Number of seats in a car is %d\n", CAR);
		break;
	   case MINIVAN: // = 7
		printf("Number of seats in a minivan is %d\n", MINIVAN);
		break;
        } // switch
    } // for
    
    return 0;
}
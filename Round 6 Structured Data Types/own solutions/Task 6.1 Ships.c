/*
Below is a *main* function that uses a data structure names **Ship**
that hasn't, however, been defined yet. Therefore, if you try to compile and
execute the program by using the "Run" button, you will get a large number
of compiler warnings and errors.

The data structure to be defined should contain three fields:

name: that tells the name of the ship.

weight: that tells the weight in tonnes.
 
cargo: that is an array of strings. The array indicates the cargo of the
ship. The maximum length of the array will be statically defined in the
data structure (you can, for example, decide that the array contains at most
10 items). Recall that an array can be represented with *char* pointer.
You can also assume that the content of the strings will not be changed.

You can only modify the portion above the *main* function. Define there the
required data structure such that the program compiles and works without errors.
Investigate the *main* function to determine what the data structure should
exactly contain.
*/
#include <stdio.h>
#include <string.h>

// Define the missing structure here
struct Ship{
    char *name;
    float weight;
    char *cargo[10];
    
};

int main(void)
{
    struct Ship vessel_1 = { "Tanker", 100000, { NULL } };

    memset(vessel_1.cargo, 0, sizeof(vessel_1.cargo));
    vessel_1.cargo[0] = "Gasoline";
    vessel_1.cargo[1] = "Oil";

    struct Ship vessel_2;
    memset(vessel_2.cargo, 0, sizeof(vessel_2.cargo));
    vessel_2.name = "Fun boat";
    vessel_2.weight = 1.25;
    vessel_2.cargo[0] = "Food basket";
    vessel_2.cargo[1] = "Sunscreen";
    vessel_2.cargo[2] = "Very good lemonade";

    struct Ship ships[2];
    ships[0] = vessel_1;
    ships[1] = vessel_2;
    
    for (int i = 0; i < 2; i++) {
	    printf("Name: %s  / Weight %.2f tonnes\n", ships[i].name, ships[i].weight);
	    printf("Cargo:\n");
	    for (int j = 0; ships[i].cargo[j] != NULL; j++) {
	        printf("* %s\n", ships[i].cargo[j]);
	    }
	    printf("----------\n");
    }
    
    return 0;
}

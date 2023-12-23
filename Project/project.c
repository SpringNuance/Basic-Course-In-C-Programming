#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Nation object that keeps track of names and their medals count
struct nation {
    char *name;  // Name of nation (dynamically allocated)
	int gold; // Number of gold medals of this nation
	int silver; // Number of silver medals of this nation
	int bronze; // Number of bronze medals of this nation
};

// This helper function is used for addNation and updateMedals function to check if a nation is in the database or not
int checkNation(const char* nationName, struct nation *database){
    int index = -1;
    for (int i = 0; database[i].name != NULL; i++){ // Scanning the database
        if (!strcmp(database[i].name, nationName)){ // Name of the nation found!
            index = i; // If this nation is found, immediately storing its index
            return index; // Then return 
        }
    }
    return index; // If this line is reached, this nation is not found in the database and -1 is returned
}

/*
A nation: Add nation
Add ”nation” to the database. Initially each nation has no medals. For example: A Finland 
*/
struct nation* addNation (const char *nationName, int gold, int silver, int bronze, struct nation *database) {
	int i = 0;
    for ( ; database[i].name != NULL; i++); // Find the index i of the last element of the database
    database = realloc(database, sizeof(struct nation) * (i + 2)); // Memory reallocation for database
    database[i].name = malloc((strlen(nationName) + 1)); // Allocate dynamic memory for new nation name
    strcpy(database[i].name, nationName); // Copy the name into the memory
    // Default number of gold, silver and bronze medals when a nation is added
	database[i].gold = gold; 
	database[i].silver = silver;
	database[i].bronze = bronze;
	// New last element's name shall be NULL again 
    database[++i].name = NULL;
    return database;
}

/*
M nation gold silver bronze : Update medals

Adds the given amount of medals to the given country. 
For example M Finland 0 1 1 will add one silver and one bronze medal to Finland, in addition to existing medals. 
If the nation was not yet added using the A - command, an error message will be given. 
The medal counts are signed integers, and because of possible doping cases also negative adjustments need to 
be allowed, which means that the total count of the particular medal will be reduced. 
*/

int updateMedals(const char* nationName, int gold, int silver, int bronze, struct nation *database){
    int index = checkNation(nationName, database); // Check for index of this nation in the database

    if (index == -1) { // The nation is not found because the index has not changed
        return 0; // Return immediately 
    } else { // Nation found
		// Updating the medals
        database[index].gold += gold;
        database[index].silver += silver;
        database[index].bronze += bronze;
        return 1; // Successfully updated
    }
};

/*
L : Output medal table

Prints the current medal table, i.e. all nations in the memory along with their medal counts: 
first gold, then silver, and finally bronze, each nation on a separate line. 
The nations should be listed in order such as first the nation with most gold medals will be output. 
In cases where there are equal number of gold medals, the number of silver medals counts. 
If also the silver counts are equal, the number of bronze medals counts. 
This command is worth of two points such that if you output all nations and medal counts correctly, 
but in wrong order, you will get one point. 
If, in addition, also the order is correct, you will get a second point. 
*/

// Helper function to sort the nations based on their olympic medals. Priority: gold > silver > bronze
int compareMedals(const void *nationFirst, const void *nationSecond){
    struct nation* firstNation = (struct nation*) nationFirst; // Casting data type
    struct nation* secondNation = (struct nation*) nationSecond; // Casting data type
    int firstGold = firstNation -> gold; // Number of gold medals of first nation
    int firstSilver = firstNation -> silver; // Number of silver medals of first nation
    int firstBronze = firstNation -> bronze; // Number of bronze medals of first nation
    int secondGold = secondNation -> gold; // Number of gold medals of second nation
    int secondSilver = secondNation -> silver; // Number of silver medals of second nation
    int secondBronze = secondNation -> bronze; // Number of bronze medals of second nation
    
	// First compare gold medals. The nation with more gold medals is placed above
    if (firstGold < secondGold) return 1;
	else if (firstGold > secondGold) return -1;
	else {
		// If they have equal number of gold medals, compare their silver medals
        if (firstSilver < secondSilver) return 1;
	    else if (firstSilver > secondSilver) return -1;
        else {
			// If they have equal number of gold and silver medals, compare their bronze medals
            if (firstBronze < secondBronze) return 1;
	        else if (firstBronze > secondBronze) return -1;
			// If they have equal number of gold, silver and bronze medals, place them arbitrarily
	        else return 0;
        }
	}
}

// Main function to output the record table of olympic medals to the standard stream
void outputMedalTable(struct nation *database) {
    int sizeDatabase = 0;
    while (database[sizeDatabase].name != NULL){
        sizeDatabase++; // Determining the size of the database, excluding the last element whose name is NULL
    };

	// Sorting the database based on the helper function
    qsort(database, sizeDatabase, sizeof(struct nation), compareMedals); 
    
	// Printing the table
    for (int i = 0; i < sizeDatabase; i++){
	  printf("%s %d %d %d\n", database[i].name, database[i].gold, database[i].silver, database[i].bronze);
    };
}

/*
W filename : Save table

Writes the medal table to a file with given filename
*/
int saveTable(const char* filenameWrite, struct nation *database){
    FILE* filePtr = fopen(filenameWrite, "w"); // Open file stream with writing mode
    if (filePtr == NULL) return 0; // Return if file not found or fail to open
    
    for (int i = 0; database[i].name != NULL; i++){
        // Writing the database to the given file stream
        fprintf(filePtr, "%s %d %d %d\n", database[i].name, database[i].gold, database[i].silver, database[i].bronze);
    }
    // Closing the file stream
    fclose(filePtr);
    return 1;
};

/*
O filename : Load table

Loads the medal table from file, and replaces the existing table in memory
*/
struct nation * loadTable(const char* filenameRead, struct nation *database){
    FILE* filePtr = fopen(filenameRead, "r"); // Open file stream with reading mode
    if (filePtr == NULL) return NULL; // Return if file not found or fail to open
    // If file successfully open, free memory of the database just like Q (Exiting program)
    for (int i = 0; database[i].name != NULL ; i++){
        free(database[i].name);
    };
    free(database);
    // Starting process of building the database from the read file
    char lineExtracted[1000]; // storing each line of the file. Since the input is 1000, each line read should be at maximum 1000 chars.
    char nationName[989]; // Name of the country inputted. Its length is determined by 1000 subtracted by 4 spaces, one char command and 6 char for 3 medals
	int gold, silver, bronze; // Storing medals of countries
    struct nation * newDatabase = malloc(sizeof(struct nation)); // Create new database
    newDatabase[0].name = NULL; // Marking the end of the database
    fgets(lineExtracted, 1001, filePtr); // fgets reads at most size - 1 characters to the buffer pointed by s from I/O stream stream
    // Since input has 1000 chars, so size = 1001 will guarantee to read all inputs
    while (!feof(filePtr)){ // EOF is reached
        sscanf(lineExtracted, "%s %d %d %d", nationName, &gold, &silver, &bronze); // Extract the name and medals from the current line
        newDatabase = addNation(nationName, gold, silver, bronze, newDatabase); // Add the nation and its medals to the new database
        fgets(lineExtracted, 1001, filePtr);
    }
    // Closing the file stream
    fclose(filePtr);
    // return the new database
    return newDatabase;
    
};

/*
Q : Exit program

Exits program and releases all allocated memory. 
This operation must be implemented so that you can find all possible memory leaks.
*/

void exitProgram(struct nation *database){
    for (int i = 0; database[i].name != NULL ; i++){
        free(database[i].name); // Freeing the names
    };
    free(database); // Freeing the database
}

// Main body
int main() {
    // Introductory text and instructions for user
    printf("Welcome to Olympic medals database! Let's take Finland for example\n");
    printf("To add nation, type A Finland\n");
    printf("To update medals, type M Finland 1 2 3\n");
    printf("To list out the table of medals, type L\n");
    printf("To save data to a new file, type W filename\n");
    printf("To load data from an existing file, type O filename\n");
    printf("To exit program, type Q\n");
	char input[1000]; // storing user's input. Assumed to be maximum at 1000 chars
	char command; // letter that determines the function, should be one in 6 letters: A, M, L, W, O, Q
	char nationName[989]; // Name of the country inputted. Its length is determined by 1000 subtracted by 4 spaces, one char command and 6 char for 3 medals
	int gold, silver, bronze; // Storing medals of countries
    char filenameWrite[998]; // Name of the writing file that reads data from or writes data into. Its length is 1000 subtracted by one char command and 1 space
	char filenameRead[998]; // Name of the reading file that reads data from or writes data into. Its length is 1000 subtracted by one char command and 1 space
    char check[1000]; // Check whether the tail of input is not matching the requirements
	// For example, A Finland is accepted but A Finland 1 2 3 will output error. This variable will
	// check whether the tail of the input is empty or not.
	bool notStop = true; // Make while loop run infinitely unless it is quitted with inputting letter Q
	struct nation *database = malloc(sizeof(struct nation));
	database[0].name = NULL;
    if (database == NULL) {
      printf("The program fails to allocate memory for the database\n");
	  return 0; // If the program fails to allocate memory for the database
	}
	while (notStop) {
		fgets(input, 1000, stdin); // Reading the input from standard stream into input string
		command = input[0]; // Extracting the command letter
        switch(command) { // Do commands based on A, M, L, W, O, Q
        case 'A': ; // A nation: adding a country into the database
		    int res1 = sscanf(input, "%c %s %s", &command, nationName, check);
			// Only "A string" is accepted. Any unnecessary endings will produce an error
		    if (res1 != 2) {
               printf("A should be followed by exactly 1 argument.\n"); 
		    } else { // Input accepted, main function carried out
                int result1 = checkNation(nationName, database); // Check whether this country is already in the database
                // If yes, prints error
                if (result1 != -1) printf("Nation \"%s\" is already in the database.\n", nationName); else {
                   database = addNation(nationName, 0, 0, 0, database); // If no, add nation to the database
                   printf("SUCCESS\n"); 
                }
			   
		    } 
            break;

        case 'M': ; // M nation gold silver bronze : Update medals
		    int res2 = sscanf(input, "%c %s %d %d %d %s", &command, nationName, &gold, &silver, &bronze, check);
		    // Only "A string int int int" is accepted. Any unnecessary endings will produce an error
			if (res2 != 5) {
               printf("M should be followed by exactly 4 arguments.\n"); 
		    } else { // Input accepted, main function carried out
               int result2 = updateMedals(nationName, gold, silver, bronze, database);
               // If no nation found, displays error, else success
               if (result2 == 0) printf("Nation \"%s\" is not in the database.\n", nationName); else printf("SUCCESS\n");
		    } 
            break;

        case 'L': ; // L : Output medal table
			int res3 = sscanf(input, "%c %s", &command, check);
			// Only "L" is accepted. Any unnecessary endings will produce an error
		    if (res3 != 1) {
               printf("L should not be followed by any argument.\n"); 
		    } else { // Input accepted, main function carried out
               outputMedalTable(database);
               printf("SUCCESS\n");
		    } 
            break;
        
		case 'W': ;// W filename : Save table
			int res4 = sscanf(input, "%c %s %s", &command, filenameWrite, check);
			// Only "W string" is accepted. Any unnecessary endings will produce an error
			if (res4 != 2) {
               printf("W should be followed by exactly 1 argument.\n"); 
		    } else { // Input accepted, main function carried out
               int result4 = saveTable(filenameWrite, database);
               // Prints error if file cannot be opened or found, else success
               if (result4 == 0) printf("Cannot open file %s for reading.\n", filenameWrite); else printf("SUCCESS\n");
		    } 
            break;

		case 'O': ; // O filename : Load table
			int res5 = sscanf(input, "%c %s %s", &command, filenameRead, check);
			// Only "O string" is accepted. Any unnecessary endings will produce an error
			if (res5 != 2) {
               printf("O should be followed by exactly 1 argument.\n"); 
		    } else { // Input accepted, main function carried out
                struct nation * temp = loadTable(filenameRead, database);
                // Prints error if file cannot be opened or found, else updating database and success
                if (temp == NULL) printf("Cannot open file %s for reading.\n", filenameRead);
                else {
                   database = temp;
                   printf("SUCCESS\n");
                } 
		    } 
            break;

		case 'Q': ; // Q : Exit program
            int res6 = sscanf(input, "%c %s", &command, check);
			// Only "O string" is accepted. Any unnecessary endings will produce an error
			if (res6 != 1) {
               printf("Q should not be followed by any argument.\n"); 
		    } else {
               // Quitting program, ending the infinite while loop
               exitProgram(database);
               printf("SUCCESS\n");
               notStop = false;
            }
            break;
        
		default: // Other commands display error
            printf("Invalid command %c\n", command);
            break;

        }

	}
	return 0;

}

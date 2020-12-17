

#include "Header.h"

int main()
{
	// Declares
	listType list;			// Declares list as listType
	relationType compare;	// Declares compare as relationType
	string action, name;	// Declares action and name as string
	int length, count;		// Declares length and count as int

	// Initializes
	list.first = NULL;		// Sets list.first = null
	list.last = NULL;		// Sets list.last = null
	compare = LESS_THAN;	// Sets compare as less than
	length = 0;				// Sets length as 0
	count = 0;				// Sets count as 0
	
	// Delcares infile and opens test.in
	ifstream infile;
	infile.open("test.in");

	// Declares outfile and opens test.out
	ofstream outfile;		
	outfile.open("test.out");

	// While loop that grabs info until end of file
	while(!infile.eof())
	{
		// Runs function GetNames
		GetNames(list, action, infile);

		// If Insert, puts name into test.out
		if(action == "Insert")
		{
			// Runs function InsertName
			InsertName(list, count, length, outfile);
		}

		// If Delete, removes name from test.out
		if(action == "Delete")
		{
			// Runs function DeleteName
			DeleteName(list, count, length, compare, outfile);
		}

	}

	// Closes both infile and outfile
	infile.close();
	outfile.close();

	return 0;
} // End of main
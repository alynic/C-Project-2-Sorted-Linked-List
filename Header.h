

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// Declare prototype
enum relationType{LESS_THAN, EQUAL, GREATER_THAN};

// Declare listType as a class
class listType
{
public:
	
	string info, item;	// Declare info and item as strings
	listType *current, *first, *last, *link, *temp;	// Declare pointers current, first, last, link, and temp as listType
};

// Function that gets the names from test.in
void GetNames(listType& list, string& action, ifstream& infile);
// Function that runs if "Insert" and inserts name grabbed from test.in and puts in alphebetical order
void InsertName(listType& list, int& count, int& length, ofstream& outfile);
// Function that runs if "Delete" and deletes names from test.in keeping alphabetical order
void DeleteName(listType& list, int& count, int& length, relationType compare, ofstream& outfile);
// Function that outputs the names to test.out
void OutputNames(listType& list, int& count, int& length, relationType compare, ofstream& outfile);
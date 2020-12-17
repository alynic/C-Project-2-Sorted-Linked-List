#include "Header.h"

void GetNames(listType& list, string& action, ifstream& infile)
{	
	infile >> action >> list.item;
}

void InsertName(listType& list, int& count, int& length, ofstream& outfile)
{
	listType* prevLoc;
	listType* location;
	bool moreToSearch;

	prevLoc= NULL;

	location= list.first;
	moreToSearch= (location != NULL);

	while(moreToSearch)
	{
		if(location->info < list.item)
		{
			prevLoc= location;
			location= location->link;
			moreToSearch= (location != NULL);
		}
		
		else
			moreToSearch= false;
	}

	list.current= new listType;
	list.current->info= list.item;
	list.current->link= NULL;
	
	if(list.last == NULL)
	{
		list.first= list.current;
		list.last= list.current;
	}

	else if(prevLoc == NULL)
	{
		list.temp= list.first;
		list.current->link= list.first;
		list.first= list.current;
		
		if(length <= 2)
		{
		list.first->link= list.last;
		}

		else
		{
			list.first->link= list.temp;
		}
	}

	else
	{
		list.current->link= location;
		prevLoc->link= list.current;
	}
	length++;
	count++;

	outfile << "-- " << count << " --" << endl;
	outfile << "Insert: " << list.current->info << endl;
	outfile << "List: ";

	list.current= list.first;
	for(int i = 1; i <= length; i++)
	{
		outfile << list.current->info << " -> ";
		list.current= list.current->link;
	}

	outfile << endl;
	outfile << "Pointers: ";

	list.current= list.first;
	for(int i = 1; i <= length; i++)
	{
		outfile << list.current->link << " -> ";
		list.current= list.current->link;
	}
	outfile << endl << endl;
}

void DeleteName(listType& list, int& count, int& length, relationType compare, ofstream& outfile)
{
	listType* location;
	listType* tempLocation;

	location= list.first;

	if(list.item > location->info)
		compare= GREATER_THAN;

	else if(list.item == location-> info)
		compare= EQUAL;

	else
		compare= LESS_THAN;

	if(compare == EQUAL)
	{
		if(location == list.first)
		{
			tempLocation= location;
			list.first= location->link;
		}

		else
		{
		tempLocation= location;
		location= location->link;
		}
	}

	else
	{
		while(compare != EQUAL)
		{
			if(location == NULL)
			{
				count++;
				outfile << "-- " << count << " --" << endl;
				outfile << "Delete: " << list.item << endl;
				outfile << "List: ";
				location= list.first;
				for(int i = 1; i <= length; i++)
				{
					outfile << location->info << " -> ";
					location= location->link;
				}

				outfile << endl;
				outfile << "Pointers: ";

				location= list.first;
				for(int i = 1; i <= length; i++)
				{
					outfile << location->link << " -> ";
					location= location->link;
				}
				outfile << endl;
				outfile << list.item << " not found in list" << endl << endl;
				return;
			}
			location= location->link;
		}

		if(location == list.first)
		{
			tempLocation= location;
			list.first= location->link;
		}

		else
		{
		tempLocation= location;
		location= location->link;
		}
	}

	delete tempLocation;
	length--;
	count++;

	outfile << "-- " << count << " --" << endl;
	outfile << "Delete: " << list.item << endl;
	outfile << "List: ";

	location= list.first;
	for(int i = 1; i <= length; i++)
	{
		outfile << location->info << " -> ";
		location= location->link;
	}

	outfile << endl;
	outfile << "Pointers: ";

	location= list.first;
	for(int i = 1; i <= length; i++)
	{
		outfile << location->link << " -> ";
		location= location->link;
	}
	outfile << endl << endl;
}
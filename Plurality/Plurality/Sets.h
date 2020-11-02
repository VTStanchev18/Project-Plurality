#pragma once

//Include and Using ----------<|
#include <iostream>
#include <vector>
#include <string>
#include "windows.h"
#include "conio.h"
#include "time.h"

using namespace std;

//Set Structure --------------<|
struct SET
{
	string origin; //How was the set created
	char name; //The name of the set
	vector<int> values; //The values that belong to the set
};

//Functions ------------------<| 
void err(int errorCode, char punctuation = '.', int speed = 1, bool wait = false, bool clearScreen = true)
{
	//How to use
	/*
	=> errorCode -> code for the current error
	=> punctuation -> char for error punctuation
	=> speed -> changes the speed of the punctuation
	=> wait -> if true, then the function will go through a _getch()
	=> clearScreen -> if true, then the function will clear the screen at the begining
	*/

	//Error Code
	/*
	1. No available space for a new set
	2. No available sets
	3. Not enough sets
	4. Invalid input
	5. Input was not an integer. Enter an integer.
	6. Set size cannot be smaller than 0
	7. Number is out of range
	*/
	if (clearScreen)
		system("CLS");


	cout << "\nError" << punctuation;

	int sleepTime = 125 / speed;
	for (int i = 0; i < 3; i++)
	{
		Sleep(sleepTime);
		cout << '.';
	}
	cout << "\t";

	switch (errorCode)
	{
	case 1:
		cout << "There is no available space for a new set.";
		break;
	case 2:
		cout << "There are no available sets";
		break;
	case 3:
		cout << "There are not enough sets";
		break;
	case 4:
		cout << "Invalid input. Enter a valid input";
		break;
	case 5:
		cout << "Input was not an integer. Enter an integer";
		break;
	case 6:
		cout << "Set size cannot be smaller than 0. Enter a bigger number";
		break;
	case 7:
		cout << "Number is out of range";
		break;
	default:
		break;
	}

	cout << punctuation;

	for (int i = 0; i < 3; i++)
	{
		Sleep(sleepTime);
		cout << '.';
	}


	if (wait)
		_getch();
}

//Think of a shorter name... pls... baka
bool checkIfThereIsAvailableSpaceForASet(int setCount)
{
	if (setCount <= 25)
		return true;
	else
		err(1);

	_getch();
	return false;
}

//Think of a shorter name... pls... baka
bool checkIfThereAreAvailableSets(int setCount)
{
	if (setCount > 0)
		return true;
	else
		err(2);

	_getch();
	return false;
}

//Think of a shorter name... pls... baka
bool checkIfThereAreEnoughSets(int setCount)
{
	if (setCount >= 1)
		return true;
	else
		err(2);

	_getch();
	return false;
}

void putinInt(int& num) //Function to input and check an integer
{
	cin >> num;
	while (!cin)
	{
		err(5);
		cin.clear();
		cin.ignore();
		cin >> num;
	}
}

void sortSet(SET& set) //Function to sort a set in ascending order
{
	int i, j;
	bool swapped;
	for (i = 0; i < set.values.size(); i++)
	{
		swapped = false;
		for (j = 0; j < set.values.size() - 1; j++)
		{
			if (set.values[j] > set.values[j + 1])
			{
				int temp = set.values[j];
				set.values[j] = set.values[j + 1];
				set.values[j + 1] = temp;
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

void createSet(SET& set, int& setCount)
{
	system("CLS");

	if (!checkIfThereIsAvailableSpaceForASet(setCount))
		return;

	int len;
	cout << "Input set lenght.(-1 to exit)\n";
	putinInt(len);
	if (len == -1)
		return;
	if (len <= 0)
	{
		err(6);
		putinInt(len);
	}
	cout << "\nInput numbers into the set.\n";

	for (int i = 0; i < len; i++)
	{
		int a = 0;
		putinInt(a);
		set.values.push_back(a);
	}

	set.origin = "User Made Set";

	set.name = char(setCount + 65);
	setCount++;

	sortSet(set);
	return;
}

bool printSets(SET* sets, int setCount, int index = -1, bool wait = true, bool clearScreen = true) //Function to print sets
{
	//How to use
	/*
	=>* sets -> array of structure SET
	=> setCount -> current size of sets array
	=> index -> if index == -1 all sets will be printed otherwise only the set pointed by the index will be printed
	=> wait -> if true, then the function will go through a _getch()
	=> clearScreen -> if true, then the function will clear the screen at the begining
	*/
	if (!checkIfThereAreAvailableSets(setCount))
		return false;

	if (clearScreen)
		system("CLS");

	size_t longestVector = 0;
	int j = 0;
	int max = setCount;
	if (index != -1)
	{
		j = index;
		max = index + 1;
	}

	for (int i = 0; i < max; i++) //I think this works?
	{
		if (sets[i].values.size() > longestVector)
		{
			longestVector = sets[i].values.size();
		}
	}

	for (j; j < max; j++)
	{
		string test = "";
		cout << j;
		if (j < 10)
		{
			cout << ' ';
		}
		cout << " -  " << sets[j].name << "(" << sets[j].values.size() << ")";
		if (sets[j].values.size() < 10)
		{
			cout << ' ';
		}
		cout << " ->  ";
		for (int i = 0; i < sets[j].values.size(); i++)
		{
			cout << sets[j].values[i] << " ";
			test += to_string(sets[j].values[i]) + ' ';
		}
		for (int i = 4 * longestVector - test.length(); i > 0; i--)
		{
			cout << ' ';
		}
		cout << "-=> " << sets[j].origin << "\n";
	}

	if (wait)
		_getch();

	return true;
}

int getRemoveIndex(SET* sets, int setCount) //Function to get and check the index before the remove function
{
	system("CLS");
	printSets(sets, setCount, -1, false);

	int index;
	cout << "Choose the set to delete (number!)(-1 to exit): "; //TODO!!! MAKE IT POSSIBLE TO DELETE A SET BY CHOOSING A NAME
	putinInt(index);
	if (index == -1)
		return index;
	if (index >= setCount or index < 0)
	{
		err(7);
		index = getRemoveIndex(sets, setCount);
	}

	return index;
}

void renameSets(SET* sets, int& setCount)
{
	for (int i = 0; i < setCount; i++)
	{
		sets[i].name = char(i + 65);
	}
}

void removeSet(SET* sets, int& setCount) //Function to remove a set
{
	if (!checkIfThereAreAvailableSets(setCount))
		return;

	int index = getRemoveIndex(sets, setCount);
	if (index == -1)
		return;

	printSets(sets, setCount, index, false);
	cout << "\n\nThis set WILL be DELETED FOREVER!\n";
	_getch();

	for (int i = index; i < setCount - 1; i++)
	{
		sets[i] = sets[i + 1];
	}
	setCount--;

	renameSets(sets, setCount);
}

bool dummySet(SET& set, int& setCount) //Function to create sets at random -> dummy sets
{
	if (!checkIfThereIsAvailableSpaceForASet(setCount))
		return false;

	int len = rand() % 10 + 1;

	for (int i = 0; i < len; i++)
	{
		int a = rand() % 60 - 29;
		set.values.push_back(a);
		Sleep(10);
	}

	set.name = char(setCount + 65);
	set.origin = "Dummy Set";
	setCount++;

	sortSet(set);

	return true;
}

int getIndex(int setCount) //Function to get and check the index before the set function
{
	int index;
	putinInt(index);
	if (index == -1)
		return index;
	if (index >= setCount or index < 0)
	{
		err(7);
		index = getIndex(setCount);
	}

	return index;
}

bool unionOfSets(SET A, SET B, SET& C, int& setCount) //Function that returns a union of Set A and Set B
{
	if (checkIfThereIsAvailableSpaceForASet(setCount))
		return false;

	if (checkIfThereAreEnoughSets(setCount))
		return false;

	string origin = "Union of ";
	origin += A.name;
	origin += " and ";
	origin += B.name;
	C.origin = origin;

	C.name = char(setCount + 65);
	setCount++;

	int index = 0;
	C.values.resize(A.values.size() + B.values.size());
	for (int i = 0; i < A.values.size(); i++)
	{
		C.values[index] = A.values[i];
		index++;
	}

	for (int i = 0; i < B.values.size(); i++)
	{
		C.values[index] = B.values[i];
		index++;
	}

	sortSet(C);

	return true;
}

bool intersectionOfSets(SET A, SET B, SET& C, int& setCount, bool temporary = false) //Function that returns an intersection of Set A and Set B
{
	if (!temporary)
	{
		if (checkIfThereIsAvailableSpaceForASet(setCount))
			return false;

		if (checkIfThereAreEnoughSets(setCount))
			return false;

		string origin = "Intersection of ";
		origin += A.name;
		origin += " and ";
		origin += B.name;
		C.origin = origin;

		C.name = char(setCount + 65);
		setCount++;
	}

	for (int i = 0; i < A.values.size(); i++)
	{
		for (int j = 0; j < B.values.size(); j++)
		{
			if (B.values[j] != 299792458 and A.values[i] == B.values[j])
			{
				C.values.push_back(A.values[i]);
				B.values[j] = 299792458;
				break;
			}
		}
	}

	sortSet(C);

	return true;
}

bool complementOfSets(SET A, SET B, SET& C, int& setCount) //Function that returns the complement of Set A in Set B
{
	if (checkIfThereIsAvailableSpaceForASet(setCount))
		return false;

	if (checkIfThereAreEnoughSets(setCount))
		return false;

	string origin = "Complement of ";
	origin += A.name;
	origin += " in ";
	origin += B.name;
	C.origin = origin;

	C.name = char(setCount + 65);
	setCount++;

	SET _C;
	intersectionOfSets(A, B, _C, setCount, true);

	for (int i = 0; i < A.values.size(); i++)
	{
		for (int j = 0; j < _C.values.size(); j++)
		{
			if (A.values[i] == _C.values[j])
			{
				A.values[i] = 299792458;
				break;
			}
		}
	}

	for (int i = 0; i < A.values.size(); i++)
	{
		if (A.values[i] != 299792458)
		{
			C.values.push_back(A.values[i]);
		}
	}

	sortSet(C);

	return true;
}
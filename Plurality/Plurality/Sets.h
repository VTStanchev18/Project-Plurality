#pragma once


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct SET
{
	vector<int> values;
};

void putinInt(int& num)
{
	cin >> num;
	while (!cin)
	{
		cout << "That was no integer! Please enter an integer: ";
		cin.clear();
		cin.ignore();
		cin >> num;
	}
}

void sortSet(vector<int>& set)
{
	int i, j;
	bool swapped;
	for (i = 0; i < set.size(); i++)
	{
		swapped = false;
		for (j = 0; j < set.size() - 1; j++)
		{
			if (set[j] > set[j + 1])
			{
				int temp = set[j];
				set[j] = set[j + 1];
				set[j + 1] = temp;
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

void createSet(vector<int> &set)
{
	system("CLS");

	int len;
	cout << "Input set lenght.\n";
	putinInt(len);
	if (len <= 0)
	{
		cout << "Size cannot be smaller than 0";
		putinInt(len);
	}
	cout << "\nInput numbers into the set.\n";

	for (int i = 0; i < len; i++)
	{
		int a = 0;
		putinInt(a);
		set.push_back(a);
	}

	sortSet(set);
}

void printSets(SET sets[], int setCount, int index = -1, bool wait = true)
{
	system("CLS");
	
	int j = 0;
	int max = setCount;
	if (index != -1)
	{
		j = index;
		max = index + 1;
	}

	for (j; j < max; j++)
	{
		cout << j << " - " << char(j + 65) << "(" << sets[j].values.size() << ")"  << " -> ";
		for (int i = 0; i < sets[j].values.size(); i++)
		{
			cout << sets[j].values[i] << " ";
		}
		cout << "\n";
	}

	if(wait)
		_getch();
}

int getRemoveIndex(SET sets[], int setCount)
{
	system("CLS");
	printSets(sets, setCount, -1, false);

	int index;
	cout << "Choose the set to delete (number!): "; //TODO!!! MAKE IT POSSIBLE TO DELETE A SET BY CHOOSING A NAME
	putinInt(index);
	if (index >= setCount or index < 0)
	{
		cout << "Error...\n";
		index = getRemoveIndex(sets, setCount);
	}

	return index;
}

void removeSet(SET sets[], int& setCount) //TODO!!! ADD THE SET NAME INTO THE SET STRUCTURE =>	
{
	int index = getRemoveIndex(sets, setCount);
	
	printSets(sets, setCount, index, false);
	cout << "\n\nThis set WILL be DELETED FOREVER!\n";
	_getch();

	for (int i = index; i < setCount - 1; i++)
	{
		sets[i] = sets[i + 1];
	}
	setCount--;
}

void dummySet(vector<int>& set)
{
	int len = rand() % 10 + 1;

	for (int i = 0; i < len; i++)
	{
		int a = rand()%60-29;
		set.push_back(a);
	}

	sortSet(set);
}
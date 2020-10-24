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

}

void printSets(SET sets[], int setCount)
{
	system("CLS");
	for (int j = 0; j < setCount; j++)
	{
		cout << char(j + 65) << "(" << sets[j].values.size() << ")"  << " -> ";
		for (int i = 0; i < sets[j].values.size(); i++)
		{
			cout << sets[j].values[i] << " ";
		}
		cout << "\n";
	}
	_getch();
}
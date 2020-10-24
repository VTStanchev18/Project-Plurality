#pragma once


#include <iostream>
#include <vector>

using namespace std;

struct SET
{

	vector<int> values;
};

void createSet(vector<int> &set)
{
	system("CLS");
	cout << "Input set lenght.\n";
	int len;
	cin >> len;
	cout << "\nInput numbers into the set.\n";

	for(int i=0;i<len;i++)
	{
		int a;
		cin >> a;
		set.push_back(a);
	}
}

void printSets(SET sets[], int setCount)
{
	system("CLS");
	for (int j = 0; j < setCount; j++)
	{
		cout << char(j + 65) << "(" << sets[j].values.size() << ")" << " -> ";
		for (int i = 0; i < sets[j].values.size(); i++)
		{
			cout << sets[j].values[i] << " ";
		}
		cout << "\n";
	}
	_getch();
}
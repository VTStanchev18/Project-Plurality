//Include and Using -----------<|
#include <iostream>
#include "conio.h"
#include <vector>
#include "time.h" 

#include "Sets.h"

using namespace std;

void mainMenu(SET sets[], int setCount);

//Main ------------------------<|
int main()
{
	srand(time(NULL));

	SET sets[30];
	int setCount = 0;
	
	mainMenu(sets, setCount);
}

//Main Functions --------------<|
//Main Meny Function ----------<|
void mainMenu(SET sets[], int setCount)
{
	bool inApp = true, devMode = false;
	int amount = 0, mem = 0;
	int firstId = 0, secondId = 1;
	string lastInput = "";
	string code = "wwssadadba";
	while (inApp)
	{
		system("CLS");
		cout << "---- M E N U ----\n";
		cout << setCount << "\\" << 26 << "\n";
		cout << "1. Create a set\n2. Print all sets\n3. Edit a set\n4. Delete a set\n5. Union of two sets\n6. Section of two sets\n7. Difference of two sets\n";
		if(devMode)
			cout << "0. Add dummy sets\n"; //Dev only
		//Prints options:
		//	Esc. Go back -> quit
		//	1. Create a new set
		//	2. Prints all or one set
		//	3. Edit a set -> change values or sort the set
		//	4. Delete a set
		//	5. Union of two sets
		//	6. Section of two sets
		//	7. Difference of two sets
		//	8. OPTIONAL: Save function
		//	9. OPTIONAL: Load function
		//	0. Adds dummy sets

		char sym = _getch();
		switch (sym)
		{
		case 27: //Escape
			lastInput = "";
			inApp = false;
			break;
		case '1': //1. Create a new set
			lastInput = "";
			if (setCount <= 26)
			{
				createSet(sets[setCount]);
				sets[setCount].name = char(setCount + 65);
				setCount++;
			}
			else
			{
				cout << "No more available space for a new set\n";
			}
			break;
		case '2': //2. Prints all or one set
			lastInput = "";
			if (setCount > 0)
			{
				printSets(sets, setCount);
			}
			else
			{
				cout << "\nError... \nNo available sets...";
				_getch();
			}
			break;
		case '3': //3. Edit a set -> change values or sort the set
			lastInput = "";

			break;
		case '4': //4. Delete a set
			lastInput = "";
			removeSet(sets, setCount);
			break;
		case '5': //5. Union of two sets
		case '6': //6. Section two sets
		case '7': //7. Difference of two sets
			lastInput = "";

			//TODO!!! Seperate from here -----------------------
			printSets(sets, setCount, -1, false);

			cout << "\nWhat sets would you like to use?\nFirst set: ";
			firstId = 0;
			secondId = 1;
			putinInt(firstId);
			//TODO!!! Make a num check fun -> num<=setCount && num>=0
			cout << "\nSecond set: ";
			putinInt(secondId);
			//TODO!!! Make a num check fun -> num<=setCount && num>=0




			//To here as a function! -----------------------

			switch (sym)
			{
			case '5':
				sets[setCount] = unionSets(sets[firstId], sets[secondId]);
				sets[setCount].name = char(setCount + 65);
				setCount++;
				break;
			case '6':

				break;
			case '7':

				break;
			default:
				break;
			}

			printSets(sets, setCount, setCount);
			cout << "\nUnion of " << sets[firstId].name << " and " << sets[secondId].name << " created.\n";

			break;
		case '0': //LOADS DUMMY SETS
			if (devMode)
			{
				amount = rand() % 8 + 4 + setCount;
				mem = setCount;
				if (amount <= 26)
				{
					for (int i = setCount; i < amount; i++)
					{
						dummySet(sets[setCount].values);
						sets[setCount].origin = "DUMMY SET";
						sets[setCount].name = char(setCount + 65);
						setCount++;
					}
					cout << "\n" << amount - mem << " DUMMY SETS ADDED...\n";
					_getch();
				}
				else
				{
					cout << "No more available space for new sets\n";
				}
			}
			lastInput = "";
			break;
		case 'w':
		case 's':
		case 'a':
		case 'd':
		case 'b':
			lastInput += sym;
			break;
		default: //TODO!!! Add an error case = default case
			lastInput = "";
			break;
		}

		if(lastInput==code)
		{
			devMode = !devMode;
			cout << "\n\nDEV MODE ";
			if (devMode)
				cout << "ACTIVATED!";
			else
				cout << "DEACTIVATED!";
			lastInput = "";
			_getch();
		}
	
	}
}

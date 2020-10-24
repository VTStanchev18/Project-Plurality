//Include and Using -----------<|
#include <iostream>
#include "conio.h"
#include <vector>

#include "Sets.h"

using namespace std;

void mainMenu(SET sets[], int setCount);

//Main ------------------------<|
int main()
{
	SET sets[30];
	int setCount = 0;
	mainMenu(sets, setCount);
}

//Main Functions --------------<|
void mainMenu(SET sets[], int setCount)
{
	bool inApp = true;
	while (inApp)
	{
		system("CLS");
		cout << "---- M E N U ----\n";
		cout << "1. Create a set\n2. Print all sets\n3. Edit a set\n4. Delete a set\n5. Merge two sets\n6. Section of two sets\n7. Difference of two sets\n";
		//Prints options:
		//	Esc. Go back -> quit
		//	1. Create a new set
		//	2. Prints all or one set
		//	3. Edit a set -> change values or sort the set
		//	4. Delete a set
		//	5. Merge two sets
		//	6. Section of two sets
		//	7. Difference of two sets
		//	8. OPTIONAL: Save function
		//	9. OPTIONAL: Load function

		switch (_getch())
		{
		case 27: //Escape
			inApp = false;
			break;
		case '1': //1. Create a new set
			if (setCount <= 26)
			{
				createSet(sets[setCount].values);
				setCount++;
			}
			else
			{
				cout << "No more available space for a new set\n";
			}
			break;
		case '2': //2. Prints all or one set
			if (setCount > 0)
			{
				printSets(sets, setCount);
			}
			else
			{
				cout << "\nError... \nNo available sets...";
			}
			break;
		case '3': //3. Edit a set -> change values or sort the set

			break;
		case '4': //4. Delete a set

			break;
		case '5': //5. Merge two sets

			break;
		case '6': //6. Section two sets

			break;
		default:

			break;
		}


	
	}
}

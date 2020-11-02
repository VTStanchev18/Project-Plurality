//Include and Using -----------<|
#include <iostream>
#include "conio.h"
#include <vector>
#include "time.h"
#include "windows.h"

#include "Sets.h"

using namespace std;

//Functions -------------------<|
void quote(string quote, int multiplier = 1);

void mainMenu(SET sets[], int setCount);

//Main ------------------------<|
int main()
{
	srand(time(NULL));
		
	struct SET sets[30];
	int setCount = 0;
	
	mainMenu(sets, setCount);
}

//Functions -------------------<|
void mainMenu(SET sets[], int setCount) //Main menu

{
	bool inApp = true, devMode = true; //IMPORTANT!!! Turn devMode to false in release version
	int amount = 0, mem = 0;
	int firstId = 0, secondId = 1;

	string lastInput = "";
	string quotesEgg1[] = {"They are rage, brutal, without mercy. But you. You will be worse. Rip and tear, until it is done...","Against all the evil that Hell can conjure, all the wickedness that mankind can produce, we will send unto them... only you. Rip and tear, until it is done..." };
	
	string operation = "";
	while (inApp)
	{
		system("CLS");
		cout << "---- M E N U ----\n";
		cout << setCount << "\\" << 26 << "\n";
		cout << "1. Create a set\n2. Print all sets\n3. Delete a set\n4. Union of two sets\n5. Intersection of two sets\n6. Complement of two sets\n";
		if(devMode)
			cout << "0. Add dummy sets\n"; //Dev only
		//Prints options:
		//	Esc. Go back -> quit
		//	1. Create a new set
		//	2. Prints all or one set
		//	3. Delete a set
		//	4. Union of two sets
		//	5. Intersection of two sets
		//	6. Complement of two sets
		//	7. OPTIONAL: Save function
		//	8. OPTIONAL: Load function
		//	9. OPTIONAL: Settings
		//	0. Adds dummy sets
		//	-. OPTIONAL: Credits
		//	=. OPTIONAL: Explanation

		cout << "\n" << lastInput;
		operation = "";
		char sym = _getch();

		switch (sym)
		{
		case 27: //Escape
			lastInput = "";
			inApp = false;
			break;
		case '1': //1. Create a new set
			lastInput = "";
			if (setCount <= 25)
			{
				if (createSet(sets[setCount]))
				{
					sets[setCount].name = char(setCount + 65);
					setCount++;
				}
			}
			else
				err(1);
			break;
		case '2': //2. Prints all or one set
			lastInput = "";
			if (setCount > 0)
				printSets(sets, setCount);
			else
				err(2);
			break;
		case '3': //4. Delete a set
			lastInput = "";
			if(setCount > 0)
				removeSet(sets, setCount);
			else
				err(2);
			break;
		case '4': //5. Union of two sets
			operation = "Union of two sets";
			goto start;
		case '5': //6. Intersection of two sets
			operation = "Intersection of two sets";
			goto start;
		case '6': //7. Complement of one set in another
			operation = "Complement of one set in another";
			start:
			
			lastInput = "";

			if (setCount < 1)
			{
				err(3);
				break;
			}
			if (setCount > 25)
			{
				err(1);
				break;
			}

			printSets(sets, setCount, -1, false);

			cout << "\n---</ " << operation << "\\>---";

			firstId = 0;
			secondId = 1;
			cout << "\nWhat sets would you like to use?(-1 to exit)\nFirst set: ";
			firstId = getIndex(setCount);
			if (firstId == -1)
				break;
			cout << "Second set: ";
			secondId = getIndex(setCount);
			if (secondId == -1)
				break;

			switch (sym)
			{
			case '4':
				sets[setCount] = unionOfSets(sets[firstId], sets[secondId]);
				sets[setCount].name = char(setCount + 65);
				break;
			case '5':
				sets[setCount] = intersectionOfSets(sets[firstId], sets[secondId]);
				sets[setCount].name = char(setCount + 65);
				break;
			case '6':
				sets[setCount] = complementOfSets(sets[firstId], sets[secondId]);
				sets[setCount].name = char(setCount + 65);
				break;
			default:
				break;
			}

			sortSet(sets[setCount]);
			
			system("CLS");
			cout << sets[setCount].origin << " created.\n";
			printSets(sets, setCount + 1, setCount, false, false);
			setCount++;

			_getch();
			break;
		case '0': //LOADS DUMMY SETS
			if (devMode)
			{
				amount = rand() % 8 + 4 + setCount;
				mem = setCount;
				if (amount <= 25)
				{
					for (int i = setCount; i < amount; i++)
					{
						dummySet(sets[setCount]);
						sets[setCount].origin = "Dummy Set";
						sets[setCount].name = char(setCount + 65);
						setCount++;
					}
					cout << "\n" << amount - mem << " Dummy Set(s) added...\n";
					_getch();
				}
				else
					err(1);
			}
			lastInput = "";
			break;
		case 'w':
		case 's':
		case 'a':
		case 'd':
		case 'b':
		case 'i':
		case 'k':
		case 'f':
			lastInput += sym;
			break;
		default:
			lastInput = "";
			err(4);
			break;
		}

		if(lastInput == "wwssadadba")
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

		if (lastInput == "idkfa")
		{
			system("CLS");
			
			int random = rand() % 3 - 1;
			switch (random)
			{
			case -1:
				/*
				=================     ===============     ===============   ========  ========
				\\ . . . . . . .\\   //. . . . . . .\\   //. . . . . . .\\  \\. . .\\// . . //
				||. . ._____. . .|| ||. . ._____. . .|| ||. . ._____. . .|| || . . .\/ . . .||
				|| . .||   ||. . || || . .||   ||. . || || . .||   ||. . || ||. . . . . . . ||
				||. . ||   || . .|| ||. . ||   || . .|| ||. . ||   || . .|| || . | . . . . .||
				|| . .||   ||. _-|| ||-_ .||   ||. . || || . .||   ||. _-|| ||-_.|\ . . . . ||
				||. . ||   ||-'  || ||  `-||   || . .|| ||. . ||   ||-'  || ||  `|\_ . .|. .||
				|| . _||   ||    || ||    ||   ||_ . || || . _||   ||    || ||   |\ `-_/| . ||
				||_-' ||  .|/    || ||    \|.  || `-_|| ||_-' ||  .|/    || ||   | \  / |-_.||
				||    ||_-'      || ||      `-_||    || ||    ||_-'      || ||   | \  / |  `||
				||    `'         || ||         `'    || ||    `'         || ||   | \  / |   ||
				||            .===' `===.         .==='.`===.         .===' /==. |  \/  |   ||
				||         .=='   \_|-_ `===. .==='   _|_   `===. .===' _-|/   `==  \/  |   ||
				||      .=='    _-'    `-_  `='    _-'   `-_    `='  _-'   `-_  /|  \/  |   ||
				||   .=='    _-'          `-__\._-'         `-_./__-'         `' |. /|  |   ||
				||.=='    _-'                                                     `' |  /==.||
				=='    _-'                                                            \/   `==
				\   _-'                                                                `-_   /
				*/
				cout << "\n" << "=================     ===============     ===============   ========  ========";
				cout << "\n" << "\\\\ . . . . . . .\\\\   //. . . . . . .\\\\   //. . . . . . .\\\\  \\\\. . .\\\\// . . //";
				cout << "\n" << "||. . ._____. . .|| ||. . ._____. . .|| ||. . ._____. . .|| || . . .\\/ . . .||";
				cout << "\n" << "|| . .||   ||. . || || . .||   ||. . || || . .||   ||. . || ||. . . . . . . ||";
				cout << "\n" << "||. . ||   || . .|| ||. . ||   || . .|| ||. . ||   || . .|| || . | . . . . .||";
				cout << "\n" << "|| . .||   ||. _-|| ||-_ .||   ||. . || || . .||   ||. _-|| ||-_.|\\ . . . . ||";
				cout << "\n" << "||. . ||   ||-'  || ||  `-||   || . .|| ||. . ||   ||-'  || ||  `|\\_ . .|. .||";
				cout << "\n" << "|| . _||   ||    || ||    ||   ||_ . || || . _||   ||    || ||   |\\ `-_/| . ||";
				cout << "\n" << "||_-' ||  .|/    || ||    \\|.  || `-_|| ||_-' ||  .|/    || ||   | \\  / |-_.||";
				cout << "\n" << "||    ||_-'      || ||      `-_||    || ||    ||_-'      || ||   | \\  / |  `||";
				cout << "\n" << "||    `'         || ||         `'    || ||    `'         || ||   | \\  / |   ||";
				cout << "\n" << "||            .===' `===.         .==='.`===.         .===' /==. |  \\/  |   ||";
				cout << "\n" << "||         .=='   \\_|-_ `===. .==='   _|_   `===. .===' _-|/   `==  \\/  |   ||";
				cout << "\n" << "||      .=='    _-'    `-_  `='    _-'   `-_    `='  _-'   `-_  /|  \\/  |   ||";
				cout << "\n" << "||   .=='    _-'          `-__\\._-'         `-_./__-'         `' |. /|  |   ||";
				cout << "\n" << "||.=='    _-'                                                     `' |  /==.||";
				cout << "\n" << "=='    _-'                                                            \\/   `==";
				cout << "\n" << "\\   _-'                                                                `-_   /";

				PlaySound(TEXT("ExtraFiles\\E1M1Doom.wav"), NULL, SND_ASYNC);
				Sleep(10000);
				break;
			case 0:
				PlaySound(TEXT("ExtraFiles\\Doom'sGate2016.wav"), NULL, SND_ASYNC);
				Sleep(8000);	
				quote(quotesEgg1[random], 3);
				Sleep(1000);	
				break;
			case 1:
				PlaySound(TEXT("ExtraFiles\\Doom'sGateEternal.wav"), NULL, SND_ASYNC);
				Sleep(8000);	
				quote(quotesEgg1[random], 5);
				Sleep(1000);
				break;
			default:
				break;
			}

			lastInput = "";
			_getch();
			_getch();
			_getch();
			PlaySound(NULL, NULL, SND_ASYNC);
		}
	
	}
}

void quote(string quote, int multiplier)
{
	for (int i = 0; i < quote.length(); i++)
	{
		cout << quote[i];
		switch (quote[i])
		{
		case ' ':
			Sleep(100 * multiplier);
			break;
		case '.':
		case ',':
		case ';':
		case ':':
		case '?':
		case '!':
			Sleep(200 * multiplier);
			break;
		default:
			Sleep(50 * multiplier);
			break;
		}
	}
}
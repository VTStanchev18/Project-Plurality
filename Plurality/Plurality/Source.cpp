//Include and Using -----------<|
#include <iostream>
#include <vector>
#include <string>
#include "conio.h"
#include "time.h"
#include "windows.h"

#include "Sets.h"

using namespace std;

//Functions -------------------<|
void quote(string quote, int multiplier = 1);

void mainMenu(SET* sets, int setCount);

//Main ------------------------<|
int main()
{
	srand(time(NULL));

	struct SET sets[30];
	int setCount = 0;

	mainMenu(sets, setCount);
}

//Functions -------------------<|
void mainMenu(SET* sets, int setCount) //Main menu
{
	bool inApp = true, operationState = false, devMode = false; //IMPORTANT!!! Turn devMode to false in release version
	int amount = 0, mem = 0;
	int firstId = 0, secondId = 1;

	string tempStr = "";
	string lastInput = "";
	
	string quotesEgg1[] = { "They are rage, #brutal, #without mercy.\nBut you...\n##You will be worse.\n#Rip #and #tear, ##until it is done...","Against all the evil that Hell can conjure,\n#all the wickedness that mankind can produce,\n##we will send unto them...\n#only #you.\n##Rip #and #tear, ##until it is done..." };
	string DOOM = "=================     ===============     ===============   ========  ========\n\\\\ . . . . . . .\\\\   //. . . . . . .\\\\   //. . . . . . .\\\\  \\\\. . .\\\\// . . //\n||. . ._____. . .|| ||. . ._____. . .|| ||. . ._____. . .|| || . . .\\/ . . .||\n|| . .||   ||. . || || . .||   ||. . || || . .||   ||. . || ||. . . . . . . ||\n||. . ||   || . .|| ||. . ||   || . .|| ||. . ||   || . .|| || . | . . . . .||\n|| . .||   ||. _-|| ||-_ .||   ||. . || || . .||   ||. _-|| ||_.|\\ . . . . ||\n||. . ||   ||-'  || ||  `-||   || . .|| ||. . ||   ||-'  || ||  `|\\_ . .|. .||\n|| . _||   ||    || ||    ||   ||_ . || || . _||   ||    || ||   |\\ `-_/| . ||\n||_-' ||  .|/    || ||    \\|.  || `-_|| ||_-' ||  .|/    || ||   | \\  / |-_.||\n||    ||_-'      || ||      `-_||    || ||    ||_-'      || ||   | \\  / |  `||\n||    `'         || ||         `'    || ||    `'         || ||   | \\  / |   ||\n||            .===' `===.         .==='.`===.         .===' /==. |  \\/  |   ||\n||         .=='   \\_|-_ `===. .==='   _|_   `===. .===' _-|/   `==  \\/  |   ||\n||      .=='    _-'    `-_  `='    _-'   `-_    `='  _-'   `-_  /|  \\/  |   ||\n||   .=='    _-'          `-__\\._-'         `-_./__-'         `' |. /|  |   ||\n||.=='    _-'                                                     `' |  /==.||\n=='    _-'                                                            \\/   `==\n\\   _-'                                                                `-_   /\n";
	string operation = "";

	while (inApp)
	{
		if (devMode)
			cout << "DevMode is ON\n";
		cout << "---- M E N U ----\n";
		cout << setCount << "\\" << 26 << "\n";
		cout << "1. Create a set\n2. Print all sets\n3. Delete a set\n4. Union of two sets\n5. Intersection of two sets\n6. Complement of two sets\n";
		if (devMode)
			cout << "0. Add dummy sets\n"; //Dev only
		cout << "Esc. Quit the program\n";
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

		operation = "";
		char sym = _getch();

		switch (sym)
		{
		case 8: //Backspace -> removes the last char of the cheat code
			tempStr = lastInput;
			lastInput = tempStr.substr(0, tempStr.size() - 1);
			break;
		case 27: //Escape -> quits the program
			lastInput = "";
			inApp = false;
			break;
		case '1': //1. Create a new set
			lastInput = "";
			createSet(sets[setCount], setCount);
			break;
		case '2': //2. Prints all or one set
			lastInput = "";
			printSets(sets, setCount);
			break;
		case '3': //4. Delete a set
			lastInput = "";
			removeSet(sets, setCount);
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
			operationState = false;

			if (!printSets(sets, setCount, -1, false))
				break;

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
				operationState = unionOfSets(sets[firstId], sets[secondId], sets[setCount + 1], setCount);
				break;
			case '5':
				operationState = intersectionOfSets(sets[firstId], sets[secondId], sets[setCount + 1], setCount);
				break;
			case '6':
				operationState = complementOfSets(sets[firstId], sets[secondId], sets[setCount + 1], setCount);
				break;
			default:
				break;
			}

			if (!operationState)
				break;
			
			system("CLS");
			cout << sets[setCount].origin << " created.\n";
			printSets(sets, setCount + 1, setCount, false, false);
			_getch();

			break;
		case '0': //LOADS DUMMY SETS
			lastInput = "";
			if (devMode)
			{
				operationState = false;
				amount = rand() % 8 + 4 + setCount;
				mem = setCount;

				for (int i = mem; i < amount; i++)
				{
					operationState = dummySet(sets[setCount], setCount);
					if (!operationState)
						break;
				}


				cout << "\n" << amount - mem << " Dummy Set(s) added...\n";
				_getch();
			}
			break;
		default:
			lastInput += sym;
			break;
		}



		if (lastInput.length() > 15)
		{
			lastInput = "";
			cout << "\nYou didn't say the magic word..."; //I'm wondering if I should add audio? https://www.youtube.com/watch?v=K3PrSj9XEu4&ab_channel=BJ22CS
			Sleep(600);
		}
		
		system("CLS");

		if(!lastInput.empty())
			cout << lastInput << "\n";

		if (lastInput == "wwssadadba")
		{
			if(!devMode)
				PlaySound(TEXT("ExtraFiles\\Secret.wav"), NULL, SND_ASYNC);
			devMode = !devMode;
			cout << "\n\nDEV MODE ";
			if (devMode)
				cout << "ACTIVATED!";
			else
				cout << "DEACTIVATED!";
			lastInput = "";
			_getch();
			system("CLS");
			PlaySound(NULL, NULL, SND_ASYNC);
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
				PlaySound(TEXT("ExtraFiles\\E1M1Doom.wav"), NULL, SND_ASYNC);
				for (size_t i = 0; i < DOOM.length(); i++)
				{
					cout << DOOM[i];
					if (i % 4 == 0) //If it is too fast change it to 2
					{
						Sleep(50);
					}
				}
				break;
			case 0:
				PlaySound(TEXT("ExtraFiles\\Doom'sGate2016.wav"), NULL, SND_ASYNC);
				Sleep(12000);
				quote(quotesEgg1[random], 2);
				break;
			case 1:
				PlaySound(TEXT("ExtraFiles\\Doom'sGateEternal.wav"), NULL, SND_ASYNC);
				Sleep(16000);
				quote(quotesEgg1[random], 3);
				break;
			default:
				break;
			}

			lastInput = "";

			_getch();

			PlaySound(NULL, NULL, SND_ASYNC);
			system("CLS");
		}
	}
}

void quote(string quote, int multiplier)
{
	for (int i = 0; i < quote.length(); i++)
	{
		if(quote[i] != '#')
			cout << quote[i];

		switch (quote[i])
		{
		case '#':
			Sleep(250 * multiplier);
			break;
		case '\n':
			Sleep(650 * multiplier);
			break;
		case ' ':
			Sleep(100 * multiplier);
			break;
		case ',':
			Sleep(200 * multiplier);
			break;
		case '.':
		case ';':
		case ':':
		case '?':
		case '!':
			Sleep(250 * multiplier);
			break;
		default:
			Sleep(100);
			break;
		}
	}
}
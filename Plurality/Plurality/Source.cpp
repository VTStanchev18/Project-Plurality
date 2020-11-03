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

void pastry();

void soundSetting();

void mainMenu(SET* sets, int setCount);

//Global variables ------------<|
bool soundOn = false;

//Main ------------------------<|
int main()
{
	srand(time(NULL));

	struct SET sets[30];
	int setCount = 0;

	soundSetting();

	_getch();

	mainMenu(sets, setCount);
}

//Functions -------------------<|
void mainMenu(SET* sets, int setCount) //Main menu
{
	system("CLS");

	bool inApp = true, operationState = false, devMode = false; //IMPORTANT!!! Turn devMode to false in release version
	int amount = 0, mem = 0;
	int firstId = 0, secondId = 1;

	string tempStr = "";
	string lastInput = "";
	
	string quotesEgg1[] = { "They are rage, #brutal, #without mercy.\nBut you...\n##You will be worse.\n#Rip #and #tear, ##until it is done.....","Against all the evil that Hell can conjure,\n#all the wickedness that mankind can produce,\n##we will send unto them...\n#only #you.\n##Rip #and #tear, ##until it is done....." };
	string DOOM = "=================     ===============     ===============   ========  ========\n\\\\ . . . . . . .\\\\   //. . . . . . .\\\\   //. . . . . . .\\\\  \\\\. . .\\\\// . . //\n||. . ._____. . .|| ||. . ._____. . .|| ||. . ._____. . .|| || . . .\\/ . . .||\n|| . .||   ||. . || || . .||   ||. . || || . .||   ||. . || ||. . . . . . . ||\n||. . ||   || . .|| ||. . ||   || . .|| ||. . ||   || . .|| || . | . . . . .||\n|| . .||   ||. _-|| ||-_ .||   ||. . || || . .||   ||. _-|| ||_.|\\ . . . . ||\n||. . ||   ||-'  || ||  `-||   || . .|| ||. . ||   ||-'  || ||  `|\\_ . .|. .||\n|| . _||   ||    || ||    ||   ||_ . || || . _||   ||    || ||   |\\ `-_/| . ||\n||_-' ||  .|/    || ||    \\|.  || `-_|| ||_-' ||  .|/    || ||   | \\  / |-_.||\n||    ||_-'      || ||      `-_||    || ||    ||_-'      || ||   | \\  / |  `||\n||    `'         || ||         `'    || ||    `'         || ||   | \\  / |   ||\n||            .===' `===.         .==='.`===.         .===' /==. |  \\/  |   ||\n||         .=='   \\_|-_ `===. .==='   _|_   `===. .===' _-|/   `==  \\/  |   ||\n||      .=='    _-'    `-_  `='    _-'   `-_    `='  _-'   `-_  /|  \\/  |   ||\n||   .=='    _-'          `-__\\._-'         `-_./__-'         `' |. /|  |   ||\n||.=='    _-'                                                     `' |  /==.||\n=='    _-'                                                            \\/   `==\n\\   _-'                                                                `-_   /\n";
	string operation = "";

	while (inApp)
	{
		if (devMode)
			cout << "DevMode is ON\n";
		cout << "---- M E N U ----\n";
		cout << setCount << "\\" << 26 << "\n";
		cout << "1. Create a set\n2. Print all sets\n3. Delete a set\n4. Union of two sets\n5. Intersection of two sets\n6. Complement of two sets\n9. Settings\n";
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
			if(soundOn) 
				Beep(350, 100);
			tempStr = lastInput;
			lastInput = tempStr.substr(0, tempStr.size() - 1);
			break;
		
		case 27: //Escape -> quits the program
			if (soundOn) 
			{
				Beep(200, 200);
				Beep(150, 100);
				Beep(100, 500);
			}
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
				operationState = unionOfSets(sets[firstId], sets[secondId], sets[setCount], setCount);
				break;
			case '5':
				operationState = intersectionOfSets(sets[firstId], sets[secondId], sets[setCount], setCount);
				break;
			case '6':
				operationState = complementOfSets(sets[firstId], sets[secondId], sets[setCount], setCount);
				break;
			default:
				break;
			}

			if (!operationState)
				break;
			
			system("CLS");
			cout << sets[setCount - 1].origin << " created.\n";
			printSets(sets, setCount - 1, setCount - 1, false, false);
			_getch();

			break;
		
		case '9': //Settings
			SettingStart:
			system("CLS");

			cout << "--< Settings >--\n";
			cout << "1. Sound settings\nEsc. Quit the program\nBackspace. Go back\n";

			switch (_getch())
			{
			case 8:
				break;
			case 27:
				inApp = false;
				break;
			case '1':
				soundSetting();
				break;
			default:
				cout << "\nError...\n";
				goto SettingStart;
				break;
			}

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
			if (soundOn) 
				Beep(700 + int(sym * 10), 100);
			lastInput += sym;
			break;
		}

		if (!inApp)
			break;

		if (lastInput.length() > 20)
		{
			lastInput = "";
			//cout << "\nYou didn't say the magic word..."; //I'm wondering if I should add audio? https://www.youtube.com/watch?v=K3PrSj9XEu4&ab_channel=BJ22CS
			Sleep(600);
		}
		
		system("CLS");

		if(!lastInput.empty())
			cout << lastInput << "\n";

		if (lastInput == "wwssadadba")
		{
			if(!devMode and soundOn)
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
				if (soundOn) PlaySound(TEXT("ExtraFiles\\E1M1Doom.wav"), NULL, SND_ASYNC);
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
				if (soundOn) PlaySound(TEXT("ExtraFiles\\Doom'sGate2016.wav"), NULL, SND_ASYNC);
				Sleep(12000);
				quote(quotesEgg1[random], 2);
				break;
			case 1:
				if (soundOn) PlaySound(TEXT("ExtraFiles\\Doom'sGateEternal.wav"), NULL, SND_ASYNC);
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

		if (lastInput == "donut" or lastInput == "doughnut")
		{
			lastInput = "";
			system("CLS");
			pastry();
		}
	}
}

void quote(string quote, int multiplier)
{
	for (int i = 0; i < quote.length(); i++)
	{
		if (quote[i] != '#')
		{
			cout << quote[i];
		}

		int len = 100;
		switch (quote[i])
		{
		case '#':
			len = 250 * multiplier;
			break;
		case '\n':
			len = 650 * multiplier;
			break;
		case ' ':
			len = 100 * multiplier;
			break;
		case ',':
			len = 200 * multiplier;
			break;
		case '.':
		case ';':
		case ':':
		case '?':
		case '!':
			len = 250 * multiplier;
			break;
		default:
			break;
		}

		if (soundOn)
			Beep(int(quote[i] * 10), len);
		else
			Sleep(len);
	}
}

void pastry()
{
	int counter = 0;
	float A = 0, B = 0;
	float i, j;
	int k;
	float z[1760];
	char b[1760];
	cout << "\x1b[2J";
	
	if (soundOn) PlaySound(TEXT("ExtraFiles\\Rotate.wav"), NULL, SND_ASYNC);
	Sleep(10000);
	
	while (counter <= 415)
	{
		memset(b, 32, 1760);
		memset(z, 0, 7040);
		for (j = 0; j < 6.28; j += 0.07)
		{
			for (i = 0; i < 6.28; i += 0.02)
			{
				float c = sin(i);
				float d = cos(j);
				float e = sin(A);
				float f = sin(j);
				float g = cos(A);
				float h = d + 2;
				float D = 1 / (c * h * e + f * g + 5);
				float l = cos(i);
				float m = cos(B);
				float n = sin(B);
				float t = c * h * g - f * e;
				int x = 40 + 30 * D * (l * h * m - t * n);
				int y = 12 + 15 * D * (l * h * n + t * m);
				int o = x + 80 * y;
				int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
				if (22 > y&& y > 0 && x > 0 && 80 > x&& D > z[o])
				{
					z[o] = D;
					b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
				}
			}
		}
		cout << "\x1b[H";
		for (k = 0; k < 1761; k++)
		{
			putchar(k % 80 ? b[k] : 10);
			A += 0.00004;
			B += 0.00002;
		}
		_int64 usec = 30000;
		HANDLE timer;
		LARGE_INTEGER ft;

		ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

		timer = CreateWaitableTimer(NULL, TRUE, NULL);
		SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
		WaitForSingleObject(timer, INFINITE);
		CloseHandle(timer);
		
		counter++;
	}

	PlaySound(NULL, NULL, SND_ASYNC);
	system("CLS");
}

void soundSetting()
{
	system("CLS");
	cout << "Would you like to enable sounds? y/n\n";
	switch (_getch())
	{
	case 'y':
		cout << "\nSounds are enabled.";
		cout << "\nWarning to headphone users. There may be loud noises...";
		soundOn = true;
		break;
	case 'n':
		cout << "\nSounds are disabled.";
		break;
	default:
		cout << "\nInvalid input...\t Sounds are disabled.";
		break;
	}
	_getch();
}
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

//Prints a quote letter by letter
void quote(string quote, int multiplier = 1);

//Easter egg 1
void pastry();

//Opens the sound settings menu
void soundSetting();

//Opens the safety settings menu
void safetySetting();

//Contains main menu. Connects all the other functions
void mainMenu(SET* sets, int setCount);

//Global variables ------------<|
bool soundOn = false;
bool safeMode = false;
char catch_getch = NULL;

//Main ------------------------<|
int main()
{
	srand(time(NULL));

	struct SET sets[30];
	int setCount = 0;

	soundSetting();

	safetySetting();

	catch_getch = _getch();

	mainMenu(sets, setCount);
}

//Functions -------------------<|
void mainMenu(SET* sets, int setCount) //Main menu
{
	system("CLS");

	bool inApp = true; //True if the user is in the program
	bool operationState = false; //True if the operation has finished successfully
	bool devMode = false; //True if devMode is On. Turn devMode to false in release version
	int amount = 0; //Amount of dummy sets to be created 
	int mem = 0; //Used to store temporary integers
	int firstId = 0; //The id of the first set to be used in an operation
	int secondId = 1; //The id of the second set to be used in an operation

	string tempStr = ""; //Temporary String. Used to remove a char from lastInput
	string lastInput = ""; //Stores the last few characters typed by the user
	
	string quotesEgg1[] = { "They are rage, #brutal, #without mercy.\nBut you...\n##You will be worse.\n#Rip #and #tear, ##until it is done.....","Against all the evil that Hell can conjure,\n#all the wickedness that mankind can produce,\n##we will send unto them...\n#only #you.\n##Rip #and #tear, ##until it is done....." }; //Quotes for the second easter egg
	string DOOM = "=================     ===============     ===============   ========  ========\n\\\\ . . . . . . .\\\\   //. . . . . . .\\\\   //. . . . . . .\\\\  \\\\. . .\\\\// . . //\n||. . ._____. . .|| ||. . ._____. . .|| ||. . ._____. . .|| || . . .\\/ . . .||\n|| . .||   ||. . || || . .||   ||. . || || . .||   ||. . || ||. . . . . . . ||\n||. . ||   || . .|| ||. . ||   || . .|| ||. . ||   || . .|| || . | . . . . .||\n|| . .||   ||. _-|| ||-_ .||   ||. . || || . .||   ||. _-|| ||-_.|\\ . . . . ||\n||. . ||   ||-'  || ||  `-||   || . .|| ||. . ||   ||-'  || ||  `|\\_ . .|. .||\n|| . _||   ||    || ||    ||   ||_ . || || . _||   ||    || ||   |\\ `-_/| . ||\n||_-' ||  .|/    || ||    \\|.  || `-_|| ||_-' ||  .|/    || ||   | \\  / |-_.||\n||    ||_-'      || ||      `-_||    || ||    ||_-'      || ||   | \\  / |  `||\n||    `'         || ||         `'    || ||    `'         || ||   | \\  / |   ||\n||            .===' `===.         .==='.`===.         .===' /==. |  \\/  |   ||\n||         .=='   \\_|-_ `===. .==='   _|_   `===. .===' _-|/   `==  \\/  |   ||\n||      .=='    _-'    `-_  `='    _-'   `-_    `='  _-'   `-_  /|  \\/  |   ||\n||   .=='    _-'          `-__\\._-'         `-_./__-'         `' |. /|  |   ||\n||.=='    _-'                                                     `' |  /==.||\n=='    _-'                                                            \\/   `==\n\\   _-'                                                                `-_   /\n"; //ASCII art for the second easter egg
	string operation = ""; //Contains the last operation that was done

	while (inApp)
	{
		if (devMode)
			cout << "DevMode is ON\n";
		cout << "                    __________\n |\\________________/Main  Menu\\________________/|\n";
		cout << " ||                                            |\\_____________________\n";
		cout << " ||      Available space: " << setCount << "\\" << 26 << "                 |     Sound: "; if (soundOn == 1) cout << "On "; else cout << "Off";
		cout << "       \\\n ||                                            | ____Safe_mode:_"; if (safeMode == 1) cout << "On_"; else cout << "Off";
		cout << "___/\n ||        ";
		if (!lastInput.empty())
		{
			cout << lastInput;
			for (int i = 0; i < 36 - lastInput.length(); i++)
			{
				cout << ' ';
			}
			cout << "|/\n";
		}
		else
			cout << "                                    |/\n";
		if(setCount <= 25)	cout << " ||  1. Create a set                           ||\n";
		if (setCount != 0)	cout << " ||  2. Print all sets                         ||\n ||  3. Delete a set                           ||\n";
		if (setCount > 1)	cout << " ||  4. Union of two sets                      ||\n ||  5. Intersection of two sets               ||\n ||  6. Complement of one set in another       ||\n";
		cout << " ||  9. Settings                               ||\n";
		if (devMode and setCount <= 25)
			cout << " ||  0. Add dummy sets                         ||\n"; //Dev only
		cout << " ||  Esc. Quit the program                     ||\n";
		cout << " \\/____________________________________________\\/\n";

//Prints options:
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
		//	Esc. Go back -> quit

//		|                    _________
//		| /\________________/Main  Menu\________________/\
//		| ||                                           |\___________________
//		| ||      Available space: 0\26                |     Sound: On      \
//		| ||                                           | ____Safe_mode:_On__/
//		| ||                                           |/
//		| ||  1. Create a set                          ||
//		| ||  2. Prints all sets                       ||
//		| ||  3. Delete a set                          ||
//		| ||  4. Union of two sets                     ||
//		| ||  5. Intersection of two sets              ||
//		| ||  6. Complement of one set in another      ||
//		| ||  7. OPTIONAL: Save function               ||
//		| ||  8. OPTIONAL: Load function               ||
//		| ||  9. OPTIONAL: Settings                    ||
//		| ||  0. Add dummy sets                        ||
//		| ||  -. OPTIONAL: Credits                     ||
//		| ||  =. OPTIONAL: Explanation                 ||
//		| ||  Esc. Quit the program                    ||
//		| \/____________________________________________\/

		operation = "";
		char sym = _getch(); //Contains the character typed by the user

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
			if (setCount <= 25 and safeMode)
				createSet(sets[setCount], setCount);
			break;
		
		case '2': //2. Prints all or one set
			lastInput = "";
			if (setCount != 0 and safeMode)
				printSets(sets, setCount);
			break;
		
		case '3': //3. Delete a set
			lastInput = "";
			if(setCount != 0 and safeMode)
				removeSet(sets, setCount);
			break;
		
		case '4': //4. Union of two sets
			operation = "Union of two sets";
			goto start;
		
		case '5': //5. Intersection of two sets
			operation = "Intersection of two sets";
			goto start;
		
		case '6': //6. Complement of one set in another
			operation = "Complement of one set in another";
		start:

			if (!(setCount > 1) and safeMode)
				break;

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
			catch_getch =_getch();

			break;
		
		case '9': //9. Settings
			SettingStart:
			system("CLS");

			cout << "--< Settings >--\n";
			cout << "1. Sound settings\n2. Safety settings\nEsc. Quit the program\nBackspace. Go back\n";

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
			case '2':
				safetySetting();
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
				catch_getch  = _getch();
			}
			break;
		
		default:
			if (soundOn) 
				Beep(700 + int(sym * 10), 100);
			if(sym >= 32)
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
			catch_getch =_getch();
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

			catch_getch =_getch();

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
	//https://www.a1k0n.net/2011/07/20/donut-math.html

//		             k;double sin()
//		         ,cos();main(){float A=
//		       0,B=0,i,j,z[1760];char b[
//		     1760];printf("\x1b[2J");for(;;
//		  ){memset(b,32,1760);memset(z,0,7040)
//		  ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
//		 >i;i+=0.02){float c=sin(i),d=cos(j),e=
//		 sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
//		 h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
//		in(B),t=c*h*g-f*        e;int x=40+30*D*
//		(l*h*m-t*n),y=            12+15*D*(l*h*n
//		+t*m),o=x+80*y,          N=8*((f*e-c*d*g
//		 )*m-c*d*e-f*g-l        *d*n);if(22>y&&
//		 y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
//		 ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
//		  printf("\x1b[H");for(k=0;1761>k;k++)
//		   putchar(k%80?b[k]:10);A+=0.04;B+=
//		     0.02;}}/*****####*******!!=;:~
//		       ~::==!!!**********!!!==::-
//		         .,~~;;;========;;;:~-.
//		             ..,--------,*/

	int counter = 0;
	float A = 0, B = 0;
	float i, j;
	int k;
	float z[1760];
	char b[1760];
	cout << "\x1b[2J";
	
	if (soundOn) PlaySound(TEXT("ExtraFiles\\Rotate.wav"), NULL, SND_ASYNC);
	Sleep(10000);
	
	while (counter <= 200)
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
	default:
		cout << "\nInvalid input...\t";
	case 'n':
		cout << "\nSounds are disabled.";
		soundOn = false;
		break;
	}
	catch_getch = _getch();
}

void safetySetting()
{
	system("CLS");
	cout << "Would you like to enable safe mode? y/n\n";
	cout << "Safe mode makes sure that the user cannot do illegal operations.\n";
	switch (_getch())
	{
	case 'y':
		cout << "\nSafe mode is enabled.";
		safeMode = true;
		break;
	default:
		cout << "\nInvalid input...\t Safe mode is disabled.";
	case 'n':
		cout << "\nSafe mode is disabled.";
		safeMode = false;
		break;
	}
	catch_getch =_getch();
}
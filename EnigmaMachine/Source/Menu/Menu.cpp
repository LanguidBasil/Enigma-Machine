#include <iostream>
#include <string>
#include "Menu.h"
#include "MenuMessages.h"

namespace Menu
{
	using std::cout;
	using std::cin;
	using std::endl;

	static char InputOneOfTwo(char expect1, char expect2)
	{
		expect1 = toupper(expect1);
		expect2 = toupper(expect2);
		std::string input;
		char inputC;

		while (true)
		{
			std::cout << Messages::INPUT;
			cin >> input;

			if (input.length() != 1)
			{
				cout << Messages::INVALID_INPUT << endl;
				continue;
			}

			inputC = toupper(input[0]);
			if (inputC == expect1)
				return expect1;
			else if (inputC == expect2)
				return expect2;
			else
				cout << Messages::INVALID_INPUT << endl;
		}
	}

	void Start()
	{
		std::string inputS;
		char inputC;

		cout << Messages::WELCOME << endl << endl;
		cout << Messages::CONF << endl;

		inputC = InputOneOfTwo('R', 'M');
		if (inputC == 'R')
			cout << Messages::CONF_RANDOM << endl << endl;
		else
			cout << Messages::CONF_MANUAL << endl << endl;
	}
}
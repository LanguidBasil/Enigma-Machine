#include <iostream>
#include <string>
#include "../Enigma/Enigma.h"
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

	static void Encryption(Enigma::Enigma& e)
	{
		std::string input;
		std::string output;

		while (true)
		{
			output = "";
			cout << Messages::INPUT;
			std::getline(std::cin, input);

			for (auto c : input)
			{
				c = toupper(c);
				if (c >= 'A' && c <= 'Z')
				{
					c = e.Encode(c);
					output += c;
				}
			}

			for (auto i = 0; i < output.size(); i++)
			{
				cout << output[i];
				if (i % 5 == 0 && i != 0)
					cout << ' ';
			}

			cout << endl;
		}
	}

	void Start()
	{
		std::unique_ptr<Enigma::Enigma> e;
		std::string inputS;
		char inputC;

		cout << Messages::WELCOME << endl << endl;
		cout << Messages::CONF << endl;

		inputC = InputOneOfTwo('R', 'M');
		if (inputC == 'R')
		{
			e = std::make_unique<Enigma::Enigma>(Enigma::Enigma::GenerateRandom());
			cout << Messages::CONF_RANDOM << endl << endl;
		}
		else
		{
			cout << "Not implemented" << endl << endl;
		}

		cout << Messages::ENCRYPTION << endl << endl;
		Encryption(*e.get());
	}
}
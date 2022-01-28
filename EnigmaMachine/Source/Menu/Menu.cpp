#include <iostream>
#include <string>
#include "../Enigma/Enigma.h"
#include "../Enigma/EnigmaConfigurations.h"
#include "Menu.h"
#include "MenuMessages.h"

namespace Menu
{
	using std::cout;
	using std::cin;
	using std::endl;

	static void PrintInputMessage()
	{
		std::cout << Messages::INPUT;
	}

	static void PrintInputMessage(std::string prefix)
	{
		std::cout << prefix << Messages::INPUT;
	}

	static void PrintInvalidInputMessage()
	{
		std::cout << Messages::INVALID_INPUT << endl;
	}

	static char InputOneOfTwo(char expect1, char expect2)
	{
		expect1 = toupper(expect1);
		expect2 = toupper(expect2);
		std::string input;

		while (true)
		{
			PrintInputMessage();
			cin >> input;

			if (input.length() != 1)
			{
				cout << Messages::INVALID_INPUT << endl;
				continue;
			}

			char inputC = toupper(input[0]);
			if (inputC == expect1 || inputC == expect2)
				return inputC;
			else
				PrintInvalidInputMessage();
		}
	}

	static int InputInRange(int lowInclusive, int highInclusive)
	{
		std::string input;

		while (true)
		{
			PrintInputMessage();
			cin >> input;

			int inputI;
			try
			{
				inputI = std::stoi(input);
			}
			catch (const std::exception&)
			{
				PrintInvalidInputMessage();
				continue;
			}

			if (lowInclusive <= inputI && inputI <= highInclusive)
				return inputI;
			else
				PrintInvalidInputMessage();
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
			// Random conf
			e = std::make_unique<Enigma::Enigma>(Enigma::Enigma::GenerateRandom());
			cout << Messages::CONF_RANDOM << endl << endl;
		}
		else
		{
			// Manual conf
			cout << Messages::ConfRotors() << endl << endl << Messages::CONF_MANUAL_ROTORS << endl;
			InputInRange(0, Enigma::Configurations::RotorConfs.size() - 1);
		}

		cout << Messages::ENCRYPTION << endl << endl;
		Encryption(*e.get());
	}
}
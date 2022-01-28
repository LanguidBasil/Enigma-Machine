#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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

	static void PrintInputMessage(const std::string& prefix)
	{
		std::cout << prefix << Messages::INPUT;
	}

	static void PrintInvalidInputMessage()
	{
		std::cout << Messages::INVALID_INPUT << endl;
	}

	// --------------------------------------------------------------------------------------------

	static std::vector<std::string> Tokenize(const std::string& string)
	{
		std::stringstream ss(string);
		std::vector<std::string> tokens;
		std::string token;

		while (std::getline(ss, token, ' '))
			tokens.push_back(token);

		return tokens;
	}

	static char InputOneOfTwo(char expect1, char expect2)
	{
		expect1 = toupper(expect1);
		expect2 = toupper(expect2);
		std::string input;

		while (true)
		{
			PrintInputMessage();
			std::getline(cin >> std::ws, input);

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

	// --------------------------------------------------------------------------------------------

	static bool InputRotorIsCorrect(std::vector<std::string> tokens)
	{
		if (tokens.size() != 3)
			return false;

		try
		{
			int inputI = std::stoi(tokens[0]);
			if (inputI < 0 || inputI > Enigma::Configurations::RotorConfs.size())
				throw std::exception("Index out of range");
		}
		catch (const std::exception&)
		{
			return false;
		}

		char rotationLetter = toupper(tokens[1][0]);
		char ringPositionLetter = toupper(tokens[2][0]);

		if (tokens[1].size() != 1 || tokens[2].size() != 1)
			return false;

		if (rotationLetter < 'A' || rotationLetter > 'Z' || ringPositionLetter < 'A' || ringPositionLetter > 'Z')
			return false;

		return true;
	}

	static Enigma::Rotor InputRotor(std::string inputPrefix)
	{
		std::string input;

		while (true)
		{
			PrintInputMessage(inputPrefix);

			std::getline(cin >> std::ws, input);

			// <rotor index> <starting letter> <ring change letter>
			auto tokens = Tokenize(input);
			if (!InputRotorIsCorrect(tokens))
			{
				PrintInvalidInputMessage();
				continue;
			}

			int inputI = std::stoi(tokens[0]);
			char rotationLetter = toupper(tokens[1][0]);
			char ringPositionLetter = toupper(tokens[2][0]);

			const auto& rotorConf = Enigma::Configurations::RotorConfs[inputI];
			int rotationIndex = 0;
			int ringPositionIndex = 0;
			for (auto i = 0; i < rotorConf.size(); i++)
			{
				if (rotorConf[i] == rotationLetter)
					rotationIndex = i;
				if (rotorConf[i] == ringPositionLetter)
					ringPositionIndex = i;
			}

			return Enigma::Rotor(rotorConf, rotationIndex, ringPositionIndex);
		}
	}

	static std::array<Enigma::Rotor, 3> InputRotors()
	{
		cout << Messages::ConfRotors() << endl << endl << Messages::CONF_MANUAL_ROTORS << endl;

		std::array<Enigma::Rotor, 3> rotors;
		for (auto i = 0; i < 3; i++)
			rotors[i] = InputRotor("Rotor " + std::to_string(i + 1));

		return rotors;
	}

	static std::string InputReflector()
	{
		cout << Messages::ConfReflectors() << endl << endl << Messages::CONF_MANUAL_REFLECTOR << endl;

		const auto& reflectors = Enigma::Configurations::ReflectorConfs;
		int reflectorIndex = InputInRange(0, reflectors.size() - 1);
		return reflectors[reflectorIndex];
	}

	static bool InputPlugboardIsCorrect(std::vector<std::string> tokens, int plugNumber)
	{
		if (tokens.size() != plugNumber)
			return false;

		std::array<bool, 26> letterIsOccupied { false };

		for (auto i = 0; i < plugNumber; i++)
		{
			if (tokens[i].size() != 2)
				return false;

			char fLetter = toupper(tokens[i][0]);
			char sLetter = toupper(tokens[i][1]);
			if (fLetter < 'A' || fLetter > 'Z' || sLetter < 'A' || sLetter > 'Z')
				return false;

			if (fLetter == sLetter)
				continue;

			if (letterIsOccupied[fLetter - 'A'] || letterIsOccupied[sLetter - 'A'])
				return false;

			letterIsOccupied[fLetter - 'A'] = true;
			letterIsOccupied[sLetter - 'A'] = true;
		}

		return true;
	}

	static std::array<Enigma::Plug, 10> InputPlugboard()
	{
		cout << Messages::CONF_MANUAL_PLUGBOARD << endl;

		std::array<Enigma::Plug, 10> plugboard;
		std::string input;

		while (true)
		{
			PrintInputMessage();

			std::getline(cin >> std::ws, input);

			auto tokens = Tokenize(input);
			if (!InputPlugboardIsCorrect(tokens, 10))
			{
				PrintInvalidInputMessage();
				continue;
			}

			for (auto i = 0; i < 10; i++)
				plugboard[i] = Enigma::Plug(tokens[i]);

			return plugboard;
		}
	}

	// --------------------------------------------------------------------------------------------

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
		cout << endl << endl;
		if (inputC == 'R')
		{
			// Random conf
			e = std::make_unique<Enigma::Enigma>(Enigma::Enigma::GenerateRandom());
		}
		else
		{
			// Manual conf
			auto rotors = InputRotors();
			cout << endl << endl;
			auto reflector = InputReflector();
			cout << endl << endl;
			auto plugboard = InputPlugboard();
			cout << endl << endl;

			e = std::make_unique<Enigma::Enigma>(Enigma::Enigma(rotors, plugboard, reflector));
		}

		cout << Messages::ENCRYPTION << endl << endl;
		Encryption(*e.get());
	}
}
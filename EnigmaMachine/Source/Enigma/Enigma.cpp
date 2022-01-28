#include <array>
#include <time.h>
#include "Enigma.h"
#include "EnigmaConfigurations.h"

namespace Enigma
{
	static const int LETTERS_IN_ALPHABET = 26;

	static std::array<Plug, 10> GenerateRandomPlugboard()
	{
		std::srand(time(nullptr));
		
		std::array<Plug, 10> plugboard;
		std::array<bool, LETTERS_IN_ALPHABET> alphabetLetterIsOccupied = { false };

		int letterIndex1, letterIndex2;
		for (int i = 0; i < 10; i++)
		{
			letterIndex1 = rand() % LETTERS_IN_ALPHABET;
			while (alphabetLetterIsOccupied[letterIndex1])
				letterIndex1 = (letterIndex1 + 1) % LETTERS_IN_ALPHABET;
			alphabetLetterIsOccupied[letterIndex1] = true;

			letterIndex2 = rand() % 26;
			while (alphabetLetterIsOccupied[letterIndex2])
				letterIndex2 = (letterIndex2 + 1) % LETTERS_IN_ALPHABET;
			alphabetLetterIsOccupied[letterIndex2] = true;

			plugboard[i] = Plug('A' + letterIndex1, 'A' + letterIndex2);
		}

		return plugboard;
	}

	Enigma::Enigma(std::array<Rotor, 3> rotors, std::array<Plug, 10> plugboard, std::string reflectorConfiguration)
		: Rotors(rotors), Plugboard(plugboard), ReflectorConfiguration(reflectorConfiguration)
	{}

	Enigma Enigma::GenerateRandom()
	{
		std::srand(time(nullptr));

		auto& rotorConfs = Configurations::RotorConfs;
		std::array<Rotor, 3> rotors;
		for (auto i = 0; i < 3; i++)
			rotors[i] = Rotor(rotorConfs[rand() % rotorConfs.size()], rand() % LETTERS_IN_ALPHABET, rand() % LETTERS_IN_ALPHABET);

		auto plugboard = GenerateRandomPlugboard();

		auto& reflectorConfs = Configurations::ReflectorConfs;
		auto reflector = reflectorConfs[rand() % reflectorConfs.size()];

		return ::Enigma::Enigma(rotors, plugboard, reflector);
	}

	char Enigma::Encode(char input)
	{
		input = toupper(input);

		if (input < 'A' || input > 'Z')
			throw "Input is not a character";


		char output = input;

		output = PushToPlugboard(output);

		for (auto i = 0; i < Rotors.size(); i++)
			output = PushToRotor(output, i);

		output = PushToReflector(output);

		for (auto i = 2; i > -1; i--)
			output = PushToRotorBackwards(output, i);

		output = PushToPlugboard(output);

		UpdateRotors();


		return output;
	}

	std::array<Rotor, 3>& Enigma::GetRotors()
	{
		return Rotors;
	}

	std::array<Plug, 10>& Enigma::GetPlugboard()
	{
		return Plugboard;
	}

	std::string& Enigma::GetReflectorConfiguration()
	{
		return ReflectorConfiguration;
	}

	char Enigma::PushToPlugboard(char input) const
	{
		for (auto& plug : Plugboard)
		{
			if (input == plug.Letter1)
				return plug.Letter2;
			else if (input == plug.Letter2)
				return plug.Letter1;
		}

		return input;
	}

	char Enigma::PushToRotor(char input, int rotorIndex) const
	{
		int indexInConf = input - 'A';

		const Rotor& rotor = Rotors[rotorIndex];
		char output = rotor.Configuration[(indexInConf + rotor.Rotation) % LETTERS_IN_ALPHABET];

		return output;
	}

	char Enigma::PushToReflector(char input) const
	{
		int indexInConf = input - 'A';

		char output = ReflectorConfiguration[indexInConf];

		return output;
	}

	char Enigma::PushToRotorBackwards(char input, int rotorIndex) const
	{
		const Rotor& rotor = Rotors[rotorIndex];
		for (auto i = 0; i < LETTERS_IN_ALPHABET; i++)
			if (rotor.Configuration[i] == input)
			{
				int indexInConf = (i + LETTERS_IN_ALPHABET - rotor.Rotation) % LETTERS_IN_ALPHABET;
				return indexInConf + 'A';
			}

		return '0';
	}

	void Enigma::UpdateRotors()
	{
		Rotor* rotor = &Rotors[0];
		rotor->Rotation = (rotor->Rotation + 1) % LETTERS_IN_ALPHABET;

		if (rotor->Rotation == rotor->RotationRingIndex)
		{
			rotor = &Rotors[1];
			rotor->Rotation = (rotor->Rotation + 1) % LETTERS_IN_ALPHABET;
		}

		if (rotor->Rotation == rotor->RotationRingIndex)
		{
			rotor = &Rotors[2];
			rotor->Rotation = (rotor->Rotation + 1) % LETTERS_IN_ALPHABET;
		}
	}
}
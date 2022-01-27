#include <array>
#include "../Enigma.h"
#include "../../Math Extenstions/MathExtensions.h"

const int LETTERS_IN_ALPHABET = 26;

Enigma::Enigma(std::array<Rotor, 3> rotors, std::array<Plug, 10> plugboard, std::string reflectorConfiguration)
	: Rotors(rotors), Plugboard(plugboard), ReflectorConfiguration(reflectorConfiguration) {}

char Enigma::Encode(char input)
{
	// to upper case
	if (InRangeInclusive(input, 'a', 'z'))
		input -= 32;

	if (!InRangeInclusive(input, 'A', 'Z'))
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

char Enigma::PushToPlugboard(char input)
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

char Enigma::PushToRotor(char input, int rotorIndex)
{
	int indexInConf = input - 'A';

	Rotor& rotor = Rotors[rotorIndex];
	char output = rotor.Configuration[(indexInConf + rotor.Rotation) % LETTERS_IN_ALPHABET];

	return output;
}

char Enigma::PushToReflector(char input)
{
	int indexInConf = input - 'A';

	char output = ReflectorConfiguration[indexInConf];

	return output;
}

char Enigma::PushToRotorBackwards(char input, int rotorIndex)
{
	Rotor& rotor = Rotors[rotorIndex];
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
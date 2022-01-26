#include <array>
#include "../Enigma.h"
#include "../../Math Extenstions/MathExtensions.h"

static const int LETTERS_IN_ALPHABET = 26;

Enigma::Enigma(std::array<Rotor, 3> rotors)
	: Rotors(rotors) {}

char Enigma::Encode(char input)
{
	char output = input;

	for (auto i = 0; i < Rotors.size(); i++)
		output = PushToRotor(output, i);

	output = PushToReflector(output);

	for (auto i = 2; i > -1; i--)
		output = PushToRotorBackwards(output, i);

	UpdateRotors();

	return output;
}

char Enigma::PushToRotor(char input, int rotorIndex)
{
	if (!InRangeInclusive(input, 'A', 'Z'))
		throw "Input of Encode on Rotor not in 'A' to 'Z' range";
	int indexInConf = input - 'A';

	Rotor& rotor = Rotors[rotorIndex];
	char output = rotor.Configuration[(indexInConf + rotor.Rotation) % LETTERS_IN_ALPHABET];

	return output;
}

char Enigma::PushToReflector(char input)
{
	char output = input;
	output -= 'A';
	output = (output + 13) % LETTERS_IN_ALPHABET;
	output += 'A';
	return output;
}

char Enigma::PushToRotorBackwards(char input, int rotorIndex)
{
	if (!InRangeInclusive(input, 'A', 'Z'))
		throw "Input of Encode on Rotor not in 'A' to 'Z' range";

	Rotor& rotor = Rotors[rotorIndex];
	int indexInConf;
	for (auto i = 0; i < LETTERS_IN_ALPHABET; i++)
		if (rotor.Configuration[i] == input)
		{
			indexInConf = (i + LETTERS_IN_ALPHABET - rotor.Rotation) % LETTERS_IN_ALPHABET;
			break;
		}

	return indexInConf + 'A';
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
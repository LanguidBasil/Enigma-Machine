#include <array>
#include "../Enigma.h"
#include "../../Math Extenstions/MathExtensions.h"

Enigma::Enigma(std::array<Rotor, 3> rotors)
	: Rotors(rotors) {}

char Enigma::Encode(char input)
{
	char output = input;

	for (auto i = 0; i < Rotors.size(); i++)
		output = PushToRotor(output, i);

	// reflect
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
	char output = rotor.Configuration[(indexInConf + rotor.Rotation) % 26];

	return output;
}

char Enigma::PushToReflector(char input)
{
	char output = input;
	output -= 'A';
	output = (output + 13) % 26;
	output += 'A';
	return output;
}

char Enigma::PushToRotorBackwards(char input, int rotorIndex)
{
	if (!InRangeInclusive(input, 'A', 'Z'))
		throw "Input of Encode on Rotor not in 'A' to 'Z' range";

	Rotor& rotor = Rotors[rotorIndex];
	int indexInConf;
	for (auto i = 0; i < 26; i++)
		if (rotor.Configuration[i] == input)
		{
			indexInConf = i;
			break;
		}

	return indexInConf + 'A';
}

void Enigma::UpdateRotors()
{
	Rotor* rotor = &Rotors[0];
	rotor->Rotation = (rotor->Rotation + 1) % 26;

	if (rotor->Rotation == 0)
	{
		rotor = &Rotors[1];
		rotor->Rotation = (rotor->Rotation + 1) % 26;
	}

	if (rotor->Rotation == 0)
	{
		rotor = &Rotors[2];
		rotor->Rotation = (rotor->Rotation + 1) % 26;
	}
}
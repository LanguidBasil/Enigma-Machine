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

	for (auto i = 2; i > -1; i--)
		output = PushToRotor(output, i);

	return output;
}

char Enigma::PushToRotor(char input, int rotorIndex)
{
	if (!InRangeInclusive(input, 'A', 'Z'))
		throw "Input of Encode on Rotor not in 'A' to 'Z' range";

	input -= 'A';
	Rotor& rotor = Rotors[rotorIndex];
	char output = rotor.Configuration[(input + rotor.Rotation) % 26];
	rotor.Rotation = (rotor.Rotation + 1) % 26;

	return output;
}
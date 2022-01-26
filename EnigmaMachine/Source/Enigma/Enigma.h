#pragma once

#include <array>
#include "Rotor.h"

class Enigma
{
public:
	Enigma(std::array<Rotor, 3> rotors);

	char Encode(char input);

private:
	std::array<Rotor, 3> Rotors;

	char PushToRotor(char input, int rotorIndex);
};
#pragma once

#include <array>
#include "Rotor.h"
#include "Plug.h"

class Enigma
{
public:
	Enigma(std::array<Rotor, 3> rotors, std::array<Plug, 10> plugboard);

	char Encode(char input);

private:
	std::array<Rotor, 3> Rotors;
	std::array<Plug, 10> Plugboard;

	char PushToPlugboard(char input);
	char PushToRotor(char input, int rotorIndex);
	char PushToReflector(char input);
	char PushToRotorBackwards(char input, int rotorIndex);
	void UpdateRotors();
};
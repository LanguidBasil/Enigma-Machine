#include <array>
#include "../Enigma.h"

Enigma::Enigma(char rotorSlow, char rotorMedium, char rotorFast)
	: RotorSlow(rotorSlow), RotorMedium(rotorMedium), RotorFast(rotorFast) {}

std::array<char, 3> Enigma::RotorPoitions()
{
	return std::array<char, 3> { RotorSlow, RotorMedium, RotorFast };
}
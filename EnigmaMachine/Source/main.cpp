#include <iostream>
#include <array>
#include "Enigma/Enigma.h"

int main()
{
	Enigma e('A', 'A', 'A');
	auto rotors = e.RotorPoitions();
	std::cout << rotors[0] << ' ' << rotors[1] << ' ' << rotors[2];
}
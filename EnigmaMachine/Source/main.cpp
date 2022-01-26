#include <iostream>
#include <array>
#include "Enigma/Enigma.h"
#include "Enigma/Rotor.h"

int main()
{
	auto defaultRotorConf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::array<Rotor, 3> rotors = { Rotor(defaultRotorConf, 0), Rotor(defaultRotorConf, 0), Rotor(defaultRotorConf, 0) };
	Enigma e(rotors);

	char input;
	while (true)
	{
		std::cin >> input;
		std::cout << ' ' << e.Encode(input) << std::endl;
	}
}
#include <iostream>
#include <array>
#include "Enigma/Enigma.h"
#include "Enigma/Rotor.h"
#include "Math Extenstions/MathExtensions.h"

int main()
{
	auto IC = "DMTWSILRUYQNKFEJCAZBPGXOHV";
	auto IIC = "HQZGPJTMOBLNCIFDYAWVEUSRKX";
	auto IIIC = "UQNTLSZFMREHDPXKIBVYGJCWOA";
	std::array<Rotor, 3> rotors = { Rotor(IC, 16), Rotor(IIC, 3), Rotor(IIIC, 5) };
	Enigma e(rotors);

	std::string input;
	std::string output;
	while (true)
	{
		std::cin >> input;
		output = "";
		
		for (auto c : input)
			if (InRangeInclusive(c, 'A', 'Z'))
				output += e.Encode(c);

		std::cout << output << std::endl;
	}
}

#include <iostream>
#include <array>
#include "Enigma/Enigma.h"
#include "Math Extenstions/MathExtensions.h"

Enigma constructEnigma()
{
	auto rotorConf1 = "DMTWSILRUYQNKFEJCAZBPGXOHV";
	auto rotorConf2 = "HQZGPJTMOBLNCIFDYAWVEUSRKX";
	auto rotorConf3 = "UQNTLSZFMREHDPXKIBVYGJCWOA";
	std::array<Rotor, 3> rotors = { Rotor(rotorConf1, 16, 14), Rotor(rotorConf2, 3, 4), Rotor(rotorConf3, 5, 21) };

	std::array<Plug, 10> plugboard = { Plug("QE"), Plug("ZI"), Plug("OA"), Plug("SD"), Plug("HJ"), Plug("KC"), Plug("WU"), Plug("FY"), Plug("VN"), Plug("BT") };

	auto reflectorConf = "FVPJIAOYEDRZXWGCTKUQSBNMHL";

	return Enigma(rotors, plugboard, reflectorConf);
}

int main()
{
	Enigma e = constructEnigma();

	std::string input;
	std::string output;
	while (true)
	{
		std::getline(std::cin, input);
		output = "";
		
		for (auto c : input)
			if (InRangeInclusive(c, 'A', 'Z') || InRangeInclusive(c, 'a', 'z'))
				output += e.Encode(c);

		for (auto i = 0; i < output.size(); i++)
		{
			std::cout << output[i];

			if ((i + 1) % 5 == 0)
				std::cout << ' ';
		}

		std::cout << std::endl << std::endl;
	}
}

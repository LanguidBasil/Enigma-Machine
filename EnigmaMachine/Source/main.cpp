#include <iostream>
#include <array>
#include "Enigma/Enigma.h"
#include "Math Extenstions/MathExtensions.h"

int main()
{
	auto IC = "DMTWSILRUYQNKFEJCAZBPGXOHV";
	auto IIC = "HQZGPJTMOBLNCIFDYAWVEUSRKX";
	auto IIIC = "UQNTLSZFMREHDPXKIBVYGJCWOA";
	std::array<Rotor, 3> rotors = { Rotor(IC, 16, 0), Rotor(IIC, 3, 0), Rotor(IIIC, 5, 0) };
	std::array<Plug, 10> plugs = { Plug("QE"), Plug("ZI"), Plug("OA"), Plug("SD"), Plug("HJ"), Plug("KC"), Plug("WU"), Plug("FY"), Plug("VN"), Plug("BT") };
	Enigma e(rotors, plugs);

	std::string input;
	std::string output;
	while (true)
	{
		std::cin >> input;
		output = "";
		
		for (auto c : input)
			if (InRangeInclusive(c, 'A', 'Z'))
				output += e.Encode(c);

		std::cout << output << std::endl << std::endl;
	}
}

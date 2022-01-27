#include <iostream>
#include <array>
#include "Enigma/Enigma.h"
#include "Enigma/EnigmaConfigurations.h"
#include "Math Extenstions/MathExtensions.h"

Enigma::Enigma constructEnigma()
{
	using namespace Enigma;
	namespace Confs = ::Enigma::Configurations;

	std::array<Rotor, 3> rotors = { Rotor(Confs::RotorI, 16, 14), Rotor(Confs::RotorII, 3, 4), Rotor(Confs::RotorIII, 5, 21) };

	std::array<Plug, 10> plugboard = { Plug("QE"), Plug("ZI"), Plug("OA"), Plug("SD"), Plug("HJ"), Plug("KC"), Plug("WU"), Plug("FY"), Plug("VN"), Plug("BT") };

	auto reflectorConf = Confs::ReflectorA;

	return ::Enigma::Enigma(rotors, plugboard, reflectorConf);
}

int main()
{
	Enigma::Enigma e = constructEnigma();

	std::string input;
	std::string output;
	while (true)
	{
		std::getline(std::cin, input);
		output = "";
		
		for (auto c : input)
			if (MathExt::InRangeInclusive(c, 'A', 'Z') || MathExt::InRangeInclusive(c, 'a', 'z'))
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

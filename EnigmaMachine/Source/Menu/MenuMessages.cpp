#include <string>
#include "MenuMessages.h"
#include "../Enigma/EnigmaConfigurations.h"

namespace Menu
{
namespace Messages
{
	std::string ConfRotors()
	{
		std::string output = "";
		const auto& rotors = Enigma::Configurations::RotorConfs;

		output += "0: " + rotors[0];
		for (int i = 1; i < rotors.size(); i++)
			output += '\n' + std::to_string(i) + ": " + rotors[i];

		return output;
	}

	std::string ConfReflectors()
	{
		std::string output = "";
		const auto& reflectors = Enigma::Configurations::ReflectorConfs;

		output += "0: " + reflectors[0];
		for (int i = 1; i < reflectors.size(); i++)
			output += '\n' + std::to_string(i) + ": " + reflectors[i];

		return output;
	}
}
}
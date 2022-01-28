#include <string>
#include "MenuMessages.h"
#include "../Enigma/Enigma.h"
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

	std::string CurrentConf(const Enigma::Enigma& e)
	{
		std::string output = "";
		const auto& rotors = e.GetRotors();

		for (auto i = 0; i < rotors.size(); i++)
		{
			const auto& cRotor = rotors[i];

			output += "Rotor " + std::to_string(i) + ": conf - " + cRotor.Configuration +
					  " current letter - " + cRotor.Configuration[cRotor.Rotation] + 
					  " ring letter - " + cRotor.Configuration[cRotor.RotationRingIndex];
			output += '\n';
		}

		output += "Reflector configuration: " + e.GetReflectorConfiguration() + '\n';

		output += "Plugboard configuration: ";
		for (const auto& plug : e.GetPlugboard())
		{
			output += plug.Letter1;
			output += plug.Letter2;
			output += ' ';
		}

		return output;
	}
}
}
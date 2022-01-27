#pragma once

#include <array>
#include "Rotor.h"
#include "Plug.h"

namespace Enigma
{
	class Enigma
	{
	public:
		Enigma(std::array<Rotor, 3> rotors, std::array<Plug, 10> plugboard, std::string reflectorConfiguration);

		static Enigma GenerateRandom();
		char Encode(char input);

	private:
		std::array<Rotor, 3> Rotors;
		std::array<Plug, 10> Plugboard;
		/// Every two letters should be flipped, i.e. if a is b then b should be a
		std::string ReflectorConfiguration;

		char PushToPlugboard(char input) const;
		char PushToRotor(char input, int rotorIndex) const;
		char PushToReflector(char input) const;
		char PushToRotorBackwards(char input, int rotorIndex) const;
		void UpdateRotors();
	};
}

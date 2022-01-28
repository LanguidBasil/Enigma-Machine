#pragma once

#include <string>
#include <array>

namespace Enigma
{
	namespace Configurations
	{
		static const std::string RotorI    = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
		static const std::string RotorII   = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
		static const std::string RotorIII  = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
		static const std::string RotorIV   = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
		static const std::string RotorV	   = "VZBRGITYUPSDNHLXAWMJQOFECK";
		static const std::string RotorVI   = "JPGVOUMFYQBENHZRDKASXLICTW";
		static const std::string RotorVII  = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
		static const std::string RotorVIII = "FKQHTLXOCBJSPDZRAMEWNIUYGV";

		static const std::string ReflectorA		= "EJMZALYXVBWFCRQUONTSPIKHGD";
		static const std::string ReflectorB		= "YRUHQSLDPXNGOKMIEBFZCWVJAT";
		static const std::string ReflectorC		= "FVPJIAOYEDRZXWGCTKUQSBNMHL";
		static const std::string ReflectorBThin = "ENKQAUYWJICOPBLMDXZVFTHRGS";
		static const std::string ReflectorCThin = "RDOBJNTKVEHMLFCWZAXGYIPSUQ";

		static const std::array<std::string, 8> RotorConfs = { RotorI, RotorII, RotorIII, RotorIV, RotorV, RotorVI, RotorVII, RotorVIII };
		static const std::array<std::string, 5> ReflectorConfs = { ReflectorA, ReflectorB, ReflectorC, ReflectorBThin, ReflectorCThin };
	}
}
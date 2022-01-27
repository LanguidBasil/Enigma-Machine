#pragma once

#include <string>

namespace Enigma
{
	struct Rotor
	{
		Rotor()
			: Configuration(""), Rotation(-1), RotationRingIndex(-1) {}

		Rotor(std::string configuration, int rotation, int rotationRingIndex)
			: Configuration(configuration), Rotation(rotation), RotationRingIndex(rotationRingIndex) {}

		/// String of 26 characters which represents order of characters on rotor
		std::string Configuration;
		int Rotation;
		/// At this index of rotation next ring should rotate
		int RotationRingIndex;
	};
}
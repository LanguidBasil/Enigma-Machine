#pragma once

#include <string>

struct Rotor
{
	Rotor(std::string configuration, int rotation, int rotationRingIndex)
		: Configuration(configuration), Rotation(rotation), RotationRingIndex(rotationRingIndex) {}

	/// string of 26 characters which represents order of characters on rotor
	const std::string Configuration;
	int Rotation;
	/// At this index of rotation next ring should rotate
	const int RotationRingIndex;
};
#pragma once

#include <string>

struct Rotor
{
	Rotor(std::string configuration, int rotation)
		: Configuration(configuration), Rotation(rotation) {}

	const std::string Configuration;
	int Rotation;
};
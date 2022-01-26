#pragma once

class Enigma
{
public:
	Enigma(char rotorSlow, char rotorMedium, char rotorFast);

	std::array<char, 3> RotorPoitions();

private:
	char RotorSlow;
	char RotorMedium;
	char RotorFast;
};
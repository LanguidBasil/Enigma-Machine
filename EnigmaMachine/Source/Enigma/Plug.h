#pragma once

#include <string>

namespace Enigma
{
	struct Plug
	{
		Plug()
			: Letter1('\0'), Letter2('\0') {}
		Plug(char letter1, char letter2)
			: Letter1(letter1), Letter2(letter2) {}
		Plug(std::string letters)
			: Letter1(letters[0]), Letter2(letters[1]) {}

		char Letter1;
		char Letter2;
	};
}
#pragma once

#include <string>

namespace Enigma
{
	struct Plug
	{
		Plug(char letter1, char letter2)
			: Letter1(letter1), Letter2(letter2)
		{}
		Plug(std::string letters)
			: Letter1(letters[0]), Letter2(letters[1])
		{}

		const char Letter1;
		const char Letter2;
	};
}
#pragma once

#include <string>

namespace Menu
{
namespace Messages
{
	/*
		| WELCOME
		| CONFIGURATION | RANDOM
		| 				| MANUALLY | ROTOR, RINGS, START POSITION
		| 						   | REFLECTOR
		| 						   | PLUG BOARD
		| ENCRYPTION | WORK
		|			 | GET CONFIGURATION
		|			 | RECONFIGURE
	*/

	/*
		any user input proceed as
		: <input>
		or
		<index of operation>: <input>
	*/

	static const std::string INVALID_INPUT =
R"(Invalid input)";

	static const std::string INPUT =
R"(: )";





	static const std::string WELCOME =
R"(Welcome to Enigma machine simulator!)";





	static const std::string CONF =
R"(Enter 'R' to generate random configuration or 'M' to configure manually)";



	static const std::string CONF_RANDOM =
R"(Enigma was configured randomly)";



	static const std::string CONF_MANUAL =
R"(Manual configuration)";

	// print options of rotors above
	static const std::string CONF_MANUAL_ROTORS =
R"(To choose a rotor enter comand as:
"<rotor wheel index> <ring change position> <starting letter of rotor>"

Rotor wheel index - index from above
Ring change position - when letter on rotor is equal to this number next rotor will rotate as well

Ring change position and starting letter of rotor should be in 0 to 25 range)";

	// print options of reflectors above
	static const std::string CONF_MANUAL_REFLECTOR =
R"(Enter index of reflector from above: )";

	static const std::string CONF_MANUAL_PLUGBOARD =
R"(Enter 10 plugboard setting as "<letter 1><letter 2>"
If you don't want to insert plug enter two identical letters as "AA")";





	static const std::string ENCRYPTION =
R"(Configuration finished, enter message of letters to encode
Enter 1 to get current configuration, 2 to reset machine, or 3 to reconfigure
Any other symbol e.g. space, '8', '\' will be ignored)";

	static const std::string ENCRYPTION_CURRENT_CONF =
R"(Current configuration: )";

}
}
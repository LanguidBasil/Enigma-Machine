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



	static const std::string CONF_MANUAL =
R"(Manual configuration)";

	std::string ConfRotors();

	static const std::string CONF_MANUAL_ROTORS =
R"(To choose a rotor enter comand as:
"<rotor index> <starting letter> <ring change letter>"

Ring change letter - when rotor is on that letter it will rotate next rotor as well
For example, a command "0 J L"
Will choose first rotor that starts on letter 'J' and on letter 'L' will rotate next rotor)";

	std::string ConfReflectors();

	static const std::string CONF_MANUAL_REFLECTOR =
R"(Enter index of reflector from above: )";

	static const std::string CONF_MANUAL_PLUGBOARD =
R"(Enter 10 plugboard setting as "<letter 1><letter 2>"
If you don't want to insert plug enter two identical letters as "AA")";





	static const std::string ENCRYPTION =
R"(Configuration finished, you can:
- Enter message of letters to encode
- Enter 1 to get current configuration
- Enter 2 to reset machine
- Enter 3 to reconfigure
Any other symbol e.g. space, '8' or '\' will be ignored)";

	static const std::string ENCRYPTION_CURRENT_CONF =
R"(Current configuration: )";

}
}
#include <string>
#include "Menu.h"

namespace Menu
{
/*
	| WELCOME
	| CONFIGURATION | RANDOM
	| 				| MANUALLY | ROTOR, RINGS, START POSITION
	| 						   | REFLECTION
	| 						   | PLUG BOARD
	| ENCRYPTION | WORK
	|			 | GET CONFIGURATION
*/

static const std::string MESSAGE_INVALID_INPUT =
R"(Invalid input)";

static const std::string MESSAGE_WELCOME =
R"(Welcome to Enigma machine simulator!)";

static const std::string MESSAGE_CONF_MENU =
R"(Enter 'R' to generate random configuration or 'M' to configure manually)";

static const std::string MESSAGE_CONF_RANDOM =
R"(Enigma was configured randomly)";

static const std::string MESSAGE_CONF_MANUAL =
R"(Manual configuration)";

static const std::string MESSAGE_CONF_MANUAL_ROTORS =
R"()";

static void Start()
{

}
}
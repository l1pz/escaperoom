#include <locale>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#endif


#include <cereal/archives/binary.hpp> // this has to load before loading item types
#include "base/Room.h"
#include "unique_items/Cabinet.h"
#include "Player.h"

std::shared_ptr<Room> init()
{
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban állok.");
	const auto cabinet = std::make_shared<Cabinet>("szekrény", "Egy fenyõ szekrény rajta matricákkal.", livingRoom);
	livingRoom->addItemInside(cabinet, "A fal mellett szorosan egy szekrény áll.");
	return livingRoom;
}

int main()
{
	std::locale::global(std::locale("hu"));
#ifdef _WIN32
	SetConsoleCP(28592);
	SetConsoleOutputCP(28592);
#endif	
	Player p{init()};
	while (true) p.input();
}

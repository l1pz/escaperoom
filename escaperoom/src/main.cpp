#include <locale>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#endif


#include <cereal/archives/binary.hpp> // this has to load before loading item types
#include "base/Room.h"
#include "unique_items/Cabinet.h"
#include "unique_items/Box.h"
#include "Player.h"

std::shared_ptr<Room> init()
{
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban állok.");

	auto cabinet = std::make_shared<Cabinet>("szekrény", "Egy fenyõ szekrény rajta matricákkal.", livingRoom);
	cabinet->unlockedMessage = "Kinyitottad a szekrényt. Egy dobozt látsz benne.";
	cabinet->alreadyUnlockedMessage = "Már ki van nyitva a szekrény.";
	cabinet->movedMessage = "Elhúztad a szekrényt. Mögötte a falon egy ablakot látsz.";
	cabinet->alreadyMovedMessage = "Már elhúztad a szekrényt. Egy ablak volt mögötte.";

	auto box = std::make_shared<Box>("doboz", "Egy apró fémdoboz. Mintha csörögne benne valami.");
	box->unlockedMessage = "Kinyitottad a dobozt. Egy kulcs volt benne.";
	box->alreadyUnlockedMessage = "Már nyitva van a doboz.";

	cabinet->addItemInside(box, "Egy fényes doboz van a szekrény aljában.");

	livingRoom->addItemInside(cabinet, "A fal mellett egy szekrény áll.");
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

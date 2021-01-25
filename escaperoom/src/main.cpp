#include <locale>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#endif


#include <cereal/archives/binary.hpp> // this has to load before loading item types
#include "base/Room.h"
#include "unique_items/Cabinet.h"
#include "unique_items/Box.h"
#include "unique_items/Door.h"
#include "unique_items/Key.h"
#include "Player.h"
#include "unique_items/Bathtub.h"

std::shared_ptr<Room> init()
{
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban állok.");
	auto bathroom = std::make_shared<Room>("fürdõszoba", "Egy fürdõszobában állok, a falát csúnya rózsaszín csempe borítja.\nKeletre egy kijárat van a nappaliba.");
	
	auto cabinet = std::make_shared<Cabinet>("szekrény", "Egy fenyõ szekrény rajta matricákkal.", livingRoom);
	cabinet->unlockedMessage = "Kinyitottad a szekrényt. Egy dobozt látsz benne.";
	cabinet->alreadyUnlockedMessage = "Már ki van nyitva a szekrény.";
	cabinet->movedMessage = "Elhúztad a szekrényt. Mögötte a falon egy ablakot látsz.";
	cabinet->alreadyMovedMessage = "Már elhúztad a szekrényt. Egy ablak volt mögötte.";

	auto box = std::make_shared<Box>("doboz", "Egy apró fémdoboz.");
	box->unlockedMessage = "Kinyitottad a dobozt. Egy kulcs volt benne.";
	box->alreadyUnlockedMessage = "Már nyitva van a doboz.";

	cabinet->addItemInside(box, "Egy fényes doboz van a szekrény aljában.");
	
	const auto key = std::make_shared<Key>("kulcs", "Egy régi rozsdás kulcs.");
	livingRoom->addItemInside(key, "Egy kulcs van benne.");
	
	const auto door = std::make_shared<Door>("ajtó", "Egy fehér fa ajtó.", key);
	door->needKeyMessage = "Az ajtó kulcsra van zárva.";
	door->alreadyUnlockedMessage = "Az ajtó már ki van nyitva.";
	door->wrongKeyMessage = "Nem ilyen kulcs való a zárba.";
	door->unlockedMessage = "A kulcs elfordult a zárban, az ajtó kinyílt.";

	auto bathtub = std::make_shared<Bathtub>("kád", "Egy fehér zománcozott fürdõkád.");
	
	livingRoom->addExit({ Room::Direction::WEST, bathroom, door });
	bathroom->addExit({ Room::Direction::EAST, livingRoom });

	bathroom->addItemInside(bathtub, "Egy kád áll a sarokban.");
	
	livingRoom->addItemInside(door, "Egy ajtót látsz nyugatra.");
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

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
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban �llok.");

	auto cabinet = std::make_shared<Cabinet>("szekr�ny", "Egy feny� szekr�ny rajta matric�kkal.", livingRoom);
	cabinet->unlockedMessage = "Kinyitottad a szekr�nyt. Egy dobozt l�tsz benne.";
	cabinet->alreadyUnlockedMessage = "M�r ki van nyitva a szekr�ny.";
	cabinet->movedMessage = "Elh�ztad a szekr�nyt. M�g�tte a falon egy ablakot l�tsz.";
	cabinet->alreadyMovedMessage = "M�r elh�ztad a szekr�nyt. Egy ablak volt m�g�tte.";

	auto box = std::make_shared<Box>("doboz", "Egy apr� f�mdoboz. Mintha cs�r�gne benne valami.");
	box->unlockedMessage = "Kinyitottad a dobozt. Egy kulcs volt benne.";
	box->alreadyUnlockedMessage = "M�r nyitva van a doboz.";

	cabinet->addItemInside(box, "Egy f�nyes doboz van a szekr�ny alj�ban.");

	livingRoom->addItemInside(cabinet, "A fal mellett egy szekr�ny �ll.");
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

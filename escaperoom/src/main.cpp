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
#include "unique_items/Crowbar.h"
#include "unique_items/Window.h"

std::shared_ptr<Room> init()
{
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban �llok.");
	auto bathroom = std::make_shared<Room>("f�rd�szoba", "Egy f�rd�szob�ban �llok, a fal�t cs�nya r�zsasz�n csempe bor�tja.\nKeletre egy kij�rat van a nappaliba.");
	auto outside = std::make_shared<Room>("udvar", "Kijutottam.");
	
	auto cabinet = std::make_shared<Cabinet>("szekr�ny", "Egy feny� szekr�ny rajta matric�kkal.", livingRoom);
	cabinet->unlockedMessage = "Kinyitottad a szekr�nyt. Egy dobozt l�tsz benne.";
	cabinet->alreadyUnlockedMessage = "M�r ki van nyitva a szekr�ny.";
	cabinet->movedMessage = "Elh�ztad a szekr�nyt.";
	cabinet->alreadyMovedMessage = "M�r elh�ztad a szekr�nyt. Egy ablak volt m�g�tte.";

	auto box = std::make_shared<Box>("doboz", "Egy apr� f�mdoboz.");
	box->unlockedMessage = "Kinyitottad a dobozt. Egy kulcs volt benne.";
	box->alreadyUnlockedMessage = "M�r nyitva van a doboz.";
	box->noNeedKeyMessage = "A kinyit�shoz nem kell kulcs, el�g ha lepattintom a tetej�t.";

	cabinet->addItemInside(box, "Egy f�nyes doboz van a szekr�ny alj�ban.");
	
	const auto key = std::make_shared<Key>("kulcs", "Egy r�gi rozsd�s kulcs.");
	box->addItemInside(key, "Egy kulcs van benne.");
	
	const auto door = std::make_shared<Door>("ajt�", "Egy feh�r fa ajt�.", key);
	door->needKeyMessage = "Az ajt� kulcsra van z�rva.";
	door->alreadyUnlockedMessage = "Az ajt� m�r ki van nyitva.";
	door->wrongKeyMessage = "Nem ilyen kulcs val� a z�rba.";
	door->unlockedMessage = "A kulcs elfordult a z�rban, az ajt� kiny�lt.";

	auto bathtub = std::make_shared<Bathtub>("k�d", "Egy feh�r zom�ncozott f�rd�k�d.");

	const auto crowbar = std::make_shared<Crowbar>("fesz�t�vas", "Egy piros fesz�t�vas. Pont mint Gordon Freeman�.");

	const auto window = std::make_shared<Window>("ablak", "Egy ablak, amin kereszt�l tal�n kijuthatn�k.", std::make_shared<Item>(), crowbar);
	window->alreadyBrokeMessage = "M�r be van t�rve az ablak.";
	window->needToolMessage = "Az �veg megv�gn� a kezem. Sz�ks�gem van valamire, hogy bet�rjem.";
	window->brokeMessage = "Siker�lt bet�rni az ablakot.";
	window->wrongToolMessage = "Ezzel nem tudom bet�rni az ablakot.";
	window->needKeyMessage = "Az ablak be van szorulva. Nem tudom kinyitni.";
	window->wrongKeyMessage = "Az ablak be van szorulva. Nem tudom kinyitni ezzel a t�rggyal.";

	cabinet->addItemBehind(window, "Egy ablak van az �szaki falon.", "M�g�tte a falon egy ablakot l�tsz.");

	bathtub->addItemInside(crowbar, "Egy fesz�t�vas van benne.");
	
	livingRoom->addExit({ Room::Direction::WEST, bathroom, door });
	livingRoom->addExit({ Room::Direction::NORTH, outside, window });
	bathroom->addExit({ Room::Direction::EAST, livingRoom });

	bathroom->addItemInside(bathtub, "Egy k�d �ll a sarokban.");
	
	livingRoom->addItemInside(door, "Egy ajt�t l�tsz nyugatra.");
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

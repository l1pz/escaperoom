#include <locale>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "base/Room.h"
#include "base/StorageItem.h"
#include "base/LiftableItem.h"
#include "base/LockedItem.h"
#include "base/MovableItem.h"
#include "Player.h"
#include "base/BreakableItem.h"

int main()
{
	std::locale::global(std::locale("hu"));
#ifdef _WIN32
	SetConsoleCP(28592);
	SetConsoleOutputCP(28592);
#endif
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban állok.");
	auto kitchen = std::make_shared<Room>("konyha", "Egy konyhában vagyok.");
	auto table = std::make_shared<StorageItem>("asztal", "Az asztal elég öreg, már pattogzik rajta a festék.");
	const auto key = std::make_shared<LiftableItem>("kulcs", "Egy rozsdás öreg kulcs.");
	const auto lockedChest = std::make_shared<LockedItem>("fémládika", "Az ládika alumíniumból készült. Be van zárva.", key); 
	auto chest = std::make_shared<StorageItem>("faládika", "Tölgyfából készült. Láthatólag nyitva van.");
	const auto money = std::make_shared<LiftableItem>("pénz", "Kissé gyûrött, de legalább nem szakadt.");
	auto sofa = std::make_shared<MovableItem>("kanapé", "Egy poros, foltos kanapé.", livingRoom);
	const auto coin = std::make_shared<LiftableItem>("érme", "Egy 5 forintos érme.");
	auto crowbar = std::make_shared<Item>("feszítõvas", "Pont mint Gordon Freemané.");
	const auto crate = std::make_shared<BreakableItem>("láda", "Egy fából készült láda. Nem tûnik túl erõsnek.", crowbar);
	
	livingRoom->addItem(table, "A szoba közepén van egy asztal.");
	livingRoom->addItem(crate, "Egy láda van az asztal elõtt.");
	table->addItem(lockedChest, "Az asztalon egy fémládika található.");
	table->addItem(chest, "Van itt egy faládika is.");
	table->addItem(key, "Hever rajta egy kulcs.");
	table->addItem(crowbar, "Van rajta egy feszítõvas is.");
	chest->addItem(money, "A ládikában pénz van.");
	sofa->addItem(coin, "Egy érme van a földön.", "A kanapé alatt egy érme volt a porban.");
	livingRoom->addItem(sofa, "A sarokban egy kanapé áll.");

	livingRoom->addExit(Room::Direction::EAST, kitchen);
	kitchen->addExit(Room::Direction::WEST, livingRoom);
	
	Player p{livingRoom};
	while (true) p.input();
}

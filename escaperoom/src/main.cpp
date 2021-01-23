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
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban �llok.");
	auto kitchen = std::make_shared<Room>("konyha", "Egy konyh�ban vagyok.");
	auto table = std::make_shared<StorageItem>("asztal", "Az asztal el�g �reg, m�r pattogzik rajta a fest�k.");
	const auto key = std::make_shared<LiftableItem>("kulcs", "Egy rozsd�s �reg kulcs.");
	const auto lockedChest = std::make_shared<LockedItem>("f�ml�dika", "Az l�dika alum�niumb�l k�sz�lt. Be van z�rva.", key); 
	auto chest = std::make_shared<StorageItem>("fal�dika", "T�lgyf�b�l k�sz�lt. L�that�lag nyitva van.");
	const auto money = std::make_shared<LiftableItem>("p�nz", "Kiss� gy�r�tt, de legal�bb nem szakadt.");
	auto sofa = std::make_shared<MovableItem>("kanap�", "Egy poros, foltos kanap�.", livingRoom);
	const auto coin = std::make_shared<LiftableItem>("�rme", "Egy 5 forintos �rme.");
	auto crowbar = std::make_shared<Item>("fesz�t�vas", "Pont mint Gordon Freeman�.");
	const auto crate = std::make_shared<BreakableItem>("l�da", "Egy f�b�l k�sz�lt l�da. Nem t�nik t�l er�snek.", crowbar);
	
	livingRoom->addItem(table, "A szoba k�zep�n van egy asztal.");
	livingRoom->addItem(crate, "Egy l�da van az asztal el�tt.");
	table->addItem(lockedChest, "Az asztalon egy f�ml�dika tal�lhat�.");
	table->addItem(chest, "Van itt egy fal�dika is.");
	table->addItem(key, "Hever rajta egy kulcs.");
	table->addItem(crowbar, "Van rajta egy fesz�t�vas is.");
	chest->addItem(money, "A l�dik�ban p�nz van.");
	sofa->addItem(coin, "Egy �rme van a f�ld�n.", "A kanap� alatt egy �rme volt a porban.");
	livingRoom->addItem(sofa, "A sarokban egy kanap� �ll.");

	livingRoom->addExit(Room::Direction::EAST, kitchen);
	kitchen->addExit(Room::Direction::WEST, livingRoom);
	
	Player p{livingRoom};
	while (true) p.input();
}

#include <locale>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "base/Room.h"
#include "base/StorageItem.h"
#include "base/LiftableItem.h"
#include "base/LockedItem.h"
#include "Player.h"

int main()
{
	std::locale::global(std::locale("hu"));
#ifdef _WIN32
	SetConsoleCP(28592);
	SetConsoleOutputCP(28592);
#endif
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban �llok.");
	auto table = std::make_shared<StorageItem>("asztal", "Az asztal el�g �reg, m�r pattogzik rajta a fest�k.");
	const auto key = std::make_shared<LiftableItem>("kulcs", "Egy rozsd�s �reg kulcs.");
	const auto lockedChest = std::make_shared<LockedItem>("f�ml�dika", "Az l�dika alum�niumb�l k�sz�lt. Be van z�rva.", []() {std::cout << "L�da nyitva"; }, key); 
	auto chest = std::make_shared<StorageItem>("fal�dika", "T�lgyf�b�l k�sz�lt. L�that�lag nyitva van.");
	const auto money = std::make_shared<LiftableItem>("p�nz", "Kiss� gy�r�tt, de legal�bb nem szakadt.");

	livingRoom->addItem(table, "A szoba k�zep�n van egy asztal.");
	table->addItem(lockedChest, "Az asztalon egy f�ml�dika tal�lhat�.");
	table->addItem(chest, "Van itt egy fal�dika is.");
	chest->addItem(money, "A l�dik�ban p�nz van.");

	Player p{livingRoom};
	while (true) p.input();
}

#include <locale>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "base/Room.h"
#include "base/StorageItem.h"
#include "base/LiftableItem.h"
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
	auto chest = std::make_shared<StorageItem>("l�dika", "Az l�dika alum�niumb�l k�sz�lt.");
	const auto money = std::make_shared<LiftableItem>("p�nz", "A p�nz kiss� gy�r�tt.");

	livingRoom->addItem(table, "A szoba k�zep�n van egy asztal.");
	table->addItem(chest, "Az asztalon egy l�dika tal�lhat�.");
	chest->addItem(money, "Benne egy kev�s p�nz tal�lhat�.");

	Player p{livingRoom};
	while (true) p.input();
}

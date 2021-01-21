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
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban állok.");
	auto table = std::make_shared<StorageItem>("asztal", "Az asztal elég öreg, már pattogzik rajta a festék.");
	const auto key = std::make_shared<LiftableItem>("kulcs", "Egy rozsdás öreg kulcs.");
	const auto chest = std::make_shared<LockedItem>("ládika", "Az ládika alumíniumból készült.", []() {std::cout << "Láda nyitva"; }, key); 

	livingRoom->addItem(table, "A szoba közepén van egy asztal.");
	table->addItem(chest, "Az asztalon egy ládika található.");

	Player p{livingRoom};
	while (true) p.input();
}

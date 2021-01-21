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
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban állok.");
	auto table = std::make_shared<StorageItem>("asztal", "Az asztal elég öreg, már pattogzik rajta a festék.");
	auto chest = std::make_shared<StorageItem>("ládika", "Az ládika alumíniumból készült.");
	const auto money = std::make_shared<LiftableItem>("pénz", "A pénz kissé gyûrött.");

	livingRoom->addItem(table, "A szoba közepén van egy asztal.");
	table->addItem(chest, "Az asztalon egy ládika található.");
	chest->addItem(money, "Benne egy kevés pénz található.");

	Player p{livingRoom};
	while (true) p.input();
}

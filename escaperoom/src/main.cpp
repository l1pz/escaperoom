#include <locale>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "base/Room.h"
#include "base/StorageItem.h"
#include "base/LiftableItem.h"
#include "Player.h"

int main() {
	std::locale::global(std::locale("hu"));
#ifdef _WIN32
	SetConsoleCP(28592);
	SetConsoleOutputCP(28592);
#endif
	std::cout << "ÂÁrvíztûrõ tükörfúrógép";
	auto livingRoom = std::make_shared<Room>("livingroom", "livingroom");
	auto table = std::make_shared<StorageItem>("table", "table");
	auto chest = std::make_shared<StorageItem>("chest", "chest");
	const auto money = std::make_shared<LiftableItem>("money", "money");

	livingRoom->addItem(table);
	table->addItem(chest);
	chest->addItem(money);
	
	Player p;
	while (true) p.input();

	return 0;
}
#ifdef _WIN32
#include <Windows.h>
#endif

#include "base/Room.h"
#include "base/Item.h"
#include "base/StorageItem.h"


int main() {
#ifdef _WIN32
	SetConsoleCP(65001); // set input console codepage to utf8
	SetConsoleOutputCP(65001); // set output console codepage to utf8
#endif
	auto livingRoom = std::make_shared<Room>("livingroom", "livingroom");
	auto table = std::make_shared<StorageItem>("table", "table");
	auto chest = std::make_shared<StorageItem>("chest", "chest");
	auto money = std::make_shared<Item>("money", "money");

	livingRoom->addItem(table);
	table->addItem(chest);
	chest->addItem(money);
	auto x = livingRoom->removeItem("money");
	return 0;
}
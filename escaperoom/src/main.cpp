#ifdef _WIN32
#include <Windows.h>
#endif

#include "Room.h"
#include "Item.h"


int main() {
#ifdef _WIN32
	SetConsoleCP(65001); // set input console codepage to utf8
	SetConsoleOutputCP(65001); // set output console codepage to utf8
#endif
	std::shared_ptr<Room> livingRoom = std::make_shared<Room>("livingroom", "livingroom");
	std::shared_ptr<Item> table = std::make_shared<Item>("table", "table");
	std::shared_ptr<Item> chest = std::make_shared<Item>("chest", "chest");
	std::shared_ptr<Item> money = std::make_shared<Item>("money", "money");

	livingRoom->addItem(table);
	table->addItem(chest);
	chest->addItem(money);
	livingRoom->addItem(livingRoom->removeItem("money").value());
	return 0;
}
#ifdef _WIN32
#include <Windows.h>
#endif

#include "Room.h"


int main() {
#ifdef _WIN32
	SetConsoleCP(65001); // set input console codepage to utf8
	SetConsoleOutputCP(65001); // set output console codepage to utf8
#endif
	std::shared_ptr<Room> livingRoom = std::make_shared<Room>("livingroom", "livingroom");
	std::shared_ptr<Room> kitchen = std::make_shared<Room>("kitchen", "kitchen");
	std::shared_ptr<Room> bedroom = std::make_shared<Room>("bedroom", "bedroom");

	livingRoom->addExit(Room::Direction::EAST, kitchen);
	kitchen->addExit(Room::Direction::WEST, livingRoom);
	kitchen->addExit(Room::Direction::WEST, livingRoom);

	livingRoom->addExit(Room::Direction::WEST, bedroom);
	bedroom->addExit(Room::Direction::EAST, livingRoom);
	return 0;
}
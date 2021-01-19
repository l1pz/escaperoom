#include "Room.h"

void Room::addExit(const Direction direction, std::shared_ptr<Room> exit) {
	assert(_exits.count(direction) != 0);
	_exits[direction] = move(exit);
}

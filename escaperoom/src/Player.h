#pragma once
#include <unordered_map>
#include <functional>
#include "base/StorageItem.h"
#include "base/Room.h"
class Player
{
private:
	std::shared_ptr<Room> currentRoom;
	StorageItem _backpack{"backpack", "backpack"};
	static std::unordered_map<std::string,
		std::function<void(const std::vector<std::string>& items)>> _actions;

public:
	void input() const;
};


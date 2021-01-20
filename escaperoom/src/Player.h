#pragma once
#include <unordered_map>
#include <functional>
#include "base/StorageItem.h"
#include "base/Room.h"
class Player
{
private:
	std::shared_ptr<Room> _currentRoom;
	StorageItem _backpack{"backpack", "backpack"};
	std::unordered_map<std::string,
		std::function<void(const std::vector<std::string>& items)>> _actions{
		{"nézd", [&](const std::vector<std::string>& items) {
			if (items.empty()) _currentRoom->check();
			else if (items.size() > 1) std::cout << "Egyszerre csak egy tárgyat tudok megnézni.";
			else {
				auto result{_currentRoom->getItem(items[0])};
				if(result.has_value()) {
					result->get()->check();
				} else {
					std::cout << "Nem látok ilyen tárgyat.";
				}
			}
		}}
	};

public:
	explicit Player(std::shared_ptr<Room> currentRoom);
	void input();
};


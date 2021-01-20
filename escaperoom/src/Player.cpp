#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include "Player.h"

std::vector<std::string> split(const std::string& str)
{
	std::vector<std::string> splitStr;
	std::istringstream iss(str);
	std::copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(splitStr));
	return splitStr;
}


void Player::_check(const std::vector<std::string>& items) const {
	if (items.empty()) _currentRoom->check();
	else if (items.size() > 1) std::cout << "Egyszerre csak egy t�rgyat tudok megn�zni.";
	else {
		auto result{ _currentRoom->getItem(items[0]) };
		if (result.has_value()) {
			result.value()->check();
		}
		else {
			std::cout << "Nem l�tok ilyen t�rgyat.";
		}
	}
}

void Player::_pickup(const std::vector<std::string>& items) {
	if (items.empty()) std::cout << "Mit vegyek fel?";
	else if (items.size() > 1) std::cout << "Egyszerre csak egy t�rgyat tudok felvenni.";
	else {
		auto result{ _currentRoom->removeItem(items[0]) };
		if (result.has_value()) {
			_backpack.addItem(result.value());
		}
		else {
			std::cout << "Nem l�tok ilyen t�rgyat.";
		}
	}
}

Player::Player(std::shared_ptr<Room> currentRoom) : _currentRoom{std::move(currentRoom)} {}

void Player::input() {
	std::string inputText;
	std::getline(std::cin, inputText);
	auto splitText{ split(inputText) };
	if (!splitText.empty()) {
		auto actionLen{ 1 };
		auto action{ splitText[0] };
		std::vector<std::string> items;
		if (splitText.size() > 1) {
			auto multiwordAction{splitText[0]};
			auto multiwordActionLen{ 1 };
			for (auto i = 1; i < splitText.size(); i++) { // multiword action support
				multiwordActionLen++;
				multiwordAction += " " + splitText[i];
				if (_actions.count(multiwordAction)) {
					action = multiwordAction;
					actionLen = multiwordActionLen;
				}
			}
			items = std::vector<std::string>(splitText.begin() + actionLen, splitText.end());
		}
		if (_actions.count(action)) {
			_actions[action](items);
			std::cout << std::endl;
		}
		else {
			std::cout << "Nincs ilyen parancs!" << std::endl;
		}
	}
	else {
		std::cout << "Adj meg valami parancsot!" << std::endl;
	}
}

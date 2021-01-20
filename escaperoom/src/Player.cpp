#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
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

std::unordered_map<std::string,
	std::function<void(const std::vector<std::string>& items)>> Player::_actions{
		{"nézd", [](std::vector<std::string> items) {std::cout << "mit nézel?"; }}
};

void Player::input() const {
	std::string inputText;
	std::getline(std::cin, inputText);
	std::cout << inputText << std::endl;
	auto splitted{ split(inputText) };
	if (splitted.size() > 0) {
		auto action{ splitted[0] };
		std::vector<std::string> items;
		if (splitted.size() > 1) {
			items = std::vector<std::string>(splitted.begin() + 1, splitted.end());
		}
		if (_actions.count(action)) {
			_actions[action](items);
		}
		else {
			std::cout << "Nincs ilyen parancs!" << std::endl;
		}
		
	}
	else {
		std::cout << "Adj meg valami parancsot!" << std::endl;
	}
}

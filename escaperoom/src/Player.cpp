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
  std::vector<std::string> splitted;
  std::istringstream iss(str);
  std::copy(std::istream_iterator<std::string>(iss),
    std::istream_iterator<std::string>(),
    std::back_inserter(splitted));
  return splitted;
}

void Player::_processInput(const std::string_view action, const std::vector<std::string>& items)
{
  
}

void Player::input() {
	std::string inputText;
  std::getline(std::cin, inputText);
  auto splitted{ split(inputText) };
  std::cout << splitted.size() << std::endl;
  if (splitted.size() > 0) {
    auto action{ splitted[0] };
    std::vector<std::string> items;
    if (splitted.size() > 1) {
      items = std::vector<std::string>(splitted.begin() + 1, splitted.end());
    }
    _processInput(action, items);
  }
  else {
    std::cout << u8"Adj meg valami parancsot!" << std::endl;
  }  
}

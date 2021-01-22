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


void Player::_check(const std::vector<std::string>& items) const
{
	if (items.empty()) _currentRoom->check();
	else if (items.size() > 1) std::cout << "Egyszerre csak egy t�rgyat tudok megn�zni.";
	else
	{
		auto result{_currentRoom->getItem(items[0])};
		if (result.has_value())
		{
			result.value()->check();
		}
		else
		{
			std::cout << "Nem l�tok ilyen t�rgyat.";
		}
	}
}

void Player::_pickup(const std::vector<std::string>& items)
{
	if (items.empty()) std::cout << "Mit vegyek fel?";
	else if (items.size() > 1) std::cout << "Egyszerre csak egy t�rgyat tudok felvenni.";
	else
	{
		auto result{_currentRoom->getItem(items[0])};
		if (result.has_value())
		{
			if (result.value()->isLiftable())
			{
				_backpack.addItem(_currentRoom->removeItem(items[0]).value(), "");
				std::cout << "Felvetted ezt: " << result.value()->name() << ".";
			}
			else
			{
				std::cout << "Ezt a t�rgyat nem tudom felvenni.";
			}
		}
		else
		{
			std::cout << "Nem l�tok ilyen t�rgyat.";
		}
	}
}

void Player::_checkBackpack(const std::vector<std::string>& items)
{
	auto backpackItems{_backpack.getItemList()};
	if (backpackItems.empty()) std::cout << "Nincs n�lam semmilyen t�rgy.";
	else
	{
		std::cout << "Ezek a t�rgyak vannak n�lam: ";
		for (const auto& bpItem : backpackItems)
		{
			std::cout << bpItem << (bpItem != backpackItems.back() ? ", " : "");
		}
	}
}

void Player::_putdown(const std::vector<std::string>& items)
{
	if (items.empty()) std::cout << "Mit tegyek le?";
	else if (items.size() > 1) std::cout << "Egyszerre csak egy t�rgyat tudok letenni.";
	else
	{
		auto result{_backpack.getItem(items[0])};
		if (result.has_value())
		{
			_currentRoom->addItem(_backpack.removeItem(items[0]).value(), "Ez van a f�ld�n: " + items[0] + ".");
			std::cout << "Letetted ezt: " << result.value()->name() << ".";
		}
		else
		{
			std::cout << "Nincs n�lam ilyen t�rgy.";
		}
	}
}

void Player::_unlock(const std::vector<std::string>& items) {
	if (items.empty()) std::cout << "Mit nyissak ki?";
	else if (items.size() > 2) std::cout << "Ennyi t�rggyal nem tudok mit kezdeni.";
	else
	{
		std::shared_ptr<Item> lockedItem;
		std::string lockedItemName;
		std::shared_ptr<Item> key;
		std::string keyName;
		for(const auto& itemName : items)
		{
			auto result{ _currentRoom->getItem(itemName) };
			if (result.has_value())
			{
				if (result.value()->isLockable())
				{
					lockedItem = result.value();
				}
				else
				{
					key = result.value();
				}
			}
			else
			{
				std::cout << "Nem l�tok ilyen t�rgyat: " << itemName;
				return;
			}
		}
		if(lockedItem)
		{
			if(lockedItem->unlock(*key))
			{
				std::cout << "Sikeres kinyitottad ezt: " << lockedItem->name();
			}
			else
			{
				std::cout << "Ezt m�r egyszer kinyittottad, vagy nem ezzel a t�rggyal nyithat�: " << key->name();
			}
		}
		else
		{
			std::cout << "Ez a t�rgy nem nyithat� ki.";
		}
	}

}

Player::Player(std::shared_ptr<Room> currentRoom) : _currentRoom{std::move(currentRoom)}
{
}

void Player::input()
{
	std::string inputText;
	std::getline(std::cin, inputText);
	auto splitText{split(inputText)};
	if (!splitText.empty())
	{
		auto actionLen{1};
		auto action{splitText[0]};
		std::vector<std::string> items;
		if (splitText.size() > 1)
		{
			auto multiwordAction{splitText[0]};
			auto multiwordActionLen{1};
			for (auto i = 1; i < splitText.size(); i++)
			{
				// multiword action support
				multiwordActionLen++;
				multiwordAction += " " + splitText[i];
				if (_actions.count(multiwordAction))
				{
					action = multiwordAction;
					actionLen = multiwordActionLen;
				}
			}
			items = std::vector<std::string>(splitText.begin() + actionLen, splitText.end());
		}
		if (_actions.count(action))
		{
			_actions[action](items);
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Nincs ilyen parancs!" << std::endl;
		}
	}
	else
	{
		std::cout << "Adj meg valami parancsot!" << std::endl;
	}
}

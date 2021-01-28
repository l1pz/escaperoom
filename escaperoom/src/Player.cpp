#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
#include <fstream>
#include <cereal/archives/binary.hpp>
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

std::optional<std::shared_ptr<Item>> Player::_getItem(const std::string& item)
{
	auto result{ _currentRoom->getItem(item) };
	if (!result) result = _backpack.getItem(item);
	return result;
}

void Player::_check(const std::vector<std::string>& items)
{
	if (items.empty()) _currentRoom->check();
	else if (items.size() > 1) std::cout << "Egyszerre csak egy t�rgyat tudok megn�zni.";
	else
	{
		auto result{_getItem(items[0])};
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
		auto fromBackpack{ false };
		auto result{_currentRoom->getItem(items[0])};
		if (!result) {
			fromBackpack = true;
			result = _backpack.getItem(items[0]);
		}
		if (result.has_value())
		{
			if (result.value()->isLiftable())
			{
				if(fromBackpack)
				{
					const auto itemList = _backpack.getItemList();
					const auto found = std::find(itemList.begin(), itemList.end(), items[0]);
					if(found == itemList.end())
					{
						_backpack.addItemInside(_backpack.removeItem(items[0]).value(), "");
					}
					else
					{
						std::cout << "Ez a t�rgy m�r n�lam van.";
						return;
					}
					
				}
				else
				{
					_backpack.addItemInside(_currentRoom->removeItem(items[0]).value(), "");
				}
				
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
			std::cout << std::endl << bpItem;
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
			_currentRoom->addItemInside(_backpack.removeItem(items[0]).value(), "Ez van a f�ld�n: " + items[0] + ".");
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
		std::shared_ptr<Item> key;
		for(const auto& itemName : items)
		{
			auto result{ _getItem(itemName) };
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
			if(key)
			{
				lockedItem->unlock(*key);
			}
			else
			{
				lockedItem->unlock();
			}
				
		}
		else
		{
			std::cout << "Ez a t�rgy nem nyithat� ki.";
		}
	}

}

void Player::_move(const std::vector<std::string>& items) const
{
	if (items.empty()) std::cout << "Mit h�zzak el?";
	else if (items.size() > 1) std::cout << "Egyszerre csak egy t�rgyat elh�zni.";
	else
	{
		auto result{ _currentRoom->getItem(items[0]) };
		if (result.has_value())
		{
			if (result.value()->isMovable())
			{
				result.value()->move();
			}
			else
			{
				std::cout << "Ezt nem tudom elh�zni.";
			}
		}
		else
		{
			std::cout << "Nem l�tok ilyen t�rgyat.";
		}
	}
}

void Player::_break(const std::vector<std::string>& items)
{
	if (items.empty()) std::cout << "Mit t�rjek �ssze?";
	else if (items.size() > 2) std::cout << "Ennyi t�rggyal nem tudok mit kezdeni.";
	else
	{
		std::shared_ptr<Item> breakableItem;
		std::shared_ptr<Item> tool;
		for (const auto& itemName : items)
		{
			auto result{ _getItem(itemName) };
			if (result.has_value())
			{
				if (result.value()->isBreakable())
				{
					breakableItem = result.value();
				}
				else
				{
					tool = result.value();
				}
			}
			else
			{
				std::cout << "Nem l�tok ilyen t�rgyat: " << itemName;
				return;
			}
		}
		if (breakableItem)
		{
			if (tool)
			{
				breakableItem->breakIt(*tool);
			}
			else
			{
				breakableItem->breakIt();
			}

		}
		else
		{
			std::cout << "Ez a t�rgy nem t�rhet� �ssze.";
		}
	}
}

void Player::_direction(const std::vector<std::string>& items, Room::Direction dir)
{
	if(!items.empty())
	{
		std::cout << "Egyszerre csak egy ir�nyba tudok menni.";
	}
	else
	{
		auto newRoom = _currentRoom->exit(dir);
		if(newRoom.has_value())
		{
			_currentRoom = newRoom.value();
			if(_currentRoom->isEscapeRoom())
			{
				std::cout << std::endl << "Gratul�lunk! Siker�lt megsz�kn�d." << std::endl;
				std::exit(0);
			}
		}

	}
}

void Player::_help()
{
	std::cout << "A haszn�lhat� parancsok: ";
	for (const auto& [command, action] : _actions)
	{
		std::cout << std::endl << command;
	}
}

void Player::_save(const std::vector<std::string>& items)
{
	std::string fileName{ "gyorsmentes.sav" };
	if (!items.empty())
	{
		if (items.size() > 1)
		{
			std::cout << "Csak egy f�jlt tudok egyszerre elmenteni.";
			return;
		}
		fileName = items[0] + ".sav";
	}
	std::ofstream outputStream(fileName, std::ios::binary);
	cereal::BinaryOutputArchive outputArchive(outputStream);
	try
	{
		outputArchive(*this);
		std::cout << "Ment�s siker�lt a " << fileName << " f�jlba.";
	}
	catch (const cereal::Exception& e)
	{
		std::cout << "Nem siker�lt a ment�s." << std::endl << e.what();
	}
	
}

void Player::_load(const std::vector<std::string>& items)
{
	std::string fileName{ "gyorsmentes.sav" };
	if (!items.empty())
	{
		if (items.size() > 1)
		{
			std::cout << "Csak egy f�jlt tudok egyszerre elmenteni.";
			return;
		}
		fileName = items[0] + ".sav";
	}
	std::ifstream inputStream(fileName, std::ios::binary);
	cereal::BinaryInputArchive inputArchive(inputStream);
	try
	{
		inputArchive(*this);
		std::cout << "Bet�lt�s siker�lt a " << fileName << " f�jlb�l.";
	}
	catch (const cereal::Exception& e)
	{
		std::cout << "Nem siker�lt a bet�lt�s." << std::endl << e.what();
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

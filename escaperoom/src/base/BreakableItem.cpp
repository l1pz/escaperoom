#include "BreakableItem.h"

#include <iostream>

void BreakableItem::_break()
{
	if (!_broken)
	{
		_broken = true;
		std::cout << brokeMessage;
	}
	else
	{
		std::cout << alreadyBrokeMessage;
	}

}

BreakableItem::BreakableItem(std::shared_ptr<Item> tool)
	: _tool{ std::move(tool) }
{
}

BreakableItem::BreakableItem(const std::string_view name, const std::string_view description, std::shared_ptr<Item> tool)
	: Item{ name, description }, _tool{ std::move(tool) }
{
}


void BreakableItem::breakIt()
{
	if (!_tool)
	{
		_break();
	}
	else
	{
		if (_broken)
		{
			std::cout << alreadyBrokeMessage;
		}
		else
		{
			std::cout << needToolMessage;
		}
	}
}

void BreakableItem::check()
{
	Item::check();
	if (_broken)
	{
		std::cout << " Össze van törve.";
	}
}

void BreakableItem::breakIt(const Item& tool)
{
	if (_tool)
	{
		if (tool == *_tool)
		{
			_break();
		}
		else
		{
			std::cout << wrongToolMessage;
		}
	}
	else
	{
		std::cout << noNeedToolMessage;
	}

}

#include "BreakableItem.h"

#include <iostream>

void BreakableItem::_break()
{
	if (!_broken)
	{
		_broken = true;
		std::cout << "Sikerült összetörni.";
	}
	else
	{
		std::cout << "Ezt már egyszer összetörtem.";
	}
}

BreakableItem::BreakableItem(const std::string_view name, const std::string_view description, std::shared_ptr<Item> tool) :
	Item{name, description}, _tool{std::move(tool)}
{
}

void BreakableItem::breakIt(const Item& tool)
{
	if (tool.name() == _tool->name())
	{
		_break();
	}
	else
	{
		std::cout << "Ezt ezzel a tárggyal nem tudom széttörni.";
	}
}

void BreakableItem::breakIt()
{
	if (!_tool)
	{
		_break();
	}
	else
	{
		std::cout << "Ennek a széttöréséhez valami tárgyra van szükségem.";
	}
}

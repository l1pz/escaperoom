#include "BreakableItem.h"

#include <iostream>

void BreakableItem::_break()
{
	if (!_broken)
	{
		_broken = true;
		std::cout << "Siker�lt �sszet�rni.";
	}
	else
	{
		std::cout << "Ezt m�r egyszer �sszet�rtem.";
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
		std::cout << "Ezt ezzel a t�rggyal nem tudom sz�tt�rni.";
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
		std::cout << "Ennek a sz�tt�r�s�hez valami t�rgyra van sz�ks�gem.";
	}
}

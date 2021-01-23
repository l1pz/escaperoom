#include "MovableItem.h"

#include <iostream>

void MovableItem::move()
{
	if (!_moved)
	{
		_moved = true;
		std::cout << "Elhúztad ezt: " << name();
		auto itr{ _items.begin() };
		while (itr != _items.end()) {
			const auto& item = (*itr).second;
			std::cout << std::endl << _itemDescriptionsMoved[item->name()];
			_room->addItem(item, _itemDescriptionsAfterMoved[item->name()]);
			itr = _items.erase(itr);
		}
	}
	else
	{
		std::cout << "Ezt a tárgyat már egyszer elhúztad.";
	}
}

MovableItem::MovableItem(const std::string_view name, const std::string_view description, std::shared_ptr<Room> room) :
	Item{ name, description }, _room{ std::move(room) }
{
}

void MovableItem::addItem(std::shared_ptr<Item> item, const std::string_view descriptionAfterMoved, const std::string_view descriptionMoved)
{
	_itemDescriptionsAfterMoved[item->name()] = descriptionAfterMoved;
	_itemDescriptionsMoved[item->name()] = descriptionMoved;
	_items[item->name()] = std::move(item);
}
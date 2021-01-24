#include "MovableItem.h"

#include <iostream>

void MovableItem::move()
{
	if (!_moved)
	{
		_moved = true;
		std::cout << movedMessage;
		auto itr{ _items.begin() };
		while (itr != _items.end()) {
			const auto& item = (*itr).second;
			std::cout << std::endl << _itemDescriptionsMoved[item->name()];
			_room->addItemInside(item, _itemDescriptionsAfterMoved[item->name()]);
			itr = _items.erase(itr);
		}
	}
	else
	{
		std::cout << alreadyMovedMessage;
	}
}

MovableItem::MovableItem(std::shared_ptr<Room> room) : _room{std::move(room)}
{
}

MovableItem::MovableItem(const std::string_view name, const std::string_view description, std::shared_ptr<Room> room) :
	Item{ name, description }, _room{ std::move(room) }
{
}

void MovableItem::addItemBehind(std::shared_ptr<Item> item, const std::string_view descriptionAfterMoved,
                          const std::string_view descriptionMoved)
{
	_itemDescriptionsAfterMoved[item->name()] = descriptionAfterMoved;
	_itemDescriptionsMoved[item->name()] = descriptionMoved;
	_items[item->name()] = std::move(item);
}
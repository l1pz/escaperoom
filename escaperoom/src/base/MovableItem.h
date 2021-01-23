#pragma once
#include "StorageItem.h"
#include "LockedItem.h"
#include "Room.h"
class MovableItem :
	public virtual Item
{
private:
	std::shared_ptr<Room> _room;
	bool _moved{ false };
	std::unordered_map<std::string, std::shared_ptr<Item>> _items{};
	std::unordered_map<std::string, std::string> _itemDescriptionsAfterMoved{};
	std::unordered_map<std::string, std::string> _itemDescriptionsMoved{};

public:
	explicit MovableItem(std::shared_ptr<Room> room);
	MovableItem(std::string_view name, std::string_view description, std::shared_ptr<Room> room);
	void addItem(std::shared_ptr<Item> item, std::string_view descriptionAfterMoved, std::string_view descriptionMoved) override;
	void move() override;
	bool isMovable() override { return true; }
};


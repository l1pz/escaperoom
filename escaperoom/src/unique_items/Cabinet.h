#pragma once
#include "../base/LockedItem.h"
#include "../base/StorageItem.h"
#include "../base/MovableItem.h"
class Cabinet :
	public MovableItem,
	public LockedItem,
	public StorageItem
{
public:
	Cabinet(std::string_view name, std::string_view description, std::shared_ptr<Room> room, std::shared_ptr<Item> key);
	Cabinet(std::string_view name, std::string_view description, std::shared_ptr<Room> room);
	void check() override;
};


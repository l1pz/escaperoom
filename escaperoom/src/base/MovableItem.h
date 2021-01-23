#pragma once
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/unordered_map.hpp>
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
	MovableItem() = default;
	explicit MovableItem(std::shared_ptr<Room> room);
	MovableItem(std::string_view name, std::string_view description, std::shared_ptr<Room> room);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _room, _moved, _items, _itemDescriptionsAfterMoved, _itemDescriptionsMoved);
	}
	void addItem(std::shared_ptr<Item> item, std::string_view descriptionAfterMoved, std::string_view descriptionMoved) override;
	void move() override;
	bool isMovable() override { return true; }
};

CEREAL_REGISTER_TYPE(MovableItem);
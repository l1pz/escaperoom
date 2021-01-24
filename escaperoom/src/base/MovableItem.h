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
	std::string movedMessage{ "Sikerült elhúzni." };
	std::string alreadyMovedMessage{ "Ezt a tárgyat már egyszer elhúztad." };

protected: 
	MovableItem() = default;
	explicit MovableItem(std::shared_ptr<Room> room);
public:
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _room, _moved, _items, _itemDescriptionsAfterMoved,
		   _itemDescriptionsMoved);
	}
	void addItemBehind(std::shared_ptr<Item> item, std::string_view descriptionAfterMoved,
	             std::string_view descriptionMoved) override;
	void move() override;
	bool isMovable() override { return true; }
};

CEREAL_REGISTER_TYPE(MovableItem);
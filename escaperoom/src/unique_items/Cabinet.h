#pragma once
#include "../base/LockedStorageItem.h"
#include "../base/MovableItem.h"
#include <cereal/types/polymorphic.hpp>
class Cabinet :
	public MovableItem,
	public LockedStorageItem
{
public:
	Cabinet() = default;
	Cabinet(std::string_view name, std::string_view description, std::shared_ptr<Room> room, std::shared_ptr<Item> key);
	Cabinet(std::string_view name, std::string_view description, std::shared_ptr<Room> room);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<MovableItem>(this), cereal::base_class<LockedStorageItem>(this));
	}
};

CEREAL_REGISTER_TYPE(Cabinet);


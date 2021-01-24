#pragma once
#include "../base/LiftableItem.h"
#include "../base/LockedStorageItem.h"
class Box :
	public LiftableItem,
	public LockedStorageItem
{
public:
	Box() = default;
	Box(std::string_view name, std::string_view description, std::shared_ptr<Item> key);
	Box(std::string_view name, std::string_view description);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<LiftableItem>(this), cereal::base_class<LockedStorageItem>(this));
	}
	std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
};

CEREAL_REGISTER_TYPE(Box);
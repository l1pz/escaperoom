#pragma once
#include "Item.h"
#include <memory>
#include <cereal/types/polymorphic.hpp>

class LiftableItem :
	public virtual Item
{
public:
	std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
	bool isLiftable() override { return true; }
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this));
	}
};

CEREAL_REGISTER_TYPE(LiftableItem);

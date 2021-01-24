#pragma once
#include "../base/LiftableItem.h"
class Key :
	public LiftableItem
{
public:
	using LiftableItem::LiftableItem;
	Key() = default;
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<LiftableItem>(this));
	}
};

CEREAL_REGISTER_TYPE(Key);



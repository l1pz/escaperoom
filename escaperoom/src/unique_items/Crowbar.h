#pragma once
#include "../base/LiftableItem.h"

class Crowbar :
	public LiftableItem
{
public:
	Crowbar() = default;
	using LiftableItem::LiftableItem;
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<LiftableItem>(this));
	}
};

CEREAL_REGISTER_TYPE(Crowbar)
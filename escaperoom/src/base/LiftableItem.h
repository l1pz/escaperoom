#pragma once
#include "Item.h"
#include <memory>

class LiftableItem :
	public Item
{
public:
	using Item::Item;
	std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
	bool isLiftable() override { return true; }
};

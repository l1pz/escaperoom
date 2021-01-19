#pragma once
#include "Item.h"
#include <memory>
class LiftableItem :
	public Item,
	public std::enable_shared_from_this<LiftableItem>
{
public:
	using Item::Item;
	std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
};


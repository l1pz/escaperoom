#pragma once
#include "Item.h"

class BreakableItem :
	public virtual Item
{
private:
	bool _broken{false};
	std::shared_ptr<Item> _tool;

private:
	void _break();

public:
	BreakableItem() = default;
	using Item::Item;
	BreakableItem(std::string_view name, std::string_view description, std::shared_ptr<Item> tool);
	void breakIt(const Item & tool) override; // can't use break since it's a reserved keyword
	void breakIt() override;
	bool isBreakable() override { return true; }
};


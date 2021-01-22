#pragma once
#include "Item.h"

class StorageItem :
	public virtual Item
{
protected:
	std::unordered_map<std::string, std::shared_ptr<Item>> _items;
	std::unordered_map<std::string, std::string> _itemDescriptions;
public:
	using Item::Item;
	void check() override;
	std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
	std::optional<std::shared_ptr<Item>> getItem(const std::string& name) override;
	void addItem(std::shared_ptr<Item> item, std::string_view description) override;
	std::vector<std::string> getItemList() override;
	bool isStorage() override { return true; }
};

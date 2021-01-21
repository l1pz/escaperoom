#pragma once
#include "Item.h"
class StorageItem :
	public Item
{
protected:
  std::unordered_map<std::string, std::shared_ptr<Item>> _items;
public:
  using Item::Item;
  std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
  std::optional<std::shared_ptr<Item>> getItem(const std::string& name) override;
  void addItem(std::shared_ptr<Item> item) override;
  std::vector<std::string> getItemList() override;
};


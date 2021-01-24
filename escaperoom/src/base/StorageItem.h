#pragma once
#include <memory>
#include <unordered_map>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/string.hpp>
#include "Item.h"

class StorageItem :
	public virtual Item
{
protected:
	std::unordered_map<std::string, std::shared_ptr<Item>> _items{};
	std::unordered_map<std::string, std::string> _itemDescriptions{};

protected:
	void checkContainedItems();

public:
	using Item::Item;
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _items, _itemDescriptions);
	}
	StorageItem() = default;
	void check() override;
	std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) override;
	std::optional<std::shared_ptr<Item>> getItem(const std::string& name) override;
	void addItemInside(std::shared_ptr<Item> item, std::string_view description) override;
	std::vector<std::string> getItemList() override;
	bool isStorage() override { return true; }
};

CEREAL_REGISTER_TYPE(StorageItem);

#pragma once
#include "Entity.h"
class Item :
    public Entity,
    public std::enable_shared_from_this<Item>
{
private:
  std::unordered_map<std::string, std::shared_ptr<Item>> _items;
  std::optional<std::shared_ptr<Item>> _key;
  bool _locked{ false };
public:
  using Entity::Entity;
  Item(const std::string_view name, const std::string_view description, std::optional<std::shared_ptr<Item>> key);
  std::optional<std::shared_ptr<Item>> removeItem(const std::string& name);
  void addItem(std::shared_ptr<Item> item);
  void unlock(const Item& key);

  inline bool operator==(const Item& rhs) const {return this->name() == rhs.name();}
};


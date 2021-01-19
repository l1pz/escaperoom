#pragma once
#include "Entity.h"
class Item :
    public Entity
{
private:
  std::unordered_map<std::string, std::shared_ptr<Item>> _items;
public:
  using Entity::Entity;
  std::optional<std::shared_ptr<Item>> removeItem(const std::string& name);
  void addItem(std::shared_ptr<Item> item);
};


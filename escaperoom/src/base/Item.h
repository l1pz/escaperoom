#pragma once
#include "Entity.h"
class Item :
    public Entity,
    public std::enable_shared_from_this<Item>
{
public:
  using Entity::Entity;
  bool operator==(const Item& rhs) const {return this->name() == rhs.name();}
  virtual void addItem(std::shared_ptr<Item> item) {}
  virtual std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) { return std::nullopt; }
  virtual std::optional<std::shared_ptr<Item>> getItem(const std::string& name);
  virtual void unlock(const Item& key) {}
};


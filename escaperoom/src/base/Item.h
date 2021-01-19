#pragma once
#include "Entity.h"
class Item :
    public Entity
{
public:
  using Entity::Entity;
  inline bool operator==(const Item& rhs) const {return this->name() == rhs.name();}
  virtual void addItem(std::shared_ptr<Item> item) {};
  virtual std::optional<std::shared_ptr<Item>> removeItem(const std::string& name) { return std::nullopt; };
  virtual void unlock(const Item& key) {};
};


#pragma once
#include <cassert>
#include "Entity.h"
#include "Item.h"
class Room :
    public Entity
{

public:
  enum class Direction {
    NORTH, EAST, SOUTH, WEST
  };

private:
  std::unordered_map<std::string, std::shared_ptr<Item>> _items;
  std::unordered_map<Direction, std::shared_ptr<Room>> _exits;

public:
  using Entity::Entity;
  void addExit(const Direction direction, std::shared_ptr<Room> exit);
  void addItem(std::shared_ptr<Item> item);
  std::optional<std::shared_ptr<Item>> removeItem(const std::string& name);
  std::optional<std::shared_ptr<Item>> getItem(const std::string& name);
  
};


#pragma once
#include "StorageItem.h"
class Room :
    public StorageItem
{

public:
  enum class Direction {
    NORTH, EAST, SOUTH, WEST
  };

private:
  std::unordered_map<Direction, std::shared_ptr<Room>> _exits;

public:
  using StorageItem::StorageItem;
  void addExit(Direction direction, std::shared_ptr<Room> exit);
  // we need getItem function because we have to make sure room doesn't return itself like the rest of the items
  std::optional<std::shared_ptr<Item>> getItem(const std::string& name) override; 
};


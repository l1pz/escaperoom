#pragma once
#include <cassert>
#include "Entity.h"
class Room :
    public Entity
{

public:
  enum class Direction {
    NORTH, EAST, SOUTH, WEST
  };

private:
  std::unordered_map<Direction, std::shared_ptr<Room>> _exits;

public:
  using Entity::Entity;
  void addExit(const Direction direction, std::shared_ptr<Room> exit);
};


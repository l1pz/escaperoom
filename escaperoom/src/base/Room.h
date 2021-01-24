#pragma once
#include "StorageItem.h"
#include <functional>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
class Room :
	public StorageItem
{
public:
	enum class Direction
	{
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

	struct Exit
	{
		Direction direction{};
		std::shared_ptr<Room> room{};
		std::function<bool()> isVisible{ []() {return true; } };
	};

private:
	std::unordered_map<Direction, Exit> _exits;
	static std::unordered_map<Direction, std::string> _directionToString;

public:
	Room() = default;
	Room(const std::string& name, const std::string& description);
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<StorageItem>(this), _exits);
	}
	void addExit(Exit exit);
	std::optional<std::shared_ptr<Room>> direction(Direction dir);
	void check() override;
	// we need getItem function because we have to make sure room doesn't return itself like the rest of the items
	std::optional<std::shared_ptr<Item>> getItem(const std::string& name) override;
	static std::string directionToString(Direction dir);
};

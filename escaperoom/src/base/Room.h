#pragma once
#include "StorageItem.h"
#include "LockedItem.h"
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
		std::shared_ptr<Item> lock;
		std::string lockedMessage{ "Ez a kij�rat be van z�rva" };
		template <class Archive>
		void serialize(Archive& ar)
		{
			ar(direction, room, lock, lockedMessage);
		}
	};

private:
	std::unordered_map<Direction, Exit> _exits;
	static std::unordered_map<Direction, std::string> _directionToString;
	bool _escapeRoom;

public:
	Room() = default;
	Room(std::string_view name, std::string_view description);
	Room(std::string_view name, std::string_view description, bool escapeRoom);
	
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::base_class<StorageItem>(this), _exits);
	}
	void addExit(Exit exit);
	std::optional<std::shared_ptr<Room>> exit(Direction dir);
	void check() override;
	// we need getItem function because we have to make sure room doesn't return itself like the rest of the items
	std::optional<std::shared_ptr<Item>> getItem(const std::string& name) override;
	static std::string directionToString(Direction dir);
	bool isEscapeRoom() const;
};

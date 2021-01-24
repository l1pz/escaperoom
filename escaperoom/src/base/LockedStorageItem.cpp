#include "LockedStorageItem.h";

LockedStorageItem::LockedStorageItem(std::shared_ptr<Item> key)
	: LockedItem{std::move(key)}
{
}

void LockedStorageItem::check()
{
	if (isUnlocked())
	{
		StorageItem::check();
	}
	else
	{
		LockedItem::check();
	}
}

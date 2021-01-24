#include "LockedStorageItem.h";

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

std::optional<std::shared_ptr<Item>> LockedStorageItem::removeItem(const std::string& name)
{
	if(isUnlocked())
	{
		return StorageItem::removeItem(name);
	}
	return LockedItem::removeItem(name);
}

std::optional<std::shared_ptr<Item>> LockedStorageItem::getItem(const std::string& name)
{
	if (isUnlocked())
	{
		return StorageItem::getItem(name);
	}
	return LockedItem::getItem(name);
}

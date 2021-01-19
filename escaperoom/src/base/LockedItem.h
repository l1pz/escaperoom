#pragma once
#include <functional>
#include "Item.h"
class LockedItem :
    public Item
{
private:
  std::optional<std::shared_ptr<Item>> _key;
  bool _unlocked{ false };
  std::function<void()> _callback;
public:
  LockedItem(const std::string_view name, const std::string_view description, std::function<void()> callback);
  void unlock(const Item& key) override;
};


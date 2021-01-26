#pragma once
#include <functional>
#include "Item.h"
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/memory.hpp>

class BreakableItem :
	public virtual Item
{
private:
	bool _broken{ false };
	std::shared_ptr<Item> _tool;
	void _break();

public:
	BreakableItem() = default;
	explicit BreakableItem(std::shared_ptr<Item> tool);
	BreakableItem(std::string_view name, std::string_view description, std::shared_ptr<Item> tool);
	using Item::Item;

public:
	std::string brokeMessage{ "Sikerült összetörni." };
	std::string alreadyBrokeMessage{ "Ezt már egyszer összetörtem." };
	std::string needToolMessage{ "Ennek az összetöréséhez valami tárgyra van szükségem." };
	std::string wrongToolMessage{ "Ezt ezzel a tárggyal nem tudom összetörni." };
	std::string noNeedToolMessage{ "Ezt a kezemmel is szét tudom törni. Nem kell hozzá más tárgy." };

public:
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _broken, _tool, brokeMessage, alreadyBrokeMessage, needToolMessage, wrongToolMessage, noNeedToolMessage);
	}
	bool isBroken() const { return _broken; }
	void check() override;
	void breakIt(const Item& tool) override;
	void breakIt() override;
	bool isBreakable() override { return true; }
};
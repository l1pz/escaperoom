#pragma once
#include <memory>
#include "Item.h"

#include <cereal/types/polymorphic.hpp>
#include <cereal/types/memory.hpp>


class BreakableItem :
	public virtual Item
{
private:
	bool _broken{false};
	std::shared_ptr<Item> _tool;

public:
	std::string brokeMessage{ "Sikerült összetörni." };
	std::string alreadyBrokeMessage{ "Ezt már egyszer összetörtem." };
	std::string wrongToolMessage{ "Ezt ezzel a tárggyal nem tudom széttörni." };
	std::string needToolMessage{ "Ennek a széttöréséhez valami tárgyra van szükségem." };

private:
	void _break();

protected:
	BreakableItem() = default;
	BreakableItem(std::shared_ptr<Item> tool);

public:
	template <class Archive>
	void serialize(Archive& ar)
	{
		ar(cereal::virtual_base_class<Item>(this), _broken, _tool);
	}
	
	void breakIt(const Item & tool) override; // can't use break since it's a reserved keyword
	void breakIt() override;
	bool isBreakable() override { return true; }
};


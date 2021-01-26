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
	std::string brokeMessage{ "Siker�lt �sszet�rni." };
	std::string alreadyBrokeMessage{ "Ezt m�r egyszer �sszet�rtem." };
	std::string needToolMessage{ "Ennek az �sszet�r�s�hez valami t�rgyra van sz�ks�gem." };
	std::string wrongToolMessage{ "Ezt ezzel a t�rggyal nem tudom �sszet�rni." };
	std::string noNeedToolMessage{ "Ezt a kezemmel is sz�t tudom t�rni. Nem kell hozz� m�s t�rgy." };

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
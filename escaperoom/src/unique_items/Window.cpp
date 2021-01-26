#include "Window.h"

Window::Window(const std::string_view name, const std::string_view description)
	: Item{ name, description }
{
}

Window::Window(const std::string_view name, const std::string_view description, std::shared_ptr<Item> key, std::shared_ptr<Item> tool)
	: Item{ name, description }, BreakableItem{ std::move(tool) }, LockedItem{std::move(key)}
{
}

void Window::check()
{
	if(isBroken())
	{
		BreakableItem::check();
	}
	else
	{
		LockedItem::check();
	}
}

bool Window::exitCondition()
{
	return isUnlocked() || isBroken();
}

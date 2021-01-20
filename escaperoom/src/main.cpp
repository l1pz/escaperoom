#include <locale>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "base/Room.h"
#include "base/StorageItem.h"
#include "base/LiftableItem.h"
#include "Player.h"

int main() {
	std::locale::global(std::locale("hu"));
#ifdef _WIN32
	SetConsoleCP(28592);
	SetConsoleOutputCP(28592);
#endif
	auto livingRoom = std::make_shared<Room>("nappali", "Egy nappaliban �llok. El�ttem van egy asztal.");
	auto table = std::make_shared<StorageItem>("asztal", "Az asztalon egy l�dika tal�lhat�.");
	auto chest = std::make_shared<StorageItem>("l�dika", "Az l�dik�ban egy kis p�nz lapul.");
	const auto money = std::make_shared<LiftableItem>("p�nz", "A p�nz kiss� gy�r�tt.");

	livingRoom->addItem(table);
	table->addItem(chest);
	chest->addItem(money);
	
	Player p{livingRoom};
	while (true) p.input();
}
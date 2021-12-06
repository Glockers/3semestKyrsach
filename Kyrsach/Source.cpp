#include "Database.h"
#include "Guest.h"
#include <Windows.h>
#include "SmartMenu.h"
Database db;
#define TYPE_METHOD void(SmartMenu::*)()



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<TYPE_METHOD> pFuncArray = { &SmartMenu::Guest::log_in_account ,&SmartMenu::Guest::reg_an_account, EXIT_FUNCTION};
	string menu_description = "������� ����\n\n1) �����������\n2) �����������\n3) ����� �� �������\n";
	SmartMenu::createMenu(menu_description, pFuncArray);
	return 0;
}
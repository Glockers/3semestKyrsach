#pragma once
#include "Guest.h"
#define EXIT_FUNCTION nullptr

class SmartMenu :
	public Guest
{
public:
	template <class T, class T2>
	static void createMenu(string& menu_description, vector<T2(T::*)()>& pMethod);

	template <class T>
	static void createMenu(string& menu_description, vector<T(*)()>& pMethod);
};

template <class T, class T2>
static void SmartMenu::createMenu(string& menu_description, vector<T2(T::*)()>& pMethod) {
	int lengthArray = (int)pMethod.size() + 1;
	int borderLimit = lengthArray - lengthArray + 1;
	while (true) {
		system("cls");
		cout << menu_description;
		cout << "¬ведите номер команды (-1 означает выход): ";
		size_t command = Security::securityInt();
		if (command == -1) {
			break;
		}
		else if (command < borderLimit || command >= lengthArray) {
			cout << "¬ведите значение от " << borderLimit << " до " << lengthArray - 1 << endl;
			system("pause");
		}
		else if (pMethod[command - 1] == EXIT_FUNCTION) {
			break;
		}
		else {
			T object;
			(object.*pMethod[(command)-1])();
		}
	}
}

template <class T>
static void SmartMenu::createMenu(string& menu_description, vector<T(*)()>& pMethod) {
	int lengthArray = (int)pMethod.size() + 1;
	int borderLimit = lengthArray - lengthArray + 1;
	while (true) {
		system("cls");
		cout << menu_description;
		cout << "¬ведите номер команды (-1 означает выход): ";
		size_t command = Security::securityInt();
		if (command == -1) {
			break;
		}
		else if (command < borderLimit || command >= lengthArray) {
			cout << "¬ведите значение от " << borderLimit << " до " << lengthArray - 1 << endl;
			system("pause");
		}
		else if (pMethod[command - 1] == EXIT_FUNCTION) {
			break;
		}
		else {
			pMethod[(command)-1]();
		}
	}
}
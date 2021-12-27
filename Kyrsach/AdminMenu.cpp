#include "AdminMenu.h"

// Отображение главного меню
void AdminMenu::showHeader() {
	system("cls");
	cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ / АДМИНА_____________\n\n" << endl;
}
void AdminMenu::showPunktMenu() {
	cout << "0)Перейти в панель администратора\n";
	ClientMenu::showPunktMenu();
}
void AdminMenu::showPanelAdmin() {
	while (true)
	{
		system("cls");
		cout << "_____________________ГЛАВНОЕ МЕНЮ АДМИНИСТРАТОРА_____________\n\n" << endl;

		cout << "Главное меню\n\n";
		cout << "1) Отобразить список\n";
		cout << "2) Добавить данные\n";
		cout << "3) Редактировать данные\n";
		cout << "4) Удалить данные\n";
		cout << "5) Соритровка данных\n";
		cout << "6) Войти в пользовательский режим\n";
		cout << "7) Выйти из cистемы\n";
		cout << "Введите номер команды: ";
		int command = Security::securityInt();
		if (command == 1) {
			//AdminMenu::ShowMenuData();
		}
		else if (command == 2) {
			//AdminMenu::ShowMenuAdd();
		}
		else if (command == 3)
		{
			//AdminMenu::ShowMenuEdit();
		}
		else if (command == 4)
		{
			//AdminMenu::ShowMenuDelete();
		}
		else if (command == 5)
		{
			//AdminMenu::ShowMenuSort();
		}
		else if (command == 6)
		{
			break;
		}
		else if (command == 7) // Выход из аккаунта
		{
			system("cls");
			cout << "Вы вышли из системы\n";
			exit(1);
		}

	}
}
void AdminMenu::selectCommand() {
	//this->showHeader();
	
	while (true) {
		int command = Security::securityInt();
		if (command == 0) {
			showPanelAdmin();
		}
		else if(command > 0){
			break;
		}
	}
	ClientMenu::selectCommand();
}
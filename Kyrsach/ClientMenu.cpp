#include "ClientMenu.h"

// Отображение главного меню
void ClientMenu::showHeader() {
	system("cls");
	cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ_____________\n\n" << endl;
}
void ClientMenu::showPunktMenu() {
	cout << "1)Купить билет\n";
	cout << "2)Посмотреть свободные места на фильм\n";
	cout << "3)Мои билеты\n";
	cout << "4)Выйти из аккаунта\n";
	cout << ">>> ";
}
void ClientMenu::selectCommand() {
	while (true) {
		system("cls");
		this->showHeader();
		this->showPunktMenu();
		int command = Security::securityInt();
		if (command == 1) {
			/*buyTicket();*/
			system("pause");
		}
		else if (command == 2) {
			//Client::show_Free_Place_On_Film();
			system("pause");

		}
		else if (command == 3) {
			//Client::show_my_Tickets();
		}
		else if (command == 4) {
			break;
		}
		
	}
}
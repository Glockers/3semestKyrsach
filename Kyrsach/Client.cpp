#include "Client.h"


void Client::showPunktMenu() {
	cout << "1)Купить билет\n";
	cout << "2)Посмотреть свободные места на фильм\n";
	cout << "3)Мои билеты\n";
	cout << "4)Выйти из аккаунта\n";
	cout << ">>> ";
}

void Client::showMenu() {
	while (true) {
		system("cls");
		cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ_____________\n\n" << endl;
		this->showPunktMenu();
		int command = Security::securityInt();
		if (command == 1) {
			//buyTicket();
		}
		else if (command == 2) {
			//Client::show_Free_Place_On_Film();
		}
		else if (command == 3) {
			//Client::show_my_Tickets();
		}
		else if (command == 4) {
			break;
		}
	}
}

Client::Client() {
	this->set_role(USER);
}


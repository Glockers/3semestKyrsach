#include "Client.h"


void Client::showPunktMenu() {
	cout << "1)������ �����\n";
	cout << "2)���������� ��������� ����� �� �����\n";
	cout << "3)��� ������\n";
	cout << "4)����� �� ��������\n";
	cout << ">>> ";
}

void Client::showMenu() {
	while (true) {
		system("cls");
		cout << "_____________________������� ���� ������������_____________\n\n" << endl;
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


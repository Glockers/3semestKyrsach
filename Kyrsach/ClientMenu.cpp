#include "ClientMenu.h"

// ����������� �������� ����
void ClientMenu::showHeader() {
	system("cls");
	cout << "_____________________������� ���� ������������_____________\n\n" << endl;
}
void ClientMenu::showPunktMenu() {
	cout << "1)������ �����\n";
	cout << "2)���������� ��������� ����� �� �����\n";
	cout << "3)��� ������\n";
	cout << "4)����� �� ��������\n";
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
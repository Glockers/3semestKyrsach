#include "AdminMenu.h"

// ����������� �������� ����
void AdminMenu::showHeader() {
	system("cls");
	cout << "_____________________������� ���� ������������ / ������_____________\n\n" << endl;
}
void AdminMenu::showPunktMenu() {
	cout << "0)������� � ������ ��������������\n";
	ClientMenu::showPunktMenu();
}
void AdminMenu::showPanelAdmin() {
	while (true)
	{
		system("cls");
		cout << "_____________________������� ���� ��������������_____________\n\n" << endl;

		cout << "������� ����\n\n";
		cout << "1) ���������� ������\n";
		cout << "2) �������� ������\n";
		cout << "3) ������������� ������\n";
		cout << "4) ������� ������\n";
		cout << "5) ���������� ������\n";
		cout << "6) ����� � ���������������� �����\n";
		cout << "7) ����� �� c������\n";
		cout << "������� ����� �������: ";
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
		else if (command == 7) // ����� �� ��������
		{
			system("cls");
			cout << "�� ����� �� �������\n";
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
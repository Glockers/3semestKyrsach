#include "Guest.h"

// �����������
void Guest::log_in_account() {
	int countTryInputPassword = 3;

	while (countTryInputPassword > 0) {
		SmartPointer<User> usersFromDataBase = new User;
		User user;

		system("cls");
		cout << "�����������\n\n" << endl;
		rewind(stdin);
		cout << "������� Login: ";
		user.set_login(Security::securityString());
		rewind(stdin);
		cout << "������� Password: ";
		string psw;
		Security::InputPassword(psw);


		// ��������
		db.findOne(fileUser, &User::get_login, user.get_login(), user);
		if (psw == "" || psw != user.get_password()) {
			countTryInputPassword--;
			cout << "�� ����� �������� ����� ��� ������! � ��� �������� " << countTryInputPassword << " �������." << endl;
			if (countTryInputPassword == 0) {
				cout << "�� ��������� ����� ������� :(" << endl;
				cout << "�� ���� �������������� �� 5 ������\n" << endl;
				Sleep(5000);
			}
			system("pause");
		}

		else if (psw == user.get_password()) {

			cout << "�� ����� ��� " << user.get_role() << endl;
			/*session.login = user.get_login();
			session.password = user.get_password();
			session.role = user.get_role();*/


			system("pause");
			system("cls");

			showMenu(user.get_role());



		/*	session.login = "";
			session.password = "";
			session.role;*/
			cout << "�� ����� �� ��������\n";
			system("pause");
			break;
		}

	}
}
void Guest::showMenu(Role roleFromDb) {
	/*Admin admin;
	Client client;

	vector<Client*> roleList = { &admin, &client };
	for (int i = 0; i < roleList.size(); i++)
	{
		if (roleList[i]->get_role() == roleFromDb) {
			IShowMainMenu* ptr;
			ptr = roleList[i];
			ptr->showMenu();
			break;
		}

	}*/
}

// �����������
void Guest::reg_an_account() {
	system("cls");
	SmartPointer<User> users = new User;
	User user;
	cout << "�����������\n\n";
	cout << "������� ��� �������� �����: ";
	string newMyLogin = Security::securityString();
	rewind(stdin);
	user.set_login(newMyLogin);
	while (true) {
		system("cls");
		cout << "������� �������� ������: ";
		string newMyPassword;
		Security::InputPassword(newMyPassword);

		if (newMyPassword.length() < 6) {
			cout << "������� �������� ������. ������� ��� ���\n";
			newMyPassword = "";
		}
		else if (newMyPassword.size() >= 6) {
			string rptPassword;
			cout << "��������� ������: ";
			Security::InputPassword(rptPassword);
			if (newMyPassword == rptPassword) {
				user.set_password(newMyPassword);
				break;
			}
			else {
				cout << "������ �� ���������\n";
				newMyPassword = "";
			}
		}
		system("pause");
	}

	db.findOne(fileUser, &User::get_login, user.get_login(), *users);
	if (users->get_login() != user.get_login() && users->get_password() != user.get_password()) {
		db.getUnicSeed(fileUser, user);
		if (user.get_id() == 0) {
			user.set_role(ADMIN);
		}
		else {
			user.set_role(USER);
		}

		db.create(fileUser, user);
		system("cls");
		cout << "�� ������������������. ����� ��� ����������� ������ ������� � ������ �������.\n";
	}
	else {
		cout << "������� � ����� ������� ��� ����������!\n";
	}

	system("pause");
	/*system("cls");
	SmartPointer<User> users = new User;
	User user;

	cout << "�����������\n\n";
	cout << "������� ��� �������� �����: ";
	string newMyLogin = Security::securityString();

	rewind(stdin);
	user.set_login(newMyLogin);
	while (true) {
		system("cls");
		cout << "������� �������� ������: ";
		string newMyPassword;
		Security::InputPassword(newMyPassword);

		if (newMyPassword.length() < 6) {
			cout << "������� �������� ������. ������� ��� ���\n";
			newMyPassword = "";
		}
		else if (newMyPassword.size() >= 6) {
			string rptPassword;
			cout << "��������� ������: ";
			Security::InputPassword(rptPassword);
			if (newMyPassword == rptPassword) {
				user.set_password(newMyPassword);
				break;
			}
			else {
				cout << "������ �� ���������\n";
				newMyPassword = "";
			}
		}
		system("pause");
	}


	file.findOne(fileUser, &User::get_login, user.get_login(), *users);
	if (users->get_login() != user.get_login() && users->get_password() != user.get_password()) {
		file.getUnicSeed(fileUser, user);
		if (user.get_id() == 0) {
			user.set_role(ADMIN);
		}
		else {
			user.set_role(USER);
		}

		file.create(fileUser, user);
		system("cls");
		cout << "�� ������������������. ����� ��� ����������� ������ ������� � ������ �������.\n";
	}
	else {
		cout << "������� � ����� ������� ��� ����������!\n";
	}

	system("pause");*/

}
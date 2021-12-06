#include "Guest.h"

// Авторизация
void Guest::log_in_account() {
	int countTryInputPassword = 3;

	while (countTryInputPassword > 0) {
		SmartPointer<User> usersFromDataBase = new User;
		User user;

		system("cls");
		cout << "Авторизация\n\n" << endl;
		rewind(stdin);
		cout << "Введите Login: ";
		user.set_login(Security::securityString());
		rewind(stdin);
		cout << "Введите Password: ";
		string psw;
		Security::InputPassword(psw);


		// Проверка
		db.findOne(fileUser, &User::get_login, user.get_login(), user);
		if (psw == "" || psw != user.get_password()) {
			countTryInputPassword--;
			cout << "Вы ввели неверный логин или пароль! У вас осталось " << countTryInputPassword << " попытки." << endl;
			if (countTryInputPassword == 0) {
				cout << "Вы исчерпали лимит попыток :(" << endl;
				cout << "Вы были заблокированны на 5 секунд\n" << endl;
				Sleep(5000);
			}
			system("pause");
		}

		else if (psw == user.get_password()) {

			cout << "Вы вошли как " << user.get_role() << endl;
			/*session.login = user.get_login();
			session.password = user.get_password();
			session.role = user.get_role();*/


			system("pause");
			system("cls");

			showMenu(user.get_role());



		/*	session.login = "";
			session.password = "";
			session.role;*/
			cout << "Вы вышли из аккаунта\n";
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

// Регистрация
void Guest::reg_an_account() {
	system("cls");
	SmartPointer<User> users = new User;
	User user;
	cout << "РЕГИСТРАЦИЯ\n\n";
	cout << "Введите ваш будующий логин: ";
	string newMyLogin = Security::securityString();
	rewind(stdin);
	user.set_login(newMyLogin);
	while (true) {
		system("cls");
		cout << "Введите надежный пароль: ";
		string newMyPassword;
		Security::InputPassword(newMyPassword);

		if (newMyPassword.length() < 6) {
			cout << "Слишком короткий пароль. Введите еще раз\n";
			newMyPassword = "";
		}
		else if (newMyPassword.size() >= 6) {
			string rptPassword;
			cout << "Повторите пароль: ";
			Security::InputPassword(rptPassword);
			if (newMyPassword == rptPassword) {
				user.set_password(newMyPassword);
				break;
			}
			else {
				cout << "Пароли не совпадают\n";
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
		cout << "Вы зарегистрировались. Далее для продолжения работы войдите в личный кабинет.\n";
	}
	else {
		cout << "Аккаунт с таким логином уже существует!\n";
	}

	system("pause");
	/*system("cls");
	SmartPointer<User> users = new User;
	User user;

	cout << "РЕГИСТРАЦИЯ\n\n";
	cout << "Введите ваш будующий логин: ";
	string newMyLogin = Security::securityString();

	rewind(stdin);
	user.set_login(newMyLogin);
	while (true) {
		system("cls");
		cout << "Введите надежный пароль: ";
		string newMyPassword;
		Security::InputPassword(newMyPassword);

		if (newMyPassword.length() < 6) {
			cout << "Слишком короткий пароль. Введите еще раз\n";
			newMyPassword = "";
		}
		else if (newMyPassword.size() >= 6) {
			string rptPassword;
			cout << "Повторите пароль: ";
			Security::InputPassword(rptPassword);
			if (newMyPassword == rptPassword) {
				user.set_password(newMyPassword);
				break;
			}
			else {
				cout << "Пароли не совпадают\n";
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
		cout << "Вы зарегистрировались. Далее для продолжения работы войдите в личный кабинет.\n";
	}
	else {
		cout << "Аккаунт с таким логином уже существует!\n";
	}

	system("pause");*/

}
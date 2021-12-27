#include "Admin.h"



Admin::Admin() {
	this->set_role(ADMIN);
};

void Admin::add_Film() {

	/*Film film;
	film.fillData();

	string nameFile = film.get_nameFilm() + ".txt";
	if (file.is_file_exist(nameFile)) {
		cout << "����� ����� ��� ����������!\n";
		return;
	};

	ofstream inFile(nameFile);
	for (int i = 1; i <= film.get_place(); i++) {
		inFile << i << "\n" << false << "\n" << "NONE\n";
	}
	inFile.close();

	file.create(fileFilms, film);
	cout << "����� ������� ��������\n";*/

};

void Admin::createUser() {
	/*system("cls");
	User user;
	cout << "�������� �������� ������������\n\n";

	cout << "������� ����� ������������: ";
	string founded_User = Security::securityString();
	rewind(stdin);

	bool isResultFound = file.findOne(fileUser, &User::get_login, founded_User, user);
	if (isResultFound) {
		cout << "����� ����� ����, ���������� ������.\n";
		return;
	}

	cout << "������� ������ ������������: ";
	string createdPassword;
	Security::InputPassword(createdPassword);

	cout << "�������� ���� ������������: \n";
	cout << "1) ������������\n";
	cout << "2) �������������\n";
	cout << "3) �������� �������� ������������\n";

	while (true) {
		int chooseRole = Security::securityInt();
		if (chooseRole == 1) {
			user.set_role(USER);
			break;
		}
		else if (chooseRole == 2) {
			user.set_role(ADMIN);
			break;
		}
		else if (chooseRole == 3) {
			return;
		}
		else {
			cout << "������ �������� ���!\n";
		}
	}
	user.set_password(createdPassword);
	user.set_login(founded_User);

	file.getUnicSeed(fileUser, user);
	file.create(fileUser, user);
	system("cls");
	cout << "�� ������� ������ ������������\n";*/

}
void Admin::editUserRole() {
	//system("cls");
	//User user;
	//cout << "�������������� ���� ������������\n\n";

	//cout << "������� ����� ������������: ";
	//string desiredUser;
	//cin >> desiredUser;
	//rewind(stdin);
	//bool isResult_Find = file.findOne(fileUser, &User::get_login, desiredUser, user);
	//if (!isResult_Find) {
	//	cout << "� ���� ������ ��� ������ ������������.\n";
	//	system("cls");
	//	return;
	//}
	//Role roleFromDb = user.get_role();

	//cout << "�������� ���� ������������: \n";
	//cout << "1) ������������\n";
	//cout << "2) �������������\n";
	//cout << "3) �������� �������� ������������\n";
	//while (true) {
	//	int chooseRole = Security::securityInt();
	//	if (chooseRole == 1) {
	//		user.set_role(USER);
	//		break;
	//	}
	//	else if (chooseRole == 2) {
	//		user.set_role(ADMIN);
	//		break;
	//	}
	//	else if (chooseRole == 3) {
	//		return;
	//	}
	//	else {
	//		cout << "������ �������� ���!\n";
	//	}
	//	if (roleFromDb == user.get_role()) {
	//		cout << "� ������������ ��� � ���� ����� ����. �������� ������ ��� �������� ��������������.\n";
	//		system("pause");
	//	}
	//}

	//vector<User> users;
	//file.findAll(fileUser, users);
	//for (size_t i = 0; i < users.size(); i++) {
	//	if (users[i].get_login() == user.get_login()) {
	//		users[i].set_role(user.get_role());
	//		cout << "���� ������� ������� ��������.\n";
	//		system("pause");
	//		break;
	//	}
	//}
	//// ���������� � ����
	//ofstream fileInput(fileUser);
	//for (size_t i = 0; i < users.size(); i++) {
	//	fileInput << users[i];
	//}
	//fileInput.close();

	//users.clear();


}
void Admin::editUserLogin() {
	//system("cls");
	//User user;
	//cout << "�������������� ������ ������������\n\n";

	//cout << "������� ����� ������������: ";
	//string desiredUser;
	//cin >> desiredUser;
	//rewind(stdin);

	//bool isResult_Find = file.findOne(fileUser, &User::get_login, desiredUser, user);
	//if (!isResult_Find) {
	//	cout << "� ���� ������ ��� ������ ������������.\n";
	//	system("cls");
	//	return;
	//}

	//cout << "������� ����� �����: ";
	//string newLoginUser;
	//cin >> newLoginUser;
	//rewind(stdin);



	//bool isExist_new_login = file.findOne(fileUser, &User::get_login, newLoginUser, user);
	//if (isExist_new_login) {
	//	cout << "� ���� ������ ��� ���� ������������ � ����� �������.\n";
	//	system("cls");
	//	return;
	//}
	//vector<User> users;
	//file.findAll(fileUser, users);
	//for (size_t i = 0; i < users.size(); i++) {
	//	if (user.get_login() == users[i].get_login()) {
	//		users[i].set_login(newLoginUser);
	//		cout << "����� ������� �������.\n";
	//		system("pause");
	//		break;
	//	}
	//}
	//// ���������� � ����
	//file.update(fileUser, users);


	//users.clear();
}
void Admin::editFilmName() {
	//system("cls");
	//Film film;
	//Place place;


	//cout << "������� �������� ������\n";
	//string current_name_film, newNameFilm;
	//cin >> current_name_film;
	//rewind(stdin);

	//// ����� �������� ������
	//if (!file.findOne(fileFilms, &Film::get_nameFilm, current_name_film, film) && !file.is_file_exist(current_name_film + ".txt")) {
	//	cout << "����� �� ������\n";
	//	system("pause");
	//	return;
	//}
	//cout << "������� ����� �������� ������\n";
	//cin >> newNameFilm;
	//rewind(stdin);
	////  ����� ������������� ������
	//if (file.findOne(fileFilms, &Film::get_nameFilm, newNameFilm, film)) {
	//	cout << "����� ����� ��� ����, ������� ������ �������� ������\n";
	//	system("pause");
	//	return;
	//}

	//vector<Film> films;
	//file.findAll(fileFilms, films);
	//vector<Place> Places;
	//file.findAll(current_name_film + ".txt", Places);

	//for (size_t i = 0; i < films.size(); i++) {
	//	if (films[i].get_nameFilm() == current_name_film) {
	//		cout << "����� ��� ������� �������.\n";
	//		films[i].set_nameFilm(newNameFilm);
	//		break;
	//	}
	//}
	//if (remove((current_name_film + ".txt").c_str())) {
	//	cout << "������ ���������� �����\n";
	//	system("pause");
	//	return;
	//}
	//file.update(fileFilms, films);
	//file.update(newNameFilm + ".txt", Places);

	//system("pause");
}
void Admin::deleteUser() {
	//vector<User> Users;
	//string loginUser;
	//cout << "�������� ������������\n\n";

	//cout << "������� ����� ������������, ��������� ������ �������: ";
	//cin >> loginUser;
	//rewind(stdin);
	//if (loginUser == session.login) {
	//	cout << "�� �� ������ ������� ���� �� �������, ������ ����������!\n";
	//	return;
	//}
	//file.findAll(fileUser, Users);
	//bool is_Find_User = false;
	//for (size_t i = 0; i < Users.size(); i++) {
	//	if (Users[i].get_login() == loginUser && Users[i].get_role() == ADMIN) {
	//		is_Find_User = true;
	//		cout << "�� �� ������ ������� ��������������!\n";
	//		break;
	//	}
	//	if (Users[i].get_login() == loginUser && Users[i].get_role() != ADMIN) {
	//		Users.erase(Users.begin() + i);
	//		is_Find_User = true;
	//		// ����������
	//		file.update(fileUser, Users);
	//		cout << "������������ ��� ������� ������!\n";
	//		break;
	//	}
	//}
	//if (!is_Find_User) {
	//	cout << "������������ " << loginUser << " �� ��� ������.\n";
	//}
}
void Admin::deleteFilm() {
	//vector<Film> Films;
	//string desired_movie_name;


	//cout << "�������� ������\n\n";
	//cout << "������� �������� ������: ";
	//cin >> desired_movie_name;
	//rewind(stdin);
	//file.findAll(fileFilms, Films);

	//bool is_One_foun_film = false;
	//for (size_t i = 0; i < Films.size(); i++) {

	//	if (Films[i].get_nameFilm() == desired_movie_name) {
	//		Films.erase(Films.begin() + i);
	//		is_One_foun_film = true;

	//		// ����������
	//		file.update(fileFilms, Films);

	//		if (!remove((desired_movie_name + ".txt").c_str())) {
	//			cout << "����� ��� ������� ������!\n";

	//		}
	//		else {
	//			cout << "����� ��� ������� ������, �� �������� �������� � ��������� �����!\n";
	//		}

	//		break;
	//	}
	//}
	//if (!is_One_foun_film) {
	//	cout << "����� " << desired_movie_name << " �� ��� ������.\n";
	//}
}
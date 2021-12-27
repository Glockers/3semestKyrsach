#include "Admin.h"



Admin::Admin() {
	this->set_role(ADMIN);
};

void Admin::add_Film() {

	/*Film film;
	film.fillData();

	string nameFile = film.get_nameFilm() + ".txt";
	if (file.is_file_exist(nameFile)) {
		cout << "Такой фильм уже существует!\n";
		return;
	};

	ofstream inFile(nameFile);
	for (int i = 1; i <= film.get_place(); i++) {
		inFile << i << "\n" << false << "\n" << "NONE\n";
	}
	inFile.close();

	file.create(fileFilms, film);
	cout << "Фильм успешно добавлен\n";*/

};

void Admin::createUser() {
	/*system("cls");
	User user;
	cout << "Создание новового пользователя\n\n";

	cout << "Введите логин пользователя: ";
	string founded_User = Security::securityString();
	rewind(stdin);

	bool isResultFound = file.findOne(fileUser, &User::get_login, founded_User, user);
	if (isResultFound) {
		cout << "Такой логин есть, придумайте другой.\n";
		return;
	}

	cout << "Введите пароль пользователя: ";
	string createdPassword;
	Security::InputPassword(createdPassword);

	cout << "Выберите роль пользователя: \n";
	cout << "1) Пользователь\n";
	cout << "2) Администратор\n";
	cout << "3) Отменить создание пользователя\n";

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
			cout << "Такого варианта нет!\n";
		}
	}
	user.set_password(createdPassword);
	user.set_login(founded_User);

	file.getUnicSeed(fileUser, user);
	file.create(fileUser, user);
	system("cls");
	cout << "Вы создали нового пользователя\n";*/

}
void Admin::editUserRole() {
	//system("cls");
	//User user;
	//cout << "Редактирование роли пользователя\n\n";

	//cout << "Введите логин пользователя: ";
	//string desiredUser;
	//cin >> desiredUser;
	//rewind(stdin);
	//bool isResult_Find = file.findOne(fileUser, &User::get_login, desiredUser, user);
	//if (!isResult_Find) {
	//	cout << "В базе данных нет такого пользователя.\n";
	//	system("cls");
	//	return;
	//}
	//Role roleFromDb = user.get_role();

	//cout << "Выберите роль пользователя: \n";
	//cout << "1) Пользователь\n";
	//cout << "2) Администратор\n";
	//cout << "3) Отменить создание пользователя\n";
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
	//		cout << "Такого варианта нет!\n";
	//	}
	//	if (roleFromDb == user.get_role()) {
	//		cout << "У пользователя уже и есть такая роль. Выберите другую или отмените редактирование.\n";
	//		system("pause");
	//	}
	//}

	//vector<User> users;
	//file.findAll(fileUser, users);
	//for (size_t i = 0; i < users.size(); i++) {
	//	if (users[i].get_login() == user.get_login()) {
	//		users[i].set_role(user.get_role());
	//		cout << "Роль успешно успешно изменена.\n";
	//		system("pause");
	//		break;
	//	}
	//}
	//// перезапись в файл
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
	//cout << "Редактирование логина пользователя\n\n";

	//cout << "Введите логин пользователя: ";
	//string desiredUser;
	//cin >> desiredUser;
	//rewind(stdin);

	//bool isResult_Find = file.findOne(fileUser, &User::get_login, desiredUser, user);
	//if (!isResult_Find) {
	//	cout << "В базе данных нет такого пользователя.\n";
	//	system("cls");
	//	return;
	//}

	//cout << "Введите новый логин: ";
	//string newLoginUser;
	//cin >> newLoginUser;
	//rewind(stdin);



	//bool isExist_new_login = file.findOne(fileUser, &User::get_login, newLoginUser, user);
	//if (isExist_new_login) {
	//	cout << "В базе данных уже есть пользователь с таким логином.\n";
	//	system("cls");
	//	return;
	//}
	//vector<User> users;
	//file.findAll(fileUser, users);
	//for (size_t i = 0; i < users.size(); i++) {
	//	if (user.get_login() == users[i].get_login()) {
	//		users[i].set_login(newLoginUser);
	//		cout << "Логин успешно изменен.\n";
	//		system("pause");
	//		break;
	//	}
	//}
	//// перезапись в файл
	//file.update(fileUser, users);


	//users.clear();
}
void Admin::editFilmName() {
	//system("cls");
	//Film film;
	//Place place;


	//cout << "Введите название фильма\n";
	//string current_name_film, newNameFilm;
	//cin >> current_name_film;
	//rewind(stdin);

	//// Поиск текущего фильма
	//if (!file.findOne(fileFilms, &Film::get_nameFilm, current_name_film, film) && !file.is_file_exist(current_name_film + ".txt")) {
	//	cout << "Фильм не найден\n";
	//	system("pause");
	//	return;
	//}
	//cout << "Введите новое название фильма\n";
	//cin >> newNameFilm;
	//rewind(stdin);
	////  Поиск существующего фильма
	//if (file.findOne(fileFilms, &Film::get_nameFilm, newNameFilm, film)) {
	//	cout << "Такой фильм уже есть, введите другое название фильма\n";
	//	system("pause");
	//	return;
	//}

	//vector<Film> films;
	//file.findAll(fileFilms, films);
	//vector<Place> Places;
	//file.findAll(current_name_film + ".txt", Places);

	//for (size_t i = 0; i < films.size(); i++) {
	//	if (films[i].get_nameFilm() == current_name_film) {
	//		cout << "Фильм был успешно изменен.\n";
	//		films[i].set_nameFilm(newNameFilm);
	//		break;
	//	}
	//}
	//if (remove((current_name_film + ".txt").c_str())) {
	//	cout << "Ошибка перезаписи файла\n";
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
	//cout << "Удаление пользователя\n\n";

	//cout << "Введите логин пользователя, котороого хотите удалить: ";
	//cin >> loginUser;
	//rewind(stdin);
	//if (loginUser == session.login) {
	//	cout << "Вы не можете удалить свой же аккаунт, будьте аккуратнее!\n";
	//	return;
	//}
	//file.findAll(fileUser, Users);
	//bool is_Find_User = false;
	//for (size_t i = 0; i < Users.size(); i++) {
	//	if (Users[i].get_login() == loginUser && Users[i].get_role() == ADMIN) {
	//		is_Find_User = true;
	//		cout << "Вы не можете удалить администратора!\n";
	//		break;
	//	}
	//	if (Users[i].get_login() == loginUser && Users[i].get_role() != ADMIN) {
	//		Users.erase(Users.begin() + i);
	//		is_Find_User = true;
	//		// Перезапись
	//		file.update(fileUser, Users);
	//		cout << "Пользователь был успешно удален!\n";
	//		break;
	//	}
	//}
	//if (!is_Find_User) {
	//	cout << "Пользователь " << loginUser << " не был найден.\n";
	//}
}
void Admin::deleteFilm() {
	//vector<Film> Films;
	//string desired_movie_name;


	//cout << "Удаление Фильма\n\n";
	//cout << "Введите название фильма: ";
	//cin >> desired_movie_name;
	//rewind(stdin);
	//file.findAll(fileFilms, Films);

	//bool is_One_foun_film = false;
	//for (size_t i = 0; i < Films.size(); i++) {

	//	if (Films[i].get_nameFilm() == desired_movie_name) {
	//		Films.erase(Films.begin() + i);
	//		is_One_foun_film = true;

	//		// Перезапись
	//		file.update(fileFilms, Films);

	//		if (!remove((desired_movie_name + ".txt").c_str())) {
	//			cout << "Фильм был успешно удален!\n";

	//		}
	//		else {
	//			cout << "Фильм был успешно удален, но возникла проблема с удалением файла!\n";
	//		}

	//		break;
	//	}
	//}
	//if (!is_One_foun_film) {
	//	cout << "Фильм " << desired_movie_name << " не был найден.\n";
	//}
}
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream> // Файлы
#include <string>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <cstdio>// для функции remove


// Отключение ошибок
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;


#define fileUser "Users.txt"
#define fileFilms "FilmList.txt"
#define fileTickets "Tickets.txt"




// Меню
class UserMenu {
public:
	static void show_Free_Place_On_Film();
};
class AdminMenu : public UserMenu
{
public:
	static void ShowMenuAdd();
	static void ShowMenuDelete();
	static void showAboutFilm();
	static void showAllFilm();
	static void showAllUser();
	static void ShowMenuData();
	static void deleteUser();
	static void deleteFilm();
	static void createUser();
	static void ShowMenuEdit();
	static void editUserRole();
	static void	editUserLogin();
	static void editFilmName();
	static void ShowMenuSort();
	static void sortLoginUser();
	static void	sortNameFilm();
	static void	sortFilmDate();
};

// Защита информации
class Security {
private:
	int res;
	string text;
public:
	// Проверки
	static void InputPassword(string& password);
	static string securityString();
	static int securityInt();
	static void securityDate(int& day, int& month, int& year);
};


// Интерфейс
class IShowMainMenu
{
public:
	virtual void showMenu() = 0;
	virtual void showPunktMenu() = 0;
};

// Типы пользователей
class User : public IShowMainMenu {

public:
	string login, role, password;
	int id;

	void showMenu() {
		while (true) {
			system("cls");
			cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ_____________\n\n" << endl;
			this->showPunktMenu();
			int command;
			command = Security::securityInt();
			if (command == 1) {
				buyTicket();
			}
			else if (command == 2) {
				UserMenu::show_Free_Place_On_Film();
			}
			else if (command == 3) {

			}
			else if (command == 4) {
				break;
			}
		}
	}

	void showPunktMenu() {
		cout << "1)Купить билет\n";
		cout << "2)Посмотреть свободные места на фильм\n";
		cout << "3)Мои билеты\n";
		cout << "4)Выйти из аккаунта\n";
		cout << ">>> ";

	}
	// method
	void buyTicket();
};
class Worker : public User {
private:
	void showPanelWorker() {

	}
public:
	void showMenu() {
		while (true) {
			system("cls");
			cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ / РАБОТНИКА_____________\n\n" << endl;
			this->showPunktMenu();
			int command;
			command = Security::securityInt();
			if (command == 0) {
				this->showPanelWorker();
			}
			else if (command == 1) {

			}
			else if (command == 2) {

			}
			else if (command == 3) {

			}
			else if (command == 4) {
				break;
			}

		}
	}

	void showPunktMenu() {
		cout << "0)Панель работника\n";
		User::showPunktMenu();
	}
};
class Admin : public User {
private:
	void showPanelAdmin() {
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
				AdminMenu::ShowMenuData();
			}
			else if (command == 2) {
				AdminMenu::ShowMenuAdd();
			}
			else if (command == 3)
			{
				AdminMenu::ShowMenuEdit();
			}
			else if (command == 4)
			{
				AdminMenu::ShowMenuDelete();
			}
			else if (command == 5)
			{
				AdminMenu::ShowMenuSort();
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
public:
	void showMenu() {
		while (true) {
			system("cls");
			cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ / АДМИНА_____________\n\n" << endl;
			this->showPunktMenu();
			int command = Security::securityInt();
			if (command == 0) {
				this->showPanelAdmin();
			}
			else if (command == 1) {

			}
			else if (command == 2) {
				AdminMenu::show_Free_Place_On_Film();
			}
			else if (command == 3) {

			}
			else if (command == 4) {
				return;
			}

		}
	}
	void showPunktMenu() {
		cout << "0)Перейти в панель администратора\n";
		User::showPunktMenu();
	}
};


// Сессия
struct SessionHandler {
	string login;
	string password;
	string role;
}session;

// Умные указатели
template <class T>
class SmartPointer {
public:
	SmartPointer(T* ptr) {
		this->ptr = ptr;
	}
	~SmartPointer() {
		delete ptr;
	}

	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
private:
	T* ptr = nullptr;
};

// Работа с файлами
class FileAction {
public:
	template<class T>
	void findAll(string nameFile, vector<T>& savedObject) {
		ifstream fileRead(nameFile);
		T varieable_object;
		while (fileRead >> varieable_object) {
			savedObject.push_back(varieable_object);
		}
		fileRead.close();
	}
	template<class T>
	void reWrite(string fileName, vector<T>& array) {
		ofstream fileWrite(fileName);
		for (size_t i = 0; i < array.size(); i++) {
			fileWrite << array[i];
		};
		fileWrite.close();
	};
	template<class T>
	void create(string fileName, T& object) {
		fstream fileWrite(fileName, ios::app);
		fileWrite << object;
		fileWrite.close();
	}
	template<class T, typename T2, class T3>
	bool findOne(string fileName, T2 T::* method, T3 value, T& savedObject) {
		ifstream fileRead(fileName);
		T variable_object;
		bool resultFind = false;
		if (!fileRead.is_open()) {
			cout << "Ошибка открытия файла\n";
			fileRead.close();
			return resultFind;
		}
		while (fileRead >> variable_object) {
			if (variable_object.*method == value) {
				savedObject = variable_object;
				resultFind = true;
				break;
			}
		}
		fileRead.close();
		return resultFind;
	}
	template <class T>
	void getUnicSeed(string nameFile, T& obj) {
		int count = 0;
		T buffer;
		ifstream fileRead(nameFile);
		if (!fileRead.is_open()) {
			obj.id = 0;
		}
		else {
			while (fileRead >> buffer) {
				count = buffer.id;
			}
			count++;
			obj.id = count;
		}
		fileRead.close();
	}

	bool is_file_exist(const string& fileName)
	{
		ifstream openFile(fileName);
		bool isOpen = openFile.good();
		openFile.close();
		return isOpen;
	};
};
FileAction file;


// ТЗ классы


class Place {
public:
	int place;
	string login;
	bool is_Free_Place;
	friend ostream& operator << (ostream& os, const Place& p);
	friend istream& operator >> (istream& in, Place& p);
};

class Film {
public:
	string nameFilm;
	int coast;
	int place, day, month, year;
	void add_New_Film();

	friend ostream& operator << (ostream& os, const Film& p);
	friend istream& operator >> (istream& in, Film& p);

};
class Tickets : public Film {
private:
	string login;
	int id;
public:
	// getter
	string getLogin() {
		return this->login;
	}
	int getId() {
		return this->id;
	}

	// setter
	void set_login(string login) {
		this->login = login;
	}
	void set_Id(int id) {
		this->id = id;
	}


	
	friend ostream& operator << (ostream& os, const Tickets& p);
	friend istream& operator >> (istream& in, Tickets& p);
	friend class FileAction;
};


class Menu : virtual public Admin, virtual public User, virtual public AdminMenu {
public:
	template <class T, class T2>
	static void createMenu(string& menu_description, T2 T::* pMethod[], int lengthArray) {
		int lowerLimit = lengthArray - lengthArray + 1;
		lengthArray++;
		while (true) {
			system("cls");
			cout << menu_description;
			cout << "Введите номер команды: ";
			int command = Security::securityInt();
			if (command < lowerLimit || command >lengthArray) {
				cout << "Введите значение от " << 1 << " до " << lengthArray << endl;
				system("pause");
			}
			else if (command == lengthArray) {
				break;
			}
			else {
				T object;
				(object.*pMethod[command - 1])();
			}
		}
	}
	static void createMenu(string& menu_description, void (*pMethod[])(), int lengthArray) {
		int lowerLimit = lengthArray - lengthArray + 1;
		lengthArray++;
		while (true) {
			system("cls");
			cout << menu_description;
			cout << "Введите номер команды: ";
			int command = Security::securityInt();
			if (command < lowerLimit || command >lengthArray) {
				cout << "Введите значение от " << lowerLimit << " до " << lengthArray << endl;
				system("pause");
			}
			else if (command == lengthArray) {
				break;
			}
			else {
				pMethod[command - 1]();
			}
		}
	}

	// Регистрация
	void reg_an_account();

	// Авторизация
	void log_in_account();
};

// Перегрузка
ostream& operator<<(ostream& out, const User& user);
istream& operator>>(istream& in, User& user);

template<class T, class T2>
void SortShell(vector<T>& arr, T2 T::* field)
{
	size_t size = arr.size();
	int step = (int)size / 2;
	while (step != 0)
	{
		// Сортируем группы элементов отстоящих друг от друга на значение шага вставками

		for (int i = step; i < size; ++i) {
			T tmp = arr[i];
			int j = 0;

			for (j = i - step; j >= 0 && arr[j].*field > tmp.*field; j -= step) {
				arr[j + step] = arr[j];
			}
			arr[j + step] = tmp;

		}
		step /= 2;
	}
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------


// ГЛАВНОЕ МЕНЮ
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("cls");
	void (Menu:: * pFuncArray[2])() = { &Menu::log_in_account, &Menu::reg_an_account };
	int lengthArray = sizeof(pFuncArray) / sizeof(pFuncArray[0]);
	string menu_description = "Главное меню\n\n1) Авторизация\n2) Регистрация\n3) Выход из системы\n";
	Menu::createMenu(menu_description, pFuncArray, lengthArray);


	return 0;
}



// -------------------------------------------------------------------------------------------------------------------------------------------------------


ostream& operator<<(ostream& out, const User& user)
{
	out << user.id << "\n" << user.login << "\n" << user.password << "\n" << user.role << endl;
	return out;
}
istream& operator>>(istream& in, User& point)
{
	in >> point.id;
	in >> point.login;
	in >> point.password;
	in >> point.role;
	return in;
}

ostream& operator << (ostream& os, const Film& p)
{
	return os << p.nameFilm << "\n" << p.place << "\n" << p.coast << "\n" << p.day << "\n" << p.month << "\n" << p.year << endl;
}
istream& operator >> (istream& in, Film& p)
{
	return in >> p.nameFilm >> p.place >> p.coast >> p.day >> p.month >> p.year;
}

ostream& operator << (ostream& os, const Place& p)
{
	return os << p.place << "\n" << p.is_Free_Place << "\n" << p.login << endl;
}
istream& operator >> (istream& in, Place& p)
{
	return in >> p.place >> p.is_Free_Place >> p.login;
}

ostream& operator << (ostream& os, const Tickets& p)
{
	return os << p.id << "\n" << p.login << "\n" << p.nameFilm << "\n" << p.place << p.day << "\n" << p.month << "\n" << p.year << endl;
}
istream& operator >> (istream& in, Tickets& p)
{
	return in >> p.id >> p.login >> p.nameFilm >> p.place >> p.day >> p.month >> p.year;
}

// Авторизация
void Menu::log_in_account() {

	int countTry = 3;

	while (countTry > 0) {
		SmartPointer<User> userLogin = new User;
		SmartPointer<User> user = new User;
		Worker worker;
		Admin admin;
		User userr;


		IShowMainMenu* ptrUser[3];
		ptrUser[0] = &userr;
		ptrUser[1] = &worker;
		ptrUser[2] = &admin;


		system("cls");
		cout << "Авторизация\n\n" << endl;
		rewind(stdin);
		cout << "Введите Login: ";
		userLogin->login = Security::securityString();
		rewind(stdin);
		cout << "Введите Password: ";
		Security::InputPassword(userLogin->password);


		// Проверка
		file.findOne(fileUser, &User::login, userLogin->login, *user);

		if (user->password == "" || user->password != userLogin->password) {
			countTry--;
			cout << "Вы ввели неверный логин или пароль! У вас осталось " << countTry << " попытки." << endl;
			if (countTry == 0) {
				cout << "Вы исчерпали лимит попыток :(" << endl;
				cout << "Вы были заблокированны на 5 секунд\n" << endl;
				Sleep(5000);
			}
			system("pause");
		}
		else if (userLogin->password == user->password) {
			cout << "Вы вошли как " << user->role << endl;
			session.login = user->login;
			session.password = user->password;
			session.role = user->role;

			system("pause");
			system("cls");

			if (user->role == "USER") {
				ptrUser[0]->showMenu();
			}

			else if (user->role == "WORKER") {
				ptrUser[1]->showMenu();
			}
			else if (user->role == "ADMIN") {
				ptrUser[2]->showMenu();
			}
			session.login = "";
			session.password = "";
			session.role = "";
			cout << "Вы вышли из аккаунта\n";
			system("pause");
			break;
		}

	}
}

// Регистрация
void Menu::reg_an_account() {
	system("cls");
	SmartPointer<User> user = new User;
	SmartPointer<User> userExist = new User;

	cout << "РЕГИСТРАЦИЯ\n\n";
	cout << "Введите ваш будующий логин: ";
	cin >> user->login;
	rewind(stdin);
	while (true) {
		system("cls");
		cout << "Введите надежный пароль: ";
		Security::InputPassword(user->password);
		if (user->password.size() < 6) {
			cout << "Слишком короткий пароль. Введите еще раз\n";
			user->password = "";
		}
		else if (user->password.size() >= 6) {
			string password;
			cout << "Повторите пароль: ";
			Security::InputPassword(password);
			if (user->password == password) {
				break;
			}
			else {
				cout << "Пароли не совпадают\n";
				user->password = "";
			}
		}
		system("pause");
	}


	file.findOne(fileUser, &User::login, user->login, *userExist);
	if (userExist->login != user->login && user->password != userExist->password) {
		file.getUnicSeed(fileUser, *user);
		if (user->id == 0) {
			user->role = "ADMIN";
		}
		else {
			user->role = "USER";
		}

		file.create(fileUser, *user);
		system("cls");
		cout << "Вы зарегистрировались. Далее для продолжения работы войдите в личный кабинет.\n";
	}
	else {
		cout << "Аккаунт с таким логином уже существует!\n";
	}


}

// FILMS
void Film::add_New_Film() {
	cout << "Введите название фильма: ";
	cin >> nameFilm;
	rewind(stdin);

	cout << "Введите количество мест: ";
	place = Security::securityInt();

	cout << "Введите стоимость билета: ";
	coast = Security::securityInt();
	system("cls");
	cout << "Введите дату начала\n ";
	Security::securityDate(this->day, this->month, this->year);

	string nameFile = nameFilm + ".txt";
	if (file.is_file_exist(nameFile)) {
		cout << "Такой фильм уже существует!\n";
		return;
	};

	ofstream inFile(nameFile);
	for (int i = 1; i <= place; i++) {
		inFile << i << "\n" << false << "\n" << "NONE\n";
	}
	inFile.close();

	file.create(fileFilms, *this);
	cout << "Фильм успешно добавлен\n";

};

// Tickets
void User::buyTicket() {
	Film film;
	Tickets ticket;
	system("cls");
	cout << "Введите название фильма: ";
	cin >> ticket.nameFilm;
	string name = ticket.nameFilm + ".txt";
	rewind(stdin);

	
	if (!file.findOne(fileFilms, &Film::nameFilm, ticket.nameFilm, film) || !file.is_file_exist(name)) {
		cerr << "Такого фильма нет!\n";
		return;
	}

	// Загружаем данные
	vector<Place> places;
	file.findAll(name, places);



	int count_free_place = 0;
	cout << "Свободные места: ";
	for (int i = 0; i < places.size(); i++)
	{
		if (!places[i].is_Free_Place) {
			count_free_place++;
			cout << places[i].place << " | ";
		}

	};
	system("pause");

	if (count_free_place == 0) {
		cout << "Свободных мест нет!\n";
		return;
	}

	int choosePlace;
	while (true) {
		system("cls");
		cout << "Выберите свободное место: ";
		choosePlace = Security::securityInt() - 1;

		if (choosePlace < 0 || choosePlace >(places.size()) - 1) {
			cout << "Такого места нет!\n";

		}
		else if (places[choosePlace].is_Free_Place) {
			cout << "Это место занятно!!!";
		}
		else {
			places[choosePlace].is_Free_Place = true;
			places[choosePlace].login = session.login;
			file.reWrite(name, places);
			break;
		}
		system("pause");
	}
	ticket.place = choosePlace;
	//ticket.day = film.day;
	ticket.set_login(session.login);
	file.getUnicSeed(fileTickets, ticket);
	
	// Запись
	file.create(fileTickets, *this);

	cout << "Вы купили билет!!!\n";
	system("pause");
};

// AdminMenu
void AdminMenu::ShowMenuData() {


	while (true) {
		system("cls");
		cout << "Вывод данных\n\n";
		cout << "1) Отоброзить список пользователей\n";
		cout << "2) Отоброзить список фильмов\n";
		cout << "3) Отоброзить список всех билетов\n";
		cout << "4) Отоброзить список мест на фильм\n";
		cout << "5) Вернуться назад\n\n";

		cout << ">>> ";
		int command = Security::securityInt();
		if (command == 1) {
			AdminMenu::showAllUser();
			system("pause");
		}
		else if (command == 2) {
			AdminMenu::showAllFilm();
			system("pause");
		}
		else if (command == 3) {

		}
		else if (command == 4) {
			system("cls");
			AdminMenu::showAboutFilm();
			system("pause");
		}
		else if (command == 5) {
			break;
		}
	}

}
void AdminMenu::showAllUser() {
	vector<User> Users;

	file.findAll(fileUser, Users);
	cout << "Список всех пользователей:" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "|   ID   |       Логин         |            Пароль                  |   Статус   |" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Users.size(); i++) {

		cout << "|" << setw(7) << Users[i].id << " |" << setw(20) << Users[i].login << " |" << setw(35) << Users[i].password
			<< " |" << setw(11) << Users[i].role << " |" << endl;


	}
	cout << "--------------------------------------------------------------------------------- " << endl;

	cout << endl;

}
void AdminMenu::showAllFilm() {
	vector<Film> Films; //Вектор строки, используемый для указания статуса пользователя

	file.findAll(fileFilms, Films);
	cout << "Список всех фильмов:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "|       Название фильма         |      Всего мест       |   Стоимость билета   |" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	bool is_Find_One_of_Film = false;
	for (size_t i = 0; i < Films.size(); i++) {
		cout << "|" << std::setw(31) << Films[i].nameFilm << "|" << setw(23) << Films[i].place
			<< "|" << setw(22) << Films[i].coast << "|" << endl;
		is_Find_One_of_Film = true;
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	if (!is_Find_One_of_Film) {
		system("cls");
		cout << "Список фильмов пуст!\n";
	}
	cout << endl;
	Films.clear();
}
void AdminMenu::showAboutFilm() {
	vector<Place> Place;
	cout << "Введите название фильма: ";
	string nameFilm;
	cin >> nameFilm;
	rewind(stdin);
	cout << "Информация о фильме: <" << nameFilm << ">" << endl;
	int countFree = 0;
	int countNotFree = 0;

	nameFilm += ".txt";
	if (!file.is_file_exist(nameFilm)) {
		cout << "Такого фильма нет!\n";
		return;
	}


	file.findAll(nameFilm, Place);

	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "|       Номер места         |      Статус места       |       Логин покупателя      |" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Place.size(); i++) {
		string status;
		string login;
		if (Place[i].is_Free_Place) {
			status = "Занято";
			countNotFree++;
		}
		else {
			status = "Свободно";
			countFree++;
		}
		if (Place[i].login == "NONE") {
			login = "Нет";
		}
		else {
			login = Place[i].login;
		}
		cout << "|" << std::setw(26) << Place[i].place << " |" << setw(24) << status
			<< " |" << setw(28) << login << " |" << endl;
	}
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Свободно мест: " << countFree << endl;
	cout << "Занято мест: " << countNotFree << endl;

	Place.clear();
}



//Two command
void AdminMenu::ShowMenuAdd() {
	while (true) {
		system("cls");

		cout << "Добавление данных\n\n";
		cout << "1) Создать пользователя\n";
		cout << "2) Добавить новый фильм\n";
		cout << "3) Вернуться назад\n\n";

		cout << ">>> ";
		int command = Security::securityInt();
		if (command == 1) {
			createUser();
			system("pause");
		}
		else if (command == 2) {
			Film film;
			film.add_New_Film();
			system("pause");
		}
		else if (command == 3) {
			break;
		}

	}
}
void AdminMenu::createUser() {
	system("cls");

	cout << "Создание новового пользователя\n\n";
	User user;
	cout << "Введите логин пользователя: ";
	cin >> user.login;
	rewind(stdin);
	bool resultFind = file.findOne(fileUser, &User::login, user.login, user);
	if (resultFind) {
		cout << "Такой логин есть, придумайте другой.\n";
		return;
	}
	cout << "Введите пароль пользователя: ";
	Security::InputPassword(user.password);

	cout << "Выберите роль пользователя: \n";
	cout << "1) Пользователь\n";
	cout << "2) Работник\n";
	cout << "3) Администратор\n";
	cout << "4) Отменить создание пользователя\n";

	while (true) {
		int chooseRole = Security::securityInt();
		if (chooseRole == 1) {
			user.role = "USER";
			break;
		}
		else if (chooseRole == 2) {
			user.role = "WORKER";
			break;
		}
		else if (chooseRole == 3) {
			user.role = "ADMIN";
			break;
		}
		else if (chooseRole == 4) {
			return;
		}
		else {
			cout << "Такого варианта нет!\n";
		}
	}
	file.getUnicSeed(fileUser, user);
	file.create(fileUser, user);
	system("cls");
	cout << "Вы создали нового пользователя\n";

}

// Three command
void AdminMenu::ShowMenuEdit() {
	system("cls");

	void (*pArrayFunc[3]) () = { &AdminMenu::editUserRole ,&AdminMenu::editUserLogin, &AdminMenu::editFilmName };
	int lengthArray = sizeof(pArrayFunc) / sizeof(pArrayFunc[0]);
	string menu_description = "Редактирование данных\n\n1) Изменить роль пользователя\n2) Изменить логин пользователя\n3) Изменить название фильма\n4) Вернуться назад\n";
	Menu::createMenu(menu_description, pArrayFunc, lengthArray);
}
void AdminMenu::editUserRole() {
	system("cls");
	User user;
	cout << "Редактирование роли пользователя\n\n";

	cout << "Введите логин пользователя: ";
	cin >> user.login;
	rewind(stdin);
	bool isResult_Find = file.findOne(fileUser, &User::login, user.login, user);
	if (!isResult_Find) {
		cout << "В базе данных нет такого пользователя.\n";
		system("cls");
		return;
	}
	cout << "Выберите новую роль: ";
	string bufferRole = user.role;
	while (true) {
		int chooseRole = Security::securityInt();
		if (chooseRole == 1) {
			user.role = "USER";
			break;
		}
		else if (chooseRole == 2) {
			user.role = "WORKER";
			break;
		}
		else if (chooseRole == 3) {
			user.role = "ADMIN";
			break;
		}
		else if (chooseRole == 4) {
			return;
		}
		else {
			cout << "Такого варианта нет!\n";
		}
		if (bufferRole == user.role) {
			cout << "У пользователя уже и есть такая роль. Выберите другую или отмените редактирование.\n";
			system("pause");
		}
	}

	vector<User> users;
	file.findAll(fileUser, users);
	for (size_t i = 0; i < users.size(); i++) {
		if (users[i].login == user.login) {
			users[i].role = user.role;
			cout << "Роль успешно успешно изменена.\n";
			system("pause");
			break;
		}
	}
	// перезапись в файл
	ofstream fileInput(fileUser);
	for (size_t i = 0; i < users.size(); i++) {
		fileInput << users[i];
	}
	fileInput.close();

	users.clear();


}
void AdminMenu::editUserLogin() {
	system("cls");
	User user;
	cout << "Редактирование логина пользователя\n\n";

	cout << "Введите логин пользователя: ";
	cin >> user.login;
	rewind(stdin);
	bool isResult_Find = file.findOne(fileUser, &User::login, user.login, user);
	if (!isResult_Find) {
		cout << "В базе данных нет такого пользователя.\n";
		return;
	}
	cout << "Введите новый логин: ";
	SmartPointer<User> newUser = new User;
	cin >> newUser->login;
	rewind(stdin);
	bool isResult_find_new_login = file.findOne(fileUser, &User::login, newUser->login, *newUser);
	if (isResult_find_new_login) {
		cout << "В базе данных уже есть пользователь с таким логином.\n";
		system("cls");
		return;
	}
	vector<User> users;
	file.findAll(fileUser, users);
	for (size_t i = 0; i < users.size(); i++) {
		if (newUser->login == users[i].login) {
			users[i].login = newUser->login;
			cout << "Логин успешно изменен.\n";
			system("pause");
			break;
		}
	}
	// перезапись в файл
	ofstream fileInput(fileUser);
	for (size_t i = 0; i < users.size(); i++) {
		fileInput << users[i];
	}
	fileInput.close();

	users.clear();
}
void AdminMenu::editFilmName() {
	system("cls");
	Film film;
	Place place;


	cout << "Введите название фильма\n";
	string nameFilm, newNameFilm;
	cin >> nameFilm;
	rewind(stdin);
	cout << "Введите новое название фильма\n";
	cin >> newNameFilm;
	rewind(stdin);

	if (!file.findOne(fileFilms, &Film::nameFilm, nameFilm, film) && !file.is_file_exist(nameFilm + ".txt")) {
		cout << "Фильм не найден\n";
		system("pause");
		return;
	}
	if (file.findOne(fileFilms, &Film::nameFilm, newNameFilm, film)) {
		cout << "Такой фильм уже есть, введите другое название фильма\n";
		system("pause");
		return;
	}

	vector<Film> films;
	file.findAll(fileFilms, films);
	vector<Place> Places;
	file.findAll(nameFilm + ".txt", Places);

	for (size_t i = 0; i < films.size(); i++) {
		if (films[i].nameFilm == nameFilm) {
			films[i].nameFilm = newNameFilm;
			break;
		}
	}
	if (remove((nameFilm + ".txt").c_str())) {
		cout << "Ошибка перезаписи файла\n";
		system("pause");
		return;
	}
	file.reWrite(fileFilms, films);
	file.reWrite(newNameFilm + ".txt", Places);

	cout << "Фильм был успешно изменен.\n";
	system("pause");

}

//Four command
void AdminMenu::ShowMenuDelete() {
	while (true) {
		system("cls");
		cout << "Удаление данных\n\n";
		cout << "1) Удалить пользователя\n";
		cout << "2) Удалить фильм\n";
		cout << "3) Вернуться назад\n\n";

		cout << ">>> ";
		int command = Security::securityInt();
		if (command == 1) {
			system("cls");
			deleteUser();
			system("pause");
		}
		else if (command == 2) {
			system("cls");
			deleteFilm();
			system("pause");
		}
		else if (command == 3) {
			break;
		}

	}
}
void AdminMenu::deleteUser() {
	vector<User> Users;
	string loginUser;
	cout << "Удаление пользователя\n\n";

	cout << "Введите логин пользователя, котороого хотите удалить: ";
	cin >> loginUser;
	rewind(stdin);
	if (loginUser == session.login) {
		cout << "Вы не можете удалить свой же аккаунт, будьте аккуратнее!\n";
		return;
	}
	file.findAll(fileUser, Users);
	bool is_Find_User = false;
	for (size_t i = 0; i < Users.size(); i++) {
		if (Users[i].login == loginUser && Users[i].role == "ADMIN") {
			is_Find_User = true;
			cout << "Вы не можете удалить администратора!\n";
			break;
		}
		if (Users[i].login == loginUser && Users[i].role != "ADMIN") {
			Users.erase(Users.begin() + i);
			is_Find_User = true;
			// Перезапись
			ofstream fileInput(fileUser);
			for (size_t i = 0; i < Users.size(); i++) {
				fileInput << Users[i];
			}
			fileInput.close();
			cout << "Пользователь был успешно удален!\n";
			break;
		}
	}
	if (!is_Find_User) {
		cout << "Пользователь " << loginUser << " не был найден.\n";
	}
}
void AdminMenu::deleteFilm() {
	vector<Film> Films;
	string desired_movie_name;


	cout << "Удаление Фильма\n\n";
	cout << "Введите название фильма: ";
	cin >> desired_movie_name;
	rewind(stdin);
	file.findAll(fileFilms, Films);

	bool is_One_foun_film = false;
	for (size_t i = 0; i < Films.size(); i++) {

		if (Films[i].nameFilm == desired_movie_name) {
			Films.erase(Films.begin() + i);
			is_One_foun_film = true;

			// Перезапись
			file.reWrite(fileFilms, Films);
			
			if (!remove((desired_movie_name + ".txt").c_str())) {
				cout << "Фильм был успешно удален!\n";

			}
			else {
				cout << "Фильм был успешно удален, но возникла проблема с удалением файла!\n";
			}

			break;
		}
	}
	if (!is_One_foun_film) {
		cout << "Фильм " << desired_movie_name << " не был найден.\n";
	}
}

//Five command
void AdminMenu::ShowMenuSort() {
	system("cls");
	void (*pArrayFunc[3]) () = { &AdminMenu::sortLoginUser ,&AdminMenu::sortNameFilm, &AdminMenu::sortFilmDate };

	int length = sizeof(pArrayFunc) / sizeof(pArrayFunc[0]);
	string menu_description = "Сортировка данных\n\n1) Сортировать пользователей по логину\n2) Сортировать название фильмов\n3) Сортировать билеты по дате\n4) Вернуться назад\n";
	Menu::createMenu(menu_description, pArrayFunc, length);
}
void AdminMenu::sortLoginUser() {
	system("cls");
	User user;
	vector <User> Users;
	file.findAll(fileUser, Users);

	SortShell(Users, &User::login);
	cout << "Список всех пользователей:" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "|   ID   |       Логин         |            Пароль                  |   Статус   |" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Users.size(); i++) {

		cout << "|" << setw(7) << Users[i].id << " |" << setw(20) << Users[i].login << " |" << setw(35) << Users[i].password
			<< " |" << setw(11) << Users[i].role << " |" << endl;
	}
	cout << "--------------------------------------------------------------------------------- " << endl;

	cout << endl;
	system("pause");
}
void AdminMenu::sortNameFilm() {
	system("cls");
	Film film;
	vector <Film> Films;
	file.findAll(fileFilms, Films);
	SortShell(Films, &Film::nameFilm);
	cout << "Список всех фильмов:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "|       Название фильма         |      Всего мест       |   Стоимость билета   |" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	bool isResult_Find_of_film = false;
	for (size_t i = 0; i < Films.size(); i++) {
		isResult_Find_of_film = true;

		cout << "|" << setw(31) << Films[i].nameFilm << "|" << setw(23) << Films[i].place
			<< "|" << setw(22) << Films[i].coast << "|" << endl;
	}
	cout << "--------------------------------------------------------------------------------" << endl;
	if (!isResult_Find_of_film) {
		system("cls");
		cout << "Список фильмов пуст!\n";
	}

	cout << endl;
	system("pause");
}
void AdminMenu::sortFilmDate() {
	system("cls");
	Tickets ticket;
	vector <Film> Films;
	file.findAll(fileFilms, Films);
	for (size_t i = 0; i < Films.size(); i++) {
		for (size_t j = i; j < Films.size(); j++) {
			if (Films[i].day < Films[j].day && Films[i].month < Films[j].month && Films[i].year < Films[j].year) {
				swap(Films[i], Films[j]);
			}
		}
	}

	cout << "Список всех фильмов\n" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	cout << "|       Название фильма         |      Всего мест       |   Стоимость билета   |   Дата начала   |" << endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	bool isResult_found_film = false;
	for (size_t i = 0; i < Films.size(); i++) {
		cout << "|" << setw(31) << Films[i].nameFilm << "|"
			<< setw(23) << Films[i].place
			<< "|" << setw(21) << Films[i].coast << " |"
			<< setw(8) << Films[i].day << "." << Films[i].month << "." << Films[i].year << " |"
			<< endl;
		isResult_found_film = true;
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;

	if (!isResult_found_film) {
		system("cls");
		cout << "Список фильмов пуст!\n";
		system("pause");

	}
	cout << endl;

	system("pause");

}




int Security::securityInt() {
	int res;
	while (!(cin >> res) || ((getchar()) != '\n')) {
		rewind(stdin);
		cin.clear();
		cout << "Введите другое\n";
	}
	return res;
}
string Security::securityString() {
	string text;
	while (true) {
		int flag = 0;
		cin >> text;
		rewind(stdin);
		for (int i = 0; i < text.length(); i++) {
			if (isdigit(text[i])) {
				flag = 1;
				cin.clear();
				cout << "Строка не должна содержать символы!\n";
				cout << "Введите еще раз: ";
				break;
			}
		}
		if (flag == 0) break;
	}
	return text;
}
void Security::InputPassword(string& password)
{
	int ch = 0;
	while (true)
	{
		ch = _getch();
		if (ch == 13) // enter
		{
			break;
		}
		else if (ch == 8)
		{
			cout << (char)8 << " " << (char)8;
			if (password.length() != 0)
			{
				password.erase(password.length() - 1);
			}
			else
			{
				password = "";
			}
		}
		else
		{
			cout << '*';
			password = password + (char)ch;
		}
	}
	cout << "\n";
	if (!password.empty())
		return;
	else
		cout << "Введите пароль!\n" << endl;;
}
void Security::securityDate(int& day, int& month, int& year) {
	while (true) {
		cout << "Введите день: ";
		day = securityInt();
		cout << "Введите месяц: ";
		month = securityInt();
		cout << "Введите год: ";
		year = securityInt();
		if ((day >= 0 && day <= 31) && (month >= 0 && month <= 12) && (year >= 1900 && year <= 2021)) {
			break;
		}
		else {
			cout << "Ошибка в дате!\n";
		}
	}
}


// Меню Юзера
void UserMenu::show_Free_Place_On_Film() {
	system("cls");
	cout << "Список свободных мест\n\n";
	vector<Film> Films;
	vector<Place> Places;

	file.findAll(fileFilms, Films);
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|   Кол-во свободных мест   |      Название фильма       |      Дата начала фильма     |" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Films.size(); i++) {
		file.findAll(Films[i].nameFilm + ".txt", Places);
		string date = "";
		int countNotFree = 0, countFree = 0;
		for (size_t i = 0; i < Places.size(); i++) {
			string status;
			string login;
			if (Places[i].is_Free_Place) {
				status = "Занято";
				countNotFree++;
			}
			else {
				status = "Свободно";
				countFree++;
			}
			if (Places[i].login == "NONE") {
				login = "Нет";
			}
			else {
				login = Places[i].login;
			}

		}
		cout << "|" << std::setw(26) << countFree << " |" << setw(27) << Films[i].nameFilm
			<< " |" << setw(20) << Films[i].day << "." << Films[i].month << "." << Films[i].year << " |" << endl;
		Places.clear();
	}

	cout << "----------------------------------------------------------------------------------------" << endl;

	system("pause");
}



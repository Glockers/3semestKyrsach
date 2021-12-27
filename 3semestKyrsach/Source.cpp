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


// препроцессирование
#define TYPE_METHOD void(SmartMenu::*)()
#define TYPE_FUNCTION void(*)()
#define EXIT_FUNCTION nullptr

const string fileUser = "Users.txt";
const string fileFilms = "FilmList.txt";
const string fileTickets = "Tickets.txt";

class Tickets;
enum Role
{
	USER,
	ADMIN
} role;
// Меню
class IMenu {
public:
	virtual void showMenu() = 0;
	virtual void showPunktMenu() = 0;
	virtual Role get_status() = 0;
	virtual bool showChecks(int command) = 0;
};
class ClientMenu : public IMenu {
protected:
	Role status;
public:
	ClientMenu() {
		this->status = USER;
	}
	Role get_status() {
		return this->status;
	}
	bool showChecks(int command) override;
	void showMenu() override;
	void showPunktMenu() override;
};
class AdminMenu : public ClientMenu
{
private:
	void showPanelAdmin();
public:
	AdminMenu() {
		this->status = ADMIN;
	}
	// Главное меню
	void showMenu() override;
	void showPunktMenu() override;
	bool showChecks(int command) override;

	// Остальные меню
	static void ShowMenuAdd();
	static void ShowMenuDelete();
	static void showAboutFilm();
	static void showAllFilm();
	static void showAllUser();
	static void ShowMenuData();
	static void ShowMenuEdit();
	static void ShowMenuSort();
	static void sortLoginUser();
	static void	sortNameFilm();
	static void	sortFilmDate();
	static void showAllTickets();


	void searchUser();
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



// Все пользователи
class User {
private:
	string login, password;
	Role role;
	int id;
public:

	// get
	string get_login() {
		return this->login;
	}
	Role get_role() {
		return role;
	}
	string get_password() {
		return this->password;
	}
	int get_id() {
		return this->id;
	}

	//setter
	void set_login(string login) {
		this->login = login;
	}
	void set_role(Role role) {
		this->role = role;
	}
	void set_password(string password) {
		this->password = password;
	}
	void set_id(int id) {
		this->id = id;
	}




	friend ostream& operator<<(ostream& out, const User& user);
	friend istream& operator>>(istream& in, User& point);

	friend class Database;
};
// Роли
class Guest : public User {
public:
	void checkRole(Role);
	// Регистрация
	void reg_an_account();
	// Авторизация
	void log_in_account();

};
class Client : public User {
protected:
	vector<Tickets> tickets;
public:

	Client();
	static void buyTicket();
	static void show_Free_Place_On_Film();
	void show_my_Tickets();

	friend istream& operator>>(istream& in, Client& client);
	friend ostream& operator<<(ostream& out, Client& client);
};
class Admin : public Client {
private:

public:
	Admin();

	void add_Film();
	static void createUser();

	static void deleteFilm();
	static void deleteUser();

	static void editUserRole();
	static void	editUserLogin();
	static void editFilmName();
};




// Сессия
struct SessionHandler {
	string login;
	string password;
	Role role;
} session;

// Умные указатели


// Работа с файлами
class Database {
	int static result;
public:
	template<class Object, class TypeMethod, class any_type>
	bool findOne(const string& fileName, TypeMethod Object::* method, any_type value, Object& object) {
		ifstream fileRead(fileName);
		Object variable_object;
		bool resultFind = false;
		if (!fileRead.is_open()) {
			cout << "Ничего не найдено\n";
			fileRead.close();
			return resultFind;
		}
		while (fileRead >> variable_object) {
			if ((variable_object.*method)() == value) {
				object = variable_object;
				resultFind = true;
				break;
			}
		}
		fileRead.close();
		return resultFind;
	}
	template<class T>
	void findAll(const string& nameFile, vector<T>& savedObject) {
		ifstream fileRead(nameFile);
		T varieable_object;
		while (fileRead >> varieable_object) {
			savedObject.push_back(varieable_object);
		}
		fileRead.close();
	}
	template<class T>
	void update(const string& fileName, vector<T>& array) {
		ofstream fileWrite(fileName);
		for (size_t i = 0; i < array.size(); i++) {
			fileWrite << array[i];
		};
		fileWrite.close();
	};
	template<class T>
	void create(const string& fileName, T& object) {
		fstream fileWrite(fileName, ios::app);
		fileWrite << object;
		fileWrite.close();
	}

	template <class T>
	void getUnicSeed(const string& nameFile, T& obj) {
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
Database file;



namespace Smart {
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
	class SmartMenu : virtual public Guest, virtual public Admin, virtual public AdminMenu {
	public:
		template <class T, class T2>
		static void createMenu(string& menu_description, vector<T2(T::*)()>& pMethod) {
			int lengthArray = (int)pMethod.size() + 1;
			int borderLimit = lengthArray - lengthArray + 1;
			while (true) {
				system("cls");
				cout << menu_description;
				cout << "Введите номер команды (-1 означает выход): ";
				size_t command = Security::securityInt();
				if (command == -1) {
					break;
				}
				else if (command < borderLimit || command >= lengthArray) {
					cout << "Введите значение от " << borderLimit << " до " << lengthArray - 1 << endl;
					system("pause");
				}
				else if (pMethod[command - 1] == EXIT_FUNCTION) {
					break;
				}
				else {
					T object;
					(object.*pMethod[(command)-1])();
				}
			}
		}

		template <class T>
		static void createMenu(string& menu_description, vector<T(*)()>& pMethod) {
			int lengthArray = (int)pMethod.size() + 1;
			int borderLimit = lengthArray - lengthArray + 1;
			while (true) {
				system("cls");
				cout << menu_description;
				cout << "Введите номер команды (-1 означает выход): ";
				size_t command = Security::securityInt();
				if (command == -1) {
					break;
				}
				else if (command < borderLimit || command >= lengthArray) {
					cout << "Введите значение от " << borderLimit << " до " << lengthArray - 1 << endl;
					system("pause");
				}
				else if (pMethod[command - 1] == EXIT_FUNCTION) {
					break;
				}
				else {
					pMethod[(command)-1]();
				}
			}
		}
	};
}
using namespace Smart;


// ТЗ классы

class Date {
	int day, month, year;
public:
	// day
	void set_day(int day) {
		this->day = day;
	}
	int& get_day() {
		return this->day;
	}
	// month
	void set_month(int month) {
		this->month = month;
	}
	int& get_month() {
		return this->month;
	}
	// year
	void set_year(int year) {
		this->year = year;
	}
	int& get_year() {
		return this->year;
	}
	friend istream& operator >> (istream& in, Date& p);
	friend ostream& operator << (ostream& os, const Date& p);
};
class Place {
	int place;
	string login;
	bool is_Free_Place;
public:

	int get_place() {
		return this->place;
	}
	string get_login() {
		return this->login;
	}
	bool get_is_Free_Place() {
		return this->is_Free_Place;
	}


	void set_place(int place) {
		this->place = place;
	}
	void set_login(string login) {
		this->login = login;
	}
	void set_is_Free_Place(bool is_Free_Place) {
		this->is_Free_Place = is_Free_Place;
	}

	friend ostream& operator << (ostream& os, const Place& p);
	friend istream& operator >> (istream& in, Place& p);
};
class Film {
private:
	string nameFilm;
	int coast, place;
	Date date;
public:


	void set_nameFilm(string nameFilm) {
		this->nameFilm = nameFilm;
	}
	string get_nameFilm() {
		return this->nameFilm;
	}
	// coast
	void set_coast(int coast) {
		this->coast = coast;
	}
	int get_coast() {
		return this->coast;
	}
	// place
	void set_place(int place) {
		this->place = place;
	}
	int get_place() {
		return this->place;
	}
	void set_date(Date date) {
		this->date = date;
	}
	Date& get_date() {
		return this->date;
	}

	void fillData() {
		system("cls");
		cout << "Введите название фильма: ";
		cin >> this->nameFilm;
		rewind(stdin);
		if (this->get_nameFilm() == fileUser || this->get_nameFilm() == fileTickets) {
			cout << "Файл с таким названием уже существует, введите другое название.\n";
			system("pause");
			return;
		}
		cout << "Введите количество мест: ";
		place = Security::securityInt();

		cout << "Введите стоимость билета: ";
		coast = Security::securityInt();
		system("cls");
		cout << "Введите дату начала\n ";
		int day, month, year;
		Security::securityDate(day, month, year);
		this->get_date().set_day(day);
		this->get_date().set_month(month);
		this->get_date().set_year(year);
	};

	friend ostream& operator << (ostream& os, const Film& film);
	friend istream& operator >> (istream& in, Film& film);
	friend class Tickets;
};
class Tickets {
	string login;
	int id;
	Film film;
public:
	// getter

	string getLogin() {
		return this->login;
	}
	Film getfilm() {
		return this->film;
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
	void set_film(Film film) {
		this->film = film;
	}

	friend ostream& operator<<(ostream& in, const Tickets& point);
	friend istream& operator>>(istream& out, Tickets& point);
	friend class Database;
};

// умное меню


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

			for (j = i - step; j >= 0 && (arr[j].*field)() > (tmp.*field)(); j -= step) {
				arr[j + step] = arr[j];
			}
			arr[j + step] = tmp;

		}
		step /= 2;
	}
}

void searchFilm();
// -------------------------------------------------------------------------------------------------------------------------------------------------------


// ГЛАВНОЕ МЕНЮ
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("cls");
	vector<TYPE_METHOD> pFuncArray = { &SmartMenu::Guest::log_in_account ,&SmartMenu::Guest::reg_an_account, EXIT_FUNCTION };
	string menu_description = "Главное меню\n\n1) Авторизация\n2) Регистрация\n3) Выход из системы\n";
	SmartMenu::createMenu(menu_description, pFuncArray);
	return 0;
}


// -------------------------------------------------------------------------------------------------------------------------------------------------------

// Перегрузки
ostream& operator<<(ostream& out, const User& user)
{

	out << user.id << "\n" << user.login << "\n" << user.password << "\n" << static_cast<int>(user.role) << endl;
	return out;
}
istream& operator>>(istream& in, User& point)
{
	int temporary;
	in >> point.id;
	in >> point.login;
	in >> point.password;
	in >> temporary;
	point.role = static_cast<Role>(temporary);
	return in;
}
ostream& operator<<(ostream& out, Client& client)
{
	Client::User user = client;
	out << user;
	return out;
}
istream& operator>>(istream& in, Client& client)
{
	Client::User user = client;
	in >> user;
	return in;
}


ostream& operator << (ostream& os, const Film& p)
{
	return os << p.nameFilm << "\n" << p.place << "\n" << p.coast << "\n" << p.date;
}
istream& operator >> (istream& in, Film& p)
{
	return in >> p.nameFilm >> p.place >> p.coast >> p.date;
}

ostream& operator << (ostream& os, const Place& p)
{
	return os << p.place << "\n" << p.is_Free_Place << "\n" << p.login << endl;
}
istream& operator >> (istream& in, Place& p)
{
	return in >> p.place >> p.is_Free_Place >> p.login;
}

ostream& operator<<(ostream& in, const Tickets& point) {
	return in << point.id << "\n" << point.login << "\n" << point.film << endl;
}
istream& operator>>(istream& out, Tickets& point) {
	return out >> point.id >> point.login >> point.film;
}

ostream& operator << (ostream& os, const Date& p)
{
	return os << p.day << "\n" << p.month << "\n" << p.year << endl;
}
istream& operator >> (istream& in, Date& p)
{
	return in >> p.day >> p.month >> p.year;
}

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
		file.findOne(fileUser, &User::get_login, user.get_login(), user);
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

			cout << "С возвращением, мы рады вас видеть!\n";
			session.login = user.get_login();
			session.password = user.get_password();
			session.role = user.get_role();


			system("pause");
			system("cls");

			checkRole(user.get_role());



			session.login = "";
			session.password = "";
			session.role;
			cout << "Вы вышли из аккаунта\n";
			system("pause");
			break;
		}

	}
}
void Guest::checkRole(Role roleFromDb) {
	ClientMenu clientMenu;
	AdminMenu adminMenu;

	vector<IMenu*> roleList = { &clientMenu, &adminMenu };

	for (int i = 0; i < roleList.size(); i++)
	{
		if (roleList[i]->get_status() == roleFromDb) {
			IMenu* ptr;
			ptr = roleList[i];
			ptr->showMenu();
			break;
		}

	}
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

	system("pause");

}

// FILMS
void Admin::add_Film() {

	Film film;
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
	cout << "Фильм успешно добавлен\n";

};

// Tickets				// TODO
void Client::buyTicket() {
	Film film;
	Tickets ticket;
	system("cls");
	cout << "Введите название фильма: ";
	string desired_film_name;
	cin >> desired_film_name;
	rewind(stdin);




	if (!file.findOne(fileFilms, &Film::get_nameFilm, desired_film_name, film) || !file.is_file_exist(desired_film_name + ".txt")) {
		cerr << "Такого фильма нет!\n";
		system("pause");
		return;
	}


	cout << "Информация о фильме:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "|       Название фильма         |      Всего мест       |   Стоимость билета   |" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "|" << std::setw(31) << film.get_nameFilm() << "|" << setw(23) << film.get_place()
		<< "|" << setw(22) << film.get_coast() << "|" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	// Загружаем данные
	vector<Place> places;
	file.findAll(desired_film_name + ".txt", places);



	int count_free_place = 0;
	cout << "Свободные места: ";
	for (size_t i = 0; i < places.size(); i++)
	{
		if (!places[i].get_is_Free_Place()) {
			count_free_place++;
			cout << places[i].get_place() << " | ";
		}

	};
	system("pause");

	if (count_free_place == 0) {
		cout << "Свободных мест нет!\n";
		system("pause");
		return;
	}
	;
	int selected_Place;
	while (true) {
		system("cls");
		cout << "Выберите свободное место(выход: -1): ";
		selected_Place = Security::securityInt() - 1;
		if (selected_Place == -2) {
			return;
		}
		if (selected_Place < 0 || selected_Place >(places.size()) - 1) {
			cout << "Такого места нет!\n";

		}
		else if (places[selected_Place].get_is_Free_Place()) {
			cout << "Это место занятно!!!";
		}
		else {
			places[selected_Place].set_is_Free_Place(true);
			places[selected_Place].set_login(session.login);
			file.update(desired_film_name + ".txt", places);
			break;
		}
		system("pause");
	}
	film.set_place(selected_Place + 1);
	ticket.set_login(session.login);
	file.getUnicSeed(fileTickets, ticket);
	ticket.set_film(film);
	// Запись
	file.create(fileTickets, ticket);

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
			AdminMenu::showAllTickets();
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

		cout << "|" << setw(7) << Users[i].get_id() << " |" << setw(20) << Users[i].get_login() << " |" << setw(35) << Users[i].get_password()
			<< " |" << setw(11) << Users[i].get_role() << " |" << endl;
	}
	cout << "----------------------------------------------------------------------------------" << endl;


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
		cout << "|" << std::setw(31) << Films[i].get_nameFilm() << "|" << setw(23) << Films[i].get_place()
			<< "|" << setw(22) << Films[i].get_coast() << "|" << endl;
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
		if (Place[i].get_is_Free_Place()) {
			status = "Занято";
			countNotFree++;
		}
		else {
			status = "Свободно";
			countFree++;
		}
		if (Place[i].get_login() == "NONE") {
			login = "Нет";
		}
		else {
			login = Place[i].get_login();
		}
		cout << "|" << std::setw(26) << Place[i].get_place() << " |" << setw(24) << status
			<< " |" << setw(28) << login << " |" << endl;
	}
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Свободно мест: " << countFree << endl;
	cout << "Занято мест: " << countNotFree << endl;

	Place.clear();
}
void AdminMenu::showAllTickets() {
	system("cls");
	vector<Tickets> tickets;

	file.findAll(fileTickets, tickets);
	cout << "Список всех моих билетов:" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "|    Название фильма     |     Место      |   Логин зрителя   |  Стоимость билета   | Дата начала  |" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;


	bool isOneFilm = false;
	for (size_t i = 0; i < tickets.size(); i++) {
		isOneFilm = true;
		Film film = tickets[i].getfilm();
		cout << "|" << setw(23) << film.get_nameFilm() << " |" << setw(15) << film.get_place() << " |"
			<< setw(18) << tickets[i].getLogin() << " |"
			<< setw(20) << film.get_coast() << " |" << setw(5) << film.get_date().get_day() << "." << film.get_date().get_month() << "." << film.get_date().get_year() << " |" << endl;
	}
	cout << "-------------------------------------------------------------------------------------------------------" << endl;


	if (isOneFilm == false) {
		system("cls");
		cout << "Билеты отстутствуют. Плохо работаете!\n";
	}

	system("pause");
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
		Admin admin;
		int command = Security::securityInt();
		if (command == 1) {
			admin.createUser();
			system("pause");
		}
		else if (command == 2) {
			admin.add_Film();
			system("pause");
		}
		else if (command == 3) {
			break;
		}

	}
}
void Admin::createUser() {
	system("cls");
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
	cout << "Вы создали нового пользователя\n";

}

// Three command
void AdminMenu::ShowMenuEdit() {
	system("cls");
	vector<TYPE_FUNCTION> pArrayFunc = { &Admin::editUserRole ,&Admin::editUserLogin, &Admin::editFilmName, EXIT_FUNCTION };
	string menu_description = "Редактирование данных\n\n1) Изменить роль пользователя\n2) Изменить логин пользователя\n3) Изменить название фильма\n4) Вернуться назад\n";
	SmartMenu::createMenu(menu_description, pArrayFunc);
}
void Admin::editUserRole() {
	system("cls");
	User user;
	cout << "Редактирование роли пользователя\n\n";

	cout << "Введите логин пользователя: ";
	string desiredUser;
	cin >> desiredUser;
	rewind(stdin);
	bool isResult_Find = file.findOne(fileUser, &User::get_login, desiredUser, user);
	if (!isResult_Find) {
		cout << "В базе данных нет такого пользователя.\n";
		system("cls");
		return;
	}
	Role roleFromDb = user.get_role();

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
		if (roleFromDb == user.get_role()) {
			cout << "У пользователя уже и есть такая роль. Выберите другую или отмените редактирование.\n";
			system("pause");
		}
	}

	vector<User> users;
	file.findAll(fileUser, users);
	for (size_t i = 0; i < users.size(); i++) {
		if (users[i].get_login() == user.get_login()) {
			users[i].set_role(user.get_role());
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
void Admin::editUserLogin() {
	system("cls");
	User user;
	cout << "Редактирование логина пользователя\n\n";

	cout << "Введите логин пользователя: ";
	string desiredUser;
	cin >> desiredUser;
	rewind(stdin);

	bool isResult_Find = file.findOne(fileUser, &User::get_login, desiredUser, user);
	if (!isResult_Find) {
		cout << "В базе данных нет такого пользователя.\n";
		system("pause");
		
		return;
	}

	cout << "Введите новый логин: ";
	string newLoginUser;
	cin >> newLoginUser;
	rewind(stdin);



	bool isExist_new_login = file.findOne(fileUser, &User::get_login, newLoginUser, user);
	if (isExist_new_login) {
		cout << "В базе данных уже есть пользователь с таким логином.\n";
		system("pause");
		return;
	}
	vector<User> users;
	file.findAll(fileUser, users);
	for (size_t i = 0; i < users.size(); i++) {
		if (user.get_login() == users[i].get_login()) {
			users[i].set_login(newLoginUser);
			cout << "Логин успешно изменен.\n";
			system("pause");
			break;
		}
	}
	// перезапись в файл
	file.update(fileUser, users);


	users.clear();
}
void Admin::editFilmName() {
	system("cls");
	Film film;
	Place place;


	cout << "Введите название фильма\n";
	string current_name_film, newNameFilm;
	cin >> current_name_film;
	rewind(stdin);

	// Поиск текущего фильма
	if (!file.findOne(fileFilms, &Film::get_nameFilm, current_name_film, film) && !file.is_file_exist(current_name_film + ".txt")) {
		cout << "Фильм не найден\n";
		system("pause");
		return;
	}
	cout << "Введите новое название фильма\n";
	cin >> newNameFilm;
	rewind(stdin);
	//  Поиск существующего фильма
	if (file.findOne(fileFilms, &Film::get_nameFilm, newNameFilm, film)) {
		cout << "Такой фильм уже есть, введите другое название фильма\n";
		system("pause");
		return;
	}

	vector<Film> films;
	file.findAll(fileFilms, films);
	vector<Place> Places;
	file.findAll(current_name_film + ".txt", Places);

	for (size_t i = 0; i < films.size(); i++) {
		if (films[i].get_nameFilm() == current_name_film) {
			cout << "Фильм был успешно изменен.\n";
			films[i].set_nameFilm(newNameFilm);
			break;
		}
	}
	if (remove((current_name_film + ".txt").c_str())) {
		cout << "Ошибка перезаписи файла\n";
		system("pause");
		return;
	}
	file.update(fileFilms, films);
	file.update(newNameFilm + ".txt", Places);

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
			Admin::deleteUser();
			system("pause");
		}
		else if (command == 2) {
			system("cls");
			Admin::deleteFilm();
			system("pause");
		}
		else if (command == 3) {
			break;
		}

	}
}
void Admin::deleteUser() {
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
		if (Users[i].get_login() == loginUser && Users[i].get_role() == ADMIN) {
			is_Find_User = true;
			cout << "Вы не можете удалить администратора!\n";
			break;
		}
		if (Users[i].get_login() == loginUser && Users[i].get_role() != ADMIN) {
			Users.erase(Users.begin() + i);
			is_Find_User = true;
			// Перезапись
			file.update(fileUser, Users);
			cout << "Пользователь был успешно удален!\n";
			break;
		}
	}
	if (!is_Find_User) {
		cout << "Пользователь " << loginUser << " не был найден.\n";
	}
}
void Admin::deleteFilm() {
	vector<Film> Films;
	string desired_movie_name;


	cout << "Удаление Фильма\n\n";
	cout << "Введите название фильма: ";
	cin >> desired_movie_name;
	rewind(stdin);
	file.findAll(fileFilms, Films);

	bool is_One_foun_film = false;
	for (size_t i = 0; i < Films.size(); i++) {

		if (Films[i].get_nameFilm() == desired_movie_name) {
			Films.erase(Films.begin() + i);
			is_One_foun_film = true;

			// Перезапись
			file.update(fileFilms, Films);

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
	vector<TYPE_FUNCTION> pArrayFunc = { &AdminMenu::sortLoginUser ,&AdminMenu::sortNameFilm, &AdminMenu::sortFilmDate,EXIT_FUNCTION };
	string menu_description = "Сортировка данных\n\n1) Сортировать пользователей по логину\n2) Сортировать название фильмов\n3) Сортировать билеты по дате\n4) Вернуться назад\n";
	SmartMenu::createMenu(menu_description, pArrayFunc);

}
void AdminMenu::sortLoginUser() {
	system("cls");
	User user;
	vector <User> Users;
	file.findAll(fileUser, Users);

	SortShell(Users, &User::get_login);
	cout << "Список всех пользователей:" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "|   ID   |       Логин         |            Пароль                  |   Статус   |" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Users.size(); i++) {

		cout << "|" << setw(7) << Users[i].get_id() << " |" << setw(20) << Users[i].get_login() << " |" << setw(35) << Users[i].get_password()
			<< " |" << setw(11) << Users[i].get_role() << " |" << endl;
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
	//SortShell(Films, &Film::nameFilm); // TODO
	cout << "Список всех фильмов:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "|       Название фильма         |      Всего мест       |   Стоимость билета   |" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	bool isResult_Find_of_film = false;
	for (size_t i = 0; i < Films.size(); i++) {
		isResult_Find_of_film = true;

		cout << "|" << setw(31) << Films[i].get_nameFilm() << "|" << setw(23) << Films[i].get_place()
			<< "|" << setw(22) << Films[i].get_coast() << "|" << endl;
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
			if (Films[i].get_date().get_day() < Films[j].get_date().get_day() && Films[i].get_date().get_month() < Films[j].get_date().get_month() && Films[i].get_date().get_year() < Films[j].get_date().get_year()) {
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
		cout << "|" << setw(31) << Films[i].get_nameFilm() << "|"
			<< setw(23) << Films[i].get_place()
			<< "|" << setw(21) << Films[i].get_coast() << " |"
			<< setw(8) << Films[i].get_date().get_day() << "." << Films[i].get_date().get_month() << "." << Films[i].get_date().get_year() << " |"
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

// Проверки
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
	if (!password.empty()) {
		return;
	}
	else if (password == "") {
		cout << "Пароль не может быть пустым!\n";
		cout << "Введите пароль еще раз: ";
		InputPassword(password);
	}
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

// Конструктор по умолчанию
Admin::Admin() {
	this->set_role(ADMIN);
}

// Возможности Юзера
void Client::show_Free_Place_On_Film() {
	system("cls");
	cout << "Список свободных мест\n\n";
	vector<Film> Films;
	vector<Place> Places;

	file.findAll(fileFilms, Films);
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|   Кол-во свободных мест   |      Название фильма       |      Дата начала фильма     |" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Films.size(); i++) {
		file.findAll(Films[i].get_nameFilm() + ".txt", Places);
		int countFree = 0;
		for (size_t i = 0; i < Places.size(); i++) {
			if (!Places[i].get_is_Free_Place()) {
				countFree++;
			}
		}
		cout << "|" << std::setw(26) << countFree << " |" << setw(27) << Films[i].get_nameFilm()
			<< " |" << setw(20) << Films[i].get_date().get_day() << "." << Films[i].get_date().get_month() << "." << Films[i].get_date().get_year() << " |" << endl;
		Places.clear();
	}

	cout << "----------------------------------------------------------------------------------------" << endl;

	system("pause");
}
void Client::show_my_Tickets() {
	system("cls");
	cout << "Мои билеты\n\n";

	file.findAll(fileTickets, tickets);

	cout << "Список всех моих билетов:" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "|    Название фильма     |     Место      |   Стоимость билета   | Дата начала  |" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;

	bool isOneFilm = false;
	for (size_t i = 0; i < tickets.size(); i++) {
		if (tickets[i].getLogin() == session.login) {
			isOneFilm = true;
			Film film = tickets[i].getfilm();
			cout << "|" << setw(23) << film.get_nameFilm() << " |" << setw(15) << film.get_place() << " |" << setw(21) << film.get_coast() << " |" << setw(5) << film.get_date().get_day() << "." << film.get_date().get_month() << "." << film.get_date().get_year() << " |" << endl;
		}
	}
	cout << "---------------------------------------------------------------------------------" << endl;

	if (isOneFilm == false) {
		system("cls");
		cout << "У вас нет никаких билетов!\n";
	}
	cout << endl;
	system("pause");
	tickets.clear();
}
Client::Client() {
	this->set_role(USER);
}

// Меню Юзера
void ClientMenu::showPunktMenu() {
	cout << "1)Купить билет\n";
	cout << "2)Посмотреть свободные места на фильм\n";
	cout << "3)Мои билеты\n";
	cout << "4)Поиск фильма\n";
	cout << "5)Выйти из аккаунта\n";
	cout << "Выберите пункт: ";
}
bool ClientMenu::showChecks(int command) {
	bool isResult = true;
	if (command == 1) {
		Client client;
		client.buyTicket();
	}
	else if (command == 2) {
		Client::show_Free_Place_On_Film();
	}
	else if (command == 3) {
		Client client;
		client.show_my_Tickets();
	}
	else if (command == 4) {
		searchFilm();
	}
	else if (command == 5) {
		isResult = false;
		return isResult;
	}

	return isResult;
}
void ClientMenu::showMenu() {
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ_____________\n\n" << endl;
		this->showPunktMenu();
		int command = Security::securityInt();
		flag = this->showChecks(command);
	}
}

// Меню Админа
void AdminMenu::showPanelAdmin() {
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
		cout << "6) Поиск пользователя по логину\n";
		cout << "7) Войти в пользовательский режим\n";
		cout << "8) Выйти из cистемы\n";
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
			AdminMenu::searchUser();
		}
		else if (command == 7)
		{
			break;
		}
		else if (command == 8) // Выход из аккаунта
		{
			system("cls");
			cout << "Вы вышли из системы\n";
			exit(1);
		}

	}

}
bool AdminMenu::showChecks(int command) {


	if (command == 0) {
		this->showPanelAdmin();
	}
	bool isReult = ClientMenu::showChecks(command);
	return isReult;
}
void AdminMenu::showMenu() {
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ / АДМИНА_____________\n\n" << endl;
		this->showPunktMenu();

		int command = Security::securityInt();
		flag = this->showChecks(command);



	}
}
void AdminMenu::showPunktMenu() {
	cout << "0)Перейти в панель администратора\n";
	ClientMenu::showPunktMenu();
}

void AdminMenu::searchUser() {

	vector<User> users;

	cout << "Введите логин пользователя: ";
	string login;
	cin >> login;
	rewind(stdin);
	file.findAll(fileUser, users);
	bool isResult = false;
	for (size_t i = 0; i < users.size(); i++) {
		if (login == users[i].get_login()) {
			isResult = true;
			cout << "Список всех пользователей\n" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << "|      Логин      |      Пароль      |   Статус   |" << endl;
			cout << "---------------------------------------------------" << endl;


			cout << "|" << setw(16) << users[i].get_login() << " |" << setw(17) << users[i].get_password()
				<< " |" << setw(11) << users[i].get_role() << " |" << endl;

			cout << "---------------------------------------------------" << endl;
			system("pause");
			return;
		}
	}
	if (!isResult) {
		cout << "Такого аккаунта нет!\n";
		system("pause");
	}


}


void searchFilm() {
	system("cls");
	cout << "Введите название фильма: ";
	Film film;
	string nameFilm;
	cin >> nameFilm;
	rewind(stdin);
	bool isResult = file.findOne(fileFilms, &Film::get_nameFilm, nameFilm, film);

	if (!isResult) {
		cout << "Ничего о фильме <" << nameFilm << "> не было найдено\n";
		system("pause");
		return;
	}

	cout << "Информация о фильме <" << nameFilm << ">" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|       Название фильма         |      Свободных мест       |   Стоимость билета   |    Дата начала фильма    |" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;

	cout << "|" << setw(31) << film.get_nameFilm()
		<< "|" << setw(27) << film.get_place() <<
		"|" << setw(22) << film.get_coast() << "|" << setw(18) << film.get_date().get_day() << "." << film.get_date().get_month() << "." << film.get_date().get_year() << " |" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;

	system("pause");
}
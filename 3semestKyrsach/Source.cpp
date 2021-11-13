#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream> // Файлы
#include <string>
#include <stdio.h>
#include <vector>


// Отключение ошибок
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;


#define fileUser "Users.txt"

// Проверки
int securityInt();
string securityString();
void InputPassword(string& password);





class User {
private:
	
public:
	string login, role, password;
	int id;
	

	virtual void showMenu() {
		while (true) {
			system("cls");
			cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ_____________\n\n" << endl;
			this->showPunktMenu();
			int command;
			command = securityInt();
			if (command == 1) {

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
		cout << "1)Купить билет\n";
		cout << "2)Посмотреть свободные места на фильм\n";
		cout << "3)Мои билеты\n";
		cout << "4)Выйти из аккаунта\n";
		cout << ">>> ";

	}
	
	void inputData() {
		cout << "Ввод данных\n\n";
		cout << "Введите Login: ";
		cin >> this->login;
		cout << "Введите Password: ";
		cin >> this->password;
	}

	
};
class Admin: public User{
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
			cout << "7) Выйти из аккаунта\n";
			cout << "Введите номер команды: ";
			int command;
			cin >> command;
			rewind(stdin);
			switch (command)
			{
			case 1: // Отобразить список 
				cout << "1";
				break;
			case 2: // Добавить данные
				cout << "2";
				break;
			case 3: // Редактировать данные
				cout << "3";
				break;
			case 4: // Удаление данных
				cout << "4";
				break;
			case 5: // Соритровка данных
				cout << "5";
				break;
			case 6:
				showMenu();
				break;
			case 7:
				system("cls");
				cout << "Вы вышли из системы\n";
				exit(1);
			}
		}

	}
public:
	virtual void showMenu() {
		while (true) {
			system("cls");
			cout << "_____________________ГЛАВНОЕ МЕНЮ ПОЛЬЗОВАТЕЛЯ_____________\n\n" << endl;
			cout << "0)Перейти в панель администратора\n";
			User::showPunktMenu();
			int command;
			command = securityInt();
			if (command == 0) {
				this->showPanelAdmin();
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
};
class Date {
	int day, month, year;
public:
	
	void setDate() {
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
	void show() {
		cout << this->day << "." << this->month << "." << this->year << endl;
	}
};
class Films {
private:
	string nameFilm;
	int places, id;
public:
	void createFilm() {
		
	}
	
};
class Security {
private:
	int res;
	string text;
public:
	int securityInt() {

		while (!(cin >> this->res) || ((getchar()) != '\n')) {
			rewind(stdin);
			cin.clear();
			cout << "Введите другое\n";
		}
		return this->res;
	}
	string securityString() {
		while (true) {
			int flag = 0;
			cin >> this->text;
			rewind(stdin);
			for (int i = 0; i < this->text.length(); i++) {
				if (isdigit(this->text[i])) {
					flag = 1;
					cin.clear();
					cout << "Строка не должна содержать символы!\n";
					cout << "Введите еще раз: ";
					break;
				}
			}
			if (flag == 0) break;
		}
		return this->text;
	}
};

class Tickets : public Films{
private:
	string login; 
	string film;
	int place; 
	Date date;
public:
	void buyTickets(string* login, string* film, int* place, Date* date) {
		
	}
};
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

class FileAction {
public:
	template<class T>
	void findAll(string nameFile, vector<T>& new_operations) {
		ifstream fileRead(nameFile);
		T obj;
		while (fileRead >> obj) {
			new_operations.push_back(obj);
		}
		fileRead.close();
	}
	template<class T>
	void create(string nameFile, T& obj) {
		fstream fileWrite(nameFile, ios::app);
		fileWrite << obj;
		fileWrite.close();
	}
	template<class T, typename T2, class T3>
	bool findOne(string nameFile, T2 T::* method, T3 value, T& saveObj) {
		ifstream fileRead(nameFile);
		T obj;
		if (!fileRead.is_open()) {
			cout << "Ошибка открытия файла\n";
			fileRead.close();
			return false;
		}
		while (fileRead >> obj) {
			if (obj.*method == value) {
				saveObj = obj;
				break;
			}
		}
		fileRead.close();
		return true;
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

};





// Регистрация
void regAccount();

// Авторизация
void authUser();

// Перегрузка
ostream& operator<<(ostream& out, const User& user);
istream& operator>>(istream& in, User& point);

// ГЛАВНОЕ МЕНЮ
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("cls");
	

	while (true) {
		system("cls");
		cout << "Главное меню\n\n";
		cout << "1) Авторизация\n";
		cout << "2) Регистрация\n";
		cout << "3) Выход из системы\n";
		cout << "Введите номер команды: ";
		int command;
		cin >> command;
		rewind(stdin);
		switch (command)
		{
		case 1:
			authUser();
			break;
		case 2:
			regAccount();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "Вы вышли из системы\n";
			return 0;
			break;
		}
	}



	return 0;
}

ostream& operator<<(ostream& out, const User& user)
{
	out << user.id << "\n" << user.login << "\n" << user.password << "\n" << user.role<<endl;
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

// Авторизация
void authUser() {

	int countTry = 3;

	while (countTry > 0) {
		SmartPointer<User> userLogin = new User;
		SmartPointer<User> user = new User;
		FileAction file;


		system("cls");
		cout << "Авторизация\n\n" << endl;
		rewind(stdin);
		cout << "Введите Login: ";
		userLogin->login = securityString();
		rewind(stdin);
		cout << "Введите Password: ";
		InputPassword(userLogin->password);


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
			system("pause");
			system("cls");

			if (user->role == "USER") {
			
				User user;
				user.showMenu();
			}
			else if (user->role == "ADMIN") {
				Admin admin;
				admin.showMenu();
			}
			cout << "Вы вышли из аккаунта\n";
			system("pause");
			break;
		}

	}
}

// Регистрация
void regAccount() {
	FileAction file;
	SmartPointer<User> user = new User;
	SmartPointer<User> userExist = new User;

	cout << "РЕГИСТРАЦИЯ\n\n";
	cout << "Введите ваш будующий логин: ";
	cin >> user->login;
	rewind(stdin);
	cout << "Введите надежный пароль: ";
	InputPassword(user->password);

	file.findOne(fileUser, &User::login, user->login, *userExist);
	if (userExist->login != user->login && user->password != userExist->password) {
		file.getUnicSeed(fileUser, *user);
		if (user->id == 0) {
			user->role = "ADMIN";
		}
		else {
			user->role = "USER";
		}
		cout << *user;
		file.create(fileUser, *user);
	}
	else {
		cout << "Аккаунт с таким логином уже существует!\n";
	}


}





// Проверки
int securityInt() {
	int res;
	while (!(cin >> res) || ((getchar()) != '\n')) {
		rewind(stdin);
		cin.clear();
		cout << "Введите другое\n";
	}
	return res;
}
string securityString() {
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
void InputPassword(string& password)
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

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream> // �����
#include <string>
#include <stdio.h>
#include <vector>
#include <iomanip>


// ���������� ������
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;


#define fileUser "Users.txt"
#define fileFilms "FilmList.txt"
#define fileTickets "Tickets.txt"






// ����
static class AdminMenu
{
public:
	static void ShowMenuAdd();
	static void ShowMenuDelete();
	static void showAboutFilm();
	static void showAllFilm();
	static void showAllUser();
	static void ShowMenuData();
};
// ������ ����������
static class Security {
private:
	int res;
	string text;
public:
	// ��������
	static void InputPassword(string& password);
	static string securityString();
	static int securityInt();
};

// ��������� ���� ������
class User {
private:

public:
	string login, role, password;
	int id;


	virtual void showMenu() {
		while (true) {
			system("cls");
			cout << "_____________________������� ���� ������������_____________\n\n" << endl;
			this->showPunktMenu();
			int command;
			command = Security::securityInt();
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
		cout << "1)������ �����\n";
		cout << "2)���������� ��������� ����� �� �����\n";
		cout << "3)��� ������\n";
		cout << "4)����� �� ��������\n";
		cout << ">>> ";

	}

	void inputData() {
		cout << "���� ������\n\n";
		cout << "������� Login: ";
		cin >> this->login;
		cout << "������� Password: ";
		cin >> this->password;
	}


};
class Admin : public User {
private:
	void showPanelAdmin() {
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
			switch (command)
			{
			case 1: // ���������� ������ 
				AdminMenu::ShowMenuData();
				break;
			case 2: // �������� ������
				AdminMenu::ShowMenuAdd();
				break;
			case 3: // ������������� ������
				cout << "3";
				break;
			case 4: // �������� ������
				AdminMenu::ShowMenuDelete();
				break;
			case 5: // ���������� ������
				cout << "5";
				break;
			case 6:
				showMenu();
				break;
			case 7:
				system("cls");
				cout << "�� ����� �� �������\n";
				exit(1);
			}
		}

	}
public:
	virtual void showMenu() {
		while (true) {
			system("cls");
			cout << "_____________________������� ���� ������������_____________\n\n" << endl;
			cout << "0)������� � ������ ��������������\n";
			User::showPunktMenu();
			int command;
			command = Security::securityInt();
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
			cout << "������� ����: ";
			day = Security::securityInt();
			cout << "������� �����: ";
			month = Security::securityInt();
			cout << "������� ���: ";
			year = Security::securityInt();


			if ((day >= 0 && day <= 31) && (month >= 0 && month <= 12) && (year >= 1900 && year <= 2021)) {
				break;
			}
			else {
				cout << "������ � ����!\n";
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

// ������
struct SessionHandler {
	string login;
	string password;
	string role;
}session;


// ����� ���������
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

// ������ � �������
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
			cout << "������ �������� �����\n";
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
	bool is_file_exist(const string& fileName)
	{
		ifstream infile(fileName);
		bool res = infile.good();
		cout << res << endl;
		infile.close();
		return res;
	};
};
FileAction file;


// �� ������
class Film {
public:
	string nameFilm;
	int coast;
	int place;
	void addFilm();
};
class Place {
public:
	int place;
	string login;
	bool is_Free_Place;
};
class Tickets : public Film {
public:
	string login;
	string nameFilm;
	string place;
	int id;

	void buyTicket();
};

// �����������
void regAccount();

// �����������
void authUser();

// ����������
ostream& operator<<(ostream& out, const User& user);
istream& operator>>(istream& in, User& point);

ostream& operator << (ostream& os, const Film& p);
istream& operator >> (istream& in, Film& p);

ostream& operator << (ostream& os, const Place& p);
istream& operator >> (istream& in, Place& p);

ostream& operator << (ostream& os, const Tickets& p);
istream& operator >> (istream& in, Tickets& p);


// -------------------------------------------------------------------------------------------------------------------------------------------------------



// ������� ����
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("cls");


	while (true) {
		system("cls");
		cout << "������� ����\n\n";
		cout << "1) �����������\n";
		cout << "2) �����������\n";
		cout << "3) ����� �� �������\n";
		cout << "������� ����� �������: ";
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
			cout << "�� ����� �� �������\n";
			return 0;
			break;
		}
	}



	return 0;
}

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
	return os << p.nameFilm << "\n" << p.place << "\n" << p.coast << endl;
}
istream& operator >> (istream& in, Film& p)
{
	return in >> p.nameFilm >> p.place >> p.coast;
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
	return os << p.id << "\n" << p.login << "\n" << p.nameFilm << "\n" << p.place << endl;
}
istream& operator >> (istream& in, Tickets& p)
{
	return in >> p.id >> p.login >> p.nameFilm >> p.place;
}

// �����������
void authUser() {

	int countTry = 3;

	while (countTry > 0) {
		SmartPointer<User> userLogin = new User;
		SmartPointer<User> user = new User;
		FileAction file;


		system("cls");
		cout << "�����������\n\n" << endl;
		rewind(stdin);
		cout << "������� Login: ";
		userLogin->login = Security::securityString();
		rewind(stdin);
		cout << "������� Password: ";
		Security::InputPassword(userLogin->password);


		// ��������
		file.findOne(fileUser, &User::login, userLogin->login, *user);

		if (user->password == "" || user->password != userLogin->password) {
			countTry--;
			cout << "�� ����� �������� ����� ��� ������! � ��� �������� " << countTry << " �������." << endl;
			if (countTry == 0) {
				cout << "�� ��������� ����� ������� :(" << endl;
				cout << "�� ���� �������������� �� 5 ������\n" << endl;
				Sleep(5000);
			}
			system("pause");
		}
		else if (userLogin->password == user->password) {
			cout << "�� ����� ��� " << user->role << endl;
			session.login = user->login;
			session.password = user->password;
			session.role = user->role;

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
			session.login = "";
			session.password = "";
			session.role = "";
			cout << "�� ����� �� ��������\n";
			system("pause");
			break;
		}

	}
}

// �����������
void regAccount() {
	FileAction file;
	SmartPointer<User> user = new User;
	SmartPointer<User> userExist = new User;

	cout << "�����������\n\n";
	cout << "������� ��� �������� �����: ";
	cin >> user->login;
	rewind(stdin);
	cout << "������� �������� ������: ";
	Security::InputPassword(user->password);

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
		cout << "������� � ����� ������� ��� ����������!\n";
	}


}

// FILMS
void Film::addFilm() {
	cout << "������� �������� ������: ";
	cin >> nameFilm;
	rewind(stdin);

	cout << "������� ���������� ����: ";
	place = Security::securityInt();

	cout << "������� ��������� ������: ";
	coast = Security::securityInt();

	FileAction file;
	string nameFile = nameFilm + ".txt";
	if (file.is_file_exist(nameFile)) {
		cout << "����� ����� ��� ����������!\n";
		return;
	};

	ofstream inFile(nameFile);
	for (int i = 1; i <= place; i++) {
		inFile << i << "\n" << false << "\n" << "NONE\n";
	}
	inFile.close();

	file.create(fileFilms, *this);
	cout << "����� ������� ��������\n";

};

// Tickets
void Tickets::buyTicket() {
	FileAction file;
	Tickets ticket;
	Film film;

	system("cls");
	cout << "������� �������� ������:";
	cin >> this->nameFilm;
	string name = this->nameFilm + ".txt";
	rewind(stdin);

	Film* isFilm = new Film;
	if (!file.findOne(fileFilms, &Film::nameFilm, nameFilm, *isFilm) || !file.is_file_exist(name)) {
		cerr << "������ ������ ���!\n";
		delete isFilm;
		return;
	}
	delete isFilm;


	vector<Place> places;
	file.findAll(name, places);
	auto iter = places.cbegin(); // ��������� �� ������ �������
	int count_free_place = 0;
	cout << "��������� �����: ";
	for (int i = 0; i < places.size(); i++)
	{
		if (!places[i].is_Free_Place) {
			count_free_place++;
			cout << places[i].place << " | ";
		}

	};
	system("pause");

	if (count_free_place == 0) {
		cout << "��������� ���� ���!\n";
		return;
	}

	this->login = session.login;
	int choosePlace;
	while (true) {
		system("cls");
		cout << "�������� ��������� �����: ";
		choosePlace = Security::securityInt() - 1;

		if (choosePlace < 0 || choosePlace >(places.size()) - 1) {
			cout << "������ ����� ���!\n";

		}
		else if (places[choosePlace].is_Free_Place) {
			cout << "��� ����� �������!!!";
		}
		else {
			places[choosePlace].is_Free_Place = true;
			places[choosePlace].login = this->login;


			ofstream fileInpute(name);

			for (int i = 0; i < places.size(); i++) {
				fileInpute << places[i];
			}
			fileInpute.close();

			cout << "�� ������ �����!!!\n";
			system("pause");
			break;
		}
		system("pause");
	}

};

// AdminMenu
void AdminMenu::ShowMenuData() {


	while (true) {
		system("cls");
		cout << "����� ������\n\n";
		cout << "1) ���������� ������ �������������\n";
		cout << "2) ���������� ������ �������\n";
		cout << "3) ���������� ������ ���� �������\n";
		cout << "4) ���������� ������ ���� �� �����\n";
		cout << "5) ��������� �����\n\n";

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
	vector<User> Users; //������ ������, ������������ ��� �������� ������� ������������

	file.findAll(fileUser, Users);
	cout << "������ ���� �������������:" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|       �����         |            ������                  |   ������   |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Users.size(); i++) {
		cout << "|" << std::setw(20) << Users[i].login << " |" << setw(35) << Users[i].password
			<< " |" << setw(11) << Users[i].role << " |" << endl;
	}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;

}
void AdminMenu::showAllFilm() {
	vector<Film> Films; //������ ������, ������������ ��� �������� ������� ������������

	file.findAll(fileFilms, Films);
	cout << "������ ���� �������:" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "|       �������� ������         |      ����� ����       |   ��������� ������   |" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Films.size(); i++) {
		cout << "|" << std::setw(31) << Films[i].nameFilm << "|" << setw(23) << Films[i].place
			<< "|" << setw(22) << Films[i].coast << "|" << endl;
	}
	cout << "--------------------------------------------------------------------------------" << endl;

	cout << endl;
	Films.clear();
}
void AdminMenu::showAboutFilm() {
	vector<Place> Place;
	cout << "������� �������� ������: ";
	string nameFilm;
	cin >> nameFilm;
	rewind(stdin);
	cout << "���������� � ������: <" << nameFilm << ">" << endl;
	int countFree = 0;
	int countNotFree = 0;

	nameFilm += ".txt";
	if (!file.is_file_exist(nameFilm)) {
		cout << "������ ������ ���!\n";
		return;
	}


	file.findAll(nameFilm, Place);

	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "|       ����� �����         |      ������ �����       |       ����� ����������      |" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	for (size_t i = 0; i < Place.size(); i++) {
		string status;
		string login;
		if (Place[i].is_Free_Place) {
			status = "������";
			countNotFree++;
		}
		else {
			status = "��������";
			countFree++;
		}
		if (Place[i].login == "NONE") {
			login = "���";
		}
		else {
			login = Place[i].login;
		}
		cout << "|" << std::setw(26) << Place[i].place << " |" << setw(24) << status
			<< " |" << setw(28) << login << " |" << endl;
	}
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "�������� ����: " << countFree << endl;
	cout << "������ ����: " << countNotFree << endl;

	Place.clear();
}
//Four command
void AdminMenu::ShowMenuDelete() {
	while (true) {
		system("cls");
		cout << "�������� ������\n\n";
		cout << "1) ������� ������������\n";
		cout << "2) ������� �����\n";
		cout << "3) ��������� �����\n\n";

		cout << ">>> ";
		int command = Security::securityInt();
		if (command == 1) {

			system("pause");
		}
		else if (command == 2) {

			system("pause");
		}
		else if (command == 3) {
			break;
		}

	}
}
//Two command
void AdminMenu::ShowMenuAdd() {
	while (true) {
		system("cls");



		cout << "���������� ������\n\n";
		cout << "1) ������� ������������\n";
		cout << "2) �������� ����� �����\n";
		cout << "3) ��������� �����\n\n";

		cout << ">>> ";
		int command = Security::securityInt();
		if (command == 1) {

			system("pause");
		}
		else if (command == 2) {
			Film film;
			film.addFilm();
			system("pause");
		}
		else if (command == 3) {
			break;
		}

	}
}


// Security
int Security::securityInt() {
	int res;
	while (!(cin >> res) || ((getchar()) != '\n')) {
		rewind(stdin);
		cin.clear();
		cout << "������� ������\n";
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
				cout << "������ �� ������ ��������� �������!\n";
				cout << "������� ��� ���: ";
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
		cout << "������� ������!\n" << endl;;
}


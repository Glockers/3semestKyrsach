#include <iostream>
#include <io.h>
#include <conio.h>
#include <windows.h>
#include <fstream> 
#include <string>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <Windows.h>
using namespace std;

#define CustomerFile "Customer.database.txt"
#define AdminFile "Admin.database.txt"

class File {
public:
	template<class Object, class TypeMethod, class any_type>
	bool findOne(const string& fileName, TypeMethod Object::* method, any_type value, Object& object) {
		ifstream fileRead(fileName);
		Object variable_object;
		bool resultFind = false;
		if (!fileRead.is_open()) {
			cout << "������ �� �������\n";
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
File file;
class Security {
private:
	int res;
	string text;
public:
	// ��������
	static void InputPassword(string& password);
	static string securityString();
	static int securityInt();
	static void securityDate(int& day, int& month, int& year);
};
class Birthday {
	int day;
	int month;
	int year;
public:

	// setter
	void set_day(int day) {
		this->day = day;
	}
	void set_month(int month) {
		this->month = month;
	}
	void set_year(int year) {
		this->year = year;
	}

	// Getter
	int get_day() {
		return this->day;
	}
	int get_set_month() {
		return this->month;
	}
	int get_year() {
		return this->year;
	}


	// friend function
	friend ostream& operator << (ostream& out, Birthday& human);
	friend istream& operator >> (istream& in, Birthday& human);
};

// Human
class Human {
	string name;
	string surname;
	string patronymic;
	Birthday birthday;
public:
	// getter
	string get_name() {
		return this->name;
	}
	string get_surname() {
		return this->surname;
	}
	string get_patronymic() {
		return this->patronymic;
	}
	Birthday get_birthday() {
		return this->birthday;
	}

	Human get_human() {
		return *this;
	}
	void set_human(Human human) {
		*this = human;
	}


	// setter
	void set_name(string name) {
		this->name = name;
	}
	void set_surname(string surname) {
		this->surname = surname;
	}
	void set_patronymic(string patronymic) {
		this->patronymic = patronymic;
	}
	void set_birthday(Birthday birthday) {
		this->birthday = birthday;
	}

	

	// friend function
	friend ostream& operator << (ostream& out, Human& human);
	friend istream& operator >> (istream& in, Human& human);
};
class User : public Human
{
private:
	string login;
	string password;
	string role;

public:

	void set_login(string login) {
		this->login = login;
	}
	void set_password(string password) {
		this->password = password;
	}
	void set_role(string role) {
		this->role = role;
	}

	string get_login() {
		return this->login;
	};
	string get_password() {
		return this->password;
	}
	string get_role() {
		return this->role;
	};


	//bool Registr(const string FileAdminHuman);
	void GetInfo();
	void SetInfo();
	void Getlogin(string login2);
	void Getpassword(int password2);

	// friend function
	friend ostream& operator << (ostream& out, User& user);
	friend istream& operator >> (istream& in, User& user);

};
class Guest {
public:
	// authorization
	void auth();
	// regist
	void reg();
};
class Session
{
private:
	string login;
	int  password;
	string role;

};
class Castomer :public User
{
	int Check;
public:

	void GetInfo();
	void SetInfo();
	bool Registr(const string FileAdminCastomer);
	void ChekHistoriBye(Session ses);
	void ByeTovar();
	void NewInfo();

	/*friend ostream& operator << (ostream& out, User& user);
	friend istream& operator >> (istream& in, User& user);*/
};
class Admin : public User
{
	string department;
public:
	Admin()
	{
		this->set_role("ADMIN");
	};

	// setter
	void set_department(string department) {
		this->department = department;
	}

	// getter
	string get_department() {
		return this->department;
	}


	void GetInfo() {};
	void SetInfo() {};
	/*friend ostream& operator << (ostream& out, Admin& admin);*/
};


// ����������� �����
class Menu {
public:
	virtual void showMenu() = 0;
};
class CustomerMenu : public Menu {
public:
	void showMenu() override
	{
		while (true) {
			system("cls");
			cout << "���� ����������\n\n";

			cout << "1) ������ �����\n";
			cout << "2) ������� �������\n";
			cout << "3) ����� ������\n";
			cout << "4) ����� ������ ������\n";
			cout << "5) ����� �� �������\n\n";

			cout << ">> ";
			int command = Security::securityInt();

			if (command == 1) {

			}
			else if (command == 2) {

			}
			else if (command == 3) {

			}
			else if (command == 4) {

			}
			else if (command == 5) {
				cout << "�� ����� �� ��������\n";
				system("pause");
				break;
			}
		}
	}
};
class AdminMenu : public CustomerMenu {
public:
	void showMenu() override
	{
		while (true) {
			system("cls");
			cout << "���� ��������������\n\n";

			cout << "1) ���������� ���� Customer'��\n";
			cout << "2) ���������� ���� ��������������� �������\n";
			cout << "3) �������� Customer'a\n";
			cout << "4) ������� Customer'a\n";
			cout << "5) �������� �������\n";
			cout << "6) ������� �������\n";
			cout << "7) �������� ����� � �������\n";
			cout << "8) ������� ����� �� ��������\n";
			cout << "9) ����� �� �������\n\n";

			cout << ">> ";
			int command = Security::securityInt();

			//1) ���������� ���� Customer'��
			if (command == 1) {

			}
			//2) ���������� ���� ��������������� �������
			else if (command == 2) {

			}
			//3) �������� Customer'a
			else if (command == 3) {

			}
			//4) ������� Customer'a
			else if (command == 4) {

			}
			// 5) �������� �������
			else if (command == 5) {

			}
			// 6) ������� �������\n
			else if (command == 6) {

			}
			//7) �������� ����� � �������
			else if (command == 7) {

			}
			//8) ������� ����� �� ��������
			else if (command == 8) {

			}
			//9) ����� �� �������
			else if (command == 9) {
				cout << "�� ����� �� ��������\n";
				system("pause");
				break;
			}
		}
	}
};

class Catalog {
	vector<string> allCatalog;
public:

};
class Goods
{
	string name;
	int cost;
public:

	/*void GetInfo();
	void SetInfo();*/

	/*friend ostream& operator << (ostream& os, Goods& p);
	friend istream& operator >> (istream& in, Goods& p);*/
};





int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	User user;
	user.set_login("admin");
	user.set_password("admin");
	user.set_role("ADMIN");
	user.set_name("Nikita");
	user.set_surname("Alisienok");
	user.set_patronymic("��_�����)");
	Birthday br;
	br.set_day(1);
	br.set_month(1);
	br.set_year(1);
	user.set_birthday(br);

	file.create("test.txt", user);

	/*while (true) {
		system("cls");
		cout << "����� ����������!\n";

		cout << "1) �����������\n";
		cout << "2) �����������\n";
		cout << "3) ����� �� �������\n\n";

		cout << ">> ";
		int command = Security::securityInt();
		Guest guest;

		if (command == 1) {
			guest.auth();
		}
		else if (command == 2) {
			guest.reg();
		}
		else if (command == 3) {
			break;
		}
	}
	return 0;*/
}

// �����������
void Guest::auth() {
	system("cls");
	User user;
	cout << "������� �����: ";
	user.set_login(Security::securityString());
};

void Guest::reg() {
	while (true) {
		system("cls");
		User newUser, resultSearch;
		cout << "������� �����: ";
		newUser.set_login(Security::securityString());
		cout << "������� ������: ";
		string password;
		Security::InputPassword(password);
		newUser.set_password(password);


		if (file.findOne(AdminFile, &User::get_login, newUser.get_login(), resultSearch)) {
			cout << "������� � ����� ������� ��� ����������!\n";
			system("pause");
		}
		else {
			newUser.set_role("USER");
			if (file.is_file_exist(CustomerFile)) {
				file.create(CustomerFile, newUser);
			}
			else {
				file.create(AdminFile, newUser);
			}
			system("cls");
			cout << "�� ������������������. ����� ��� ����������� ������ ������� � ������ �������.\n";
		}

	}
}

// ����������
ostream& operator << (ostream& out, Birthday& birthday)
{
	out << birthday.day << endl;
	out << birthday.month << endl;
	out << birthday.year << endl;
	return out;
}
istream& operator >> (istream& in, Birthday& birthday)
{
	in >> birthday.day;
	in >> birthday.month;
	in >> birthday.year;
	return in;
}

ostream& operator << (ostream& out, Human& human)
{
	out << human.name << endl;
	out << human.surname << endl;
	out << human.patronymic << endl;
	out << human.birthday << endl;
	return out;
}
istream& operator >> (istream& in, Human& human)
{
	in >> human.name;
	in >> human.surname;
	in >> human.patronymic;
	in >> human.birthday;
	return in;
}

ostream& operator << (ostream& out, User& user)
{
	User::Human h = user;
	out << user.login << endl;
	out << user.password << endl;
	out << user.role << endl;
	out << h;


	return out;
}
istream& operator >> (istream& in, User& user)
{
	Human human;
	in >> user.login;
	in >> user.password;
	in >> user.role;
	in >> human;
	user.set_human(human);
	return in;
}






// ��������
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
void Security::securityDate(int& day, int& month, int& year) {
	while (true) {
		cout << "������� ����: ";
		day = securityInt();
		cout << "������� �����: ";
		month = securityInt();
		cout << "������� ���: ";
		year = securityInt();
		if ((day >= 0 && day <= 31) && (month >= 0 && month <= 12) && (year >= 1900 && year <= 2021)) {
			break;
		}
		else {
			cout << "������ � ����!\n";
		}
	}
}
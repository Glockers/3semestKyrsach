#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream> // �����
#include <string>
#include <stdio.h>
#include <vector>


// ���������� ������
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

// ��������
int securityInt();
string securityString();
void InputPassword(string& password);





class User {
private:
	
public:
	string login, role, password;
	int id;
	// getters
	string setLogin() {
		return this->login;
	}
	string setRole() {
		return this->role;
	}
	string setPassword() {
		return this->password;
	}


	void inputData() {
		cout << "���� ������\n\n";
		cout << "������� Login: ";
		cin >> this->login;
		cout << "������� Password: ";
		cin >> this->password;
	}

	//settets
	void setLogin(string login) {
		this->login = login;
	}
	void setRole(string role) {
		this->role = role;
	}
	void setPassword(string password) {
		this->password = password;
	}
	void setId(int id) {
		this->id = id;
	}
};
class Admin: public User{
public:

};
class Date {
	int day, month, year;
public:
	
	void setDate() {
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
			cout << "������� ������\n";
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
					cout << "������ �� ������ ��������� �������!\n";
					cout << "������� ��� ���: ";
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






// �����������
void regUser();

// �����������
void authUser();

// ����������
ostream& operator<<(ostream& out, const User& user);
istream& operator>>(istream& in, User& point);

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
		cin.clear();
		switch (command)
		{
		case 1:
			authUser();
			break;
		case 2:
			regUser();
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
	out << user.id << "\n" << user.login << "\n" << user.password << "\n" << user.role;
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

// �����������
void authUser() {
	cout << "1)������ �����\n";
	cout << "2)���������� ��������� ����� �� �����\n";
	cout << "3)��� ������\n";
	cout << "4)����� �� ��������\n";
	cout << "������� ����� �������: ";
	int command;
	cin >> command;
	rewind(stdin);
	cin.clear();
	switch (command)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	case 4:
		system("cls");
		cout << "�� ����� �� �������\n";
		break;
	}


}

// �����������
void regUser() {
	User user;
	user.inputData();

}





// ��������
int securityInt() {
	int res;
	while (!(cin >> res) || ((getchar()) != '\n')) {
		rewind(stdin);
		cin.clear();
		cout << "������� ������\n";
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
				cout << "������ �� ������ ��������� �������!\n";
				cout << "������� ��� ���: ";
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
		cout << "������� ������!\n" << endl;;
}

#include "Header.h"
/*
ostream& operator << (ostream& out,User& user)
{
	out <<user.login<< "\n"<< endl;
	out << user.password << "\n" << endl;
	out << user.role << "\n" << endl;
	return out;
}
istream& operator >> (istream& in, User& user)
{
	in >> user.login;
	in >> user.password;
	in >> user.role;
	return in;
}


istream& operator >>(istream& in, Castomer& castomer)
{

}
ostream& operator<<(ostream& out, Castomer& castomer)
{

}
ostream& operator << (ostream& os, Company& p)
{
	return os << p.place << "\n" << p.is_Free_Place << "\n" << p.login << endl;
}
istream& operator >> (istream& in, Company& p)
{
	return in >> p.place >> p.is_Free_Place  p.login;
}
*/


//��������
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
// ��� ������
ostream& operator << (ostream& out, User& user)
{
	out << user.login << "\n" << endl;
	out << user.password << "\n" << endl;
	return out;
}
istream& operator >> (istream& in, User& user)
{
	in >> user.login;
	in >> user.password;
	return in;
}

ostream& operator << (ostream& out, Admin& admin)
{
	User user = User();
	out << user;
	admin.department;
	return out;
}
//istream& operator>>(istream& in, Admin& admin)
//{
//
//
//}
// ����������
ostream& operator << (ostream& os, Goods& p)
{
	return os << p.name << "\n" << p.cost;
}
istream& operator >> (istream& in, Goods& p)
{
	return in >> p.name >> p.cost;
}

//bool File::FileCreat(const string FileFileName, string& FileName)
//{
//	string FileName1 = FileName;
//	FileName1 += ".txt";
//	string object;
//	ifstream fileWrite4(FileFileName);
//	for (fileWrite4 >> object; !fileWrite4.eof(); fileWrite4 >> object) {
//		if (object == FileName1)
//		{
//			cout << "����� ����� ��� ����������";
//			return true;
//		}
//
//	}
//	ofstream fileWrite(FileName1);
//	if (!fileWrite.is_open())
//	{
//		cout << "���� �� ����� ���� ������ ��� ������\n";
//		fileWrite.close();
//		return true;
//	};
//	fstream fileWrite5(FileFileName, ios::app);
//	fileWrite5 << FileName1 << "\n";
//	fileWrite5.close();
//	return false;
//};


// ���� ����� � ������ 
void User::GetInfo()
{
	/*cout << "������� �����\n";
	this->login = c.securityString();
	cout << "������� ������\n";
	this->password = c.securityInt();
	this->role = "0";*/
};
void User::SetInfo()
{
	cout << "��� �����\n" << this->login;
	cout << "��� ������\n" << this->password;
};
void  User::Getlogin(string login2)
{
	login2 = login;
};
void User::Getpassword(int password2)
{
	//password2 = password;
};
void Castomer::GetInfo()
{
	/*User::GetInfo();
	cout << " ������� ���\n";
	this->Name = c.securityString();
	cout << " ������� �������\n";
	this->Surname = c.securityString();
	cout << "������� ��������\n";
	this->Otch = c.securityString();
	this->role = "CASTOMER";
	cout << "������� ���� ��������\n";
	c.securityDate(day, month, Year);
	cout << "������� ��� ���� � �����\n";
	this->Czet = c.securityInt();*/
};
void Castomer::SetInfo()
{
	/*cout << "��� �����\n" << this->login;
	cout << "��� ������\n" << this->password;*/
};




//Castomer
void Castomer::ChekHistoriBye(Session ses)
{
	/*string ses2;
	ses2 = ses.login + ".txt";
	vector<Tovar> tov;
	file.findAll<Tovar>(ses2, tov);
	int size = tov.size() - 1;
	for (size_t i = 0; i < size; i++)
	{
		tov[i].SetInfo();
	}*/
};
void Castomer::ByeTovar()
{


};
void Castomer::NewInfo()
{
	Castomer castomer;
};













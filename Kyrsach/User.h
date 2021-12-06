#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

enum Role
{
	USER,
	ADMIN
};
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

	User get_User() {
		return *this;
	};

	void set_User(User user) {
		*this = user;
	}

	friend ostream& operator<<(ostream& out, const User& user);
	friend istream& operator>>(istream& in, User& point);

	friend class Database;
};


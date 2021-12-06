#include "User.h"



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
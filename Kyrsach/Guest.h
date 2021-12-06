#pragma once
#include "User.h"
#include "SmartPointer.h"
#include "Security.h"
#include "Database.h"
#include <Windows.h>

#define fileUser "Users.txt"
#define fileFilms "FilmList.txt"
#define fileTickets "Tickets.txt"


extern Database db;
class Guest :
    public User
{
public:
	void showMenu(Role);
	// Регистрация
	void reg_an_account();
	// Авторизация
	void log_in_account();

};


#pragma once
#include "Client.h"
class Admin : public Client
{
public:

	// Конструктор по умолчанию
	Admin();

	// Поведение
	void add_Film();
	static void createUser();
	static void deleteFilm();
	static void deleteUser();
	static void editUserRole();
	static void	editUserLogin();
	static void editFilmName();
};


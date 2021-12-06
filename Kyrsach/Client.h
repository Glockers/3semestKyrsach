#pragma once
#include "User.h"
#include "Tickets.h"
#include "Security.h"
class Client : public User
{
private:
	vector<Tickets> tickets;

public:
	Client();
	// Μενώ
	void showMenu();
	void showPunktMenu();
	//static void buyTicket();
	//static void show_Free_Place_On_Film();
	//void show_my_Tickets();
};


#pragma once
#include "ClientMenu.h"

class AdminMenu :
    public ClientMenu
{
private:
	void showPanelAdmin();

public:
	void showHeader();
	void showPunktMenu();
	void selectCommand();
};


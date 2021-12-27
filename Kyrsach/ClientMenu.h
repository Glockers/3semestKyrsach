#pragma once
#include <iostream>
#include "IShowMainMenu.h"
#include "Security.h"
class ClientMenu :
    public IShowMainMenu
{
public:
	// Отображение главного меню
	void showHeader() override;
	void showPunktMenu();
	void selectCommand();

};


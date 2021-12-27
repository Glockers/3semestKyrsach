#pragma once

class IShowMainMenu {
public:
	virtual void showHeader() = 0;
	virtual void showPunktMenu() = 0;
	virtual void selectCommand() = 0;
};

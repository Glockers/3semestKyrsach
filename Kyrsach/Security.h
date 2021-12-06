#pragma once
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Security {
private:
	int res;
	string text;
public:
	// Проверки
	static void InputPassword(string& password);
	static string securityString();
	static int securityInt();
	static void securityDate(int& day, int& month, int& year);
};


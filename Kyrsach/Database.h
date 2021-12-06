#pragma once

#include <iostream>
#include <vector>
#include <fstream> // Файлы

using namespace std;






class Database {
public:
	template<class Object, class TypeMethod, class any_type>
	bool findOne(const string& fileName, TypeMethod Object::* method, any_type value, Object& object);
	template<class T>
	void findAll(const string& nameFile, vector<T>& savedObject);
	template<class T>
	void update(const string& fileName, vector<T>& array);
	template<class T>
	void create(const string& fileName, T& object);
	template <class T>
	void getUnicSeed(const string& nameFile, T& obj);
	template <class T>
	bool is_file_exist(const T& fileName);
};


template<class Object, class TypeMethod, class any_type>
bool Database::findOne(const string& fileName, TypeMethod Object::* method, any_type value, Object& object) {
	ifstream fileRead(fileName);
	Object variable_object;
	bool resultFind = false;
	if (!fileRead.is_open()) {
		cout << "Ничего не найдено\n";
		fileRead.close();
		return resultFind;
	}
	while (fileRead >> variable_object) {
		if ((variable_object.*method)() == value) {
			object = variable_object;
			resultFind = true;
			break;
		}
	}
	fileRead.close();
	return resultFind;
}
template<class T>
void Database::findAll(const string& nameFile, vector<T>& savedObject) {
	ifstream fileRead(nameFile);
	T varieable_object;
	while (fileRead >> varieable_object) {
		savedObject.push_back(varieable_object);
	}
	fileRead.close();
}
template<class T>
void Database::update(const string& fileName, vector<T>& array) {
	ofstream fileWrite(fileName);
	for (size_t i = 0; i < array.size(); i++) {
		fileWrite << array[i];
	};
	fileWrite.close();
};
template<class T>
void Database::create(const string& fileName, T& object) {
	fstream fileWrite(fileName, ios::app);
	fileWrite << object;
	fileWrite.close();
}
template<class T> void Database::getUnicSeed(const string& nameFile, T& obj) {
	int count = 0;
	T buffer;
	ifstream fileRead(nameFile);
	if (!fileRead.is_open()) {
		obj.id = 0;
	}
	else {
		while (fileRead >> buffer) {
			count = buffer.id;
		}
		count++;
		obj.id = count;
	}
	fileRead.close();
}
template <class T>
bool Database::is_file_exist(const T& fileName)
{
	ifstream openFile(fileName);
	bool isOpen = openFile.good();
	openFile.close();
	return isOpen;
};
#pragma once
#include <iostream>
#include <cstring>

class User
{
public:
	//Конструкторы
	User() = default;
	explicit User(const std::string name, const std::string login, const std::string password); // явное задание 
	//Деструктор
	~User(); // деструктор + освобождение выделенной памяти
	//Методы
	std::string getName();
	void setName(std::string name);
	std::string getLogin();
	void setLogin(std::string login);
	std::string getPassword();
	void setPassword(std::string password);
	void showUser();
	void showUserName();
    void clearLogin();
	void clearName();
	
private:
	std::string _name;
	std::string _login;
	std::string _password;
};

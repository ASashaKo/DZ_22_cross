#include "User.h"


User::User(const std::string name, const std::string login, const std::string password) :
	_name{ name }, _login{ login }, _password{ password } {}


User::~User()
{
	
}

std::string User::getName()
{
	return _name;
}

void User::setName(std::string name)
{
	_name = name;
}

std::string User::getLogin()
{
	return _login;
}

void User::setLogin(std::string login)
{
	_login = login;
}

std::string User::getPassword()
{
	return _password;
}

void User::setPassword(std::string password)
{
	_password = password;
}

void User::showUser()
{
	std::cout << "Name: " << _name << std::endl;
    std::cout << "Login: " << _login << std::endl;
}

void User::showUserName()
{
	std::cout << _name << std::endl;
}

void User::clearLogin()
{
	_login.clear();
}

void User::clearName()
{
	_name.clear();
}

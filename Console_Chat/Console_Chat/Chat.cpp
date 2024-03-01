#include "Chat.h"
//#include <conio.h>
//#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

#if defined(max)
#undef max
#endif

Chat::Chat()
{
	std::cout << "\nHello, welcome!!!" << "\n\n";
}

Chat::~Chat()
{

}

std::string Chat::readInput()
{
	std::string input;
	std::getline(std::cin >> std::ws, input);
	return input;
}

void Chat::userDataInput(User& user)
{
	std::cout << "Enter your name: ";

	user.setName(readInput());

	logInInput(user);
}

void Chat::logInInput(User& user)
{
	std::cout << "Enter your login: ";
	user.setLogin(readInput());

	std::cout << "Enter your password: ";
	user.setPassword(readInput());
}



void Chat::regUser(bool* userExist)
{
	User user;	
	userDataInput(user);
	bool check = true;
	isAvailable(user, check);
	if (check)
	{
		addUserToList(user);

        std::ofstream file1 ("UserList.txt", std::ios::app);
        file1 << user.getName() << '\t' << user.getLogin() << '\t' << user.getPassword() << '\r' << '\n';
        file1.close();

		std::cout << "\nYou registered as:\n";
		user.showUser();
	}
}


void Chat::logInUser(bool* userExist)
{
	User userDataCheck;
	logInInput(userDataCheck);
	*userExist = false;
	size_t counter = 0;
	for (User all : _userList)
	{
		if (userDataCheck.getLogin() == all.getLogin() && userDataCheck.getPassword() == all.getPassword())
		{
			setActiveUser(userExist ,counter, all.getName(), all.getLogin());
			std::cout << "\n\nYou are logged as:\n\n";
			_userList.at(counter).showUser();
			*userExist = true;
		}
        counter++;
	}
	if (*userExist == false)
	{
		std::cout << "\nWrong login or password\n";
		return;
	}
}

void Chat::logOutUser(bool* userExist)
{
	*userExist = false;
	userID = 0;
	_activeUserName.clear();
	_activeUserLogin.clear();
}

void Chat::isAvailable(User& user, bool& check)
{

	for (User all : _userList)
	{
		if (user.getName() == all.getName())
		{
			user.clearName();
			std::cout << "This name is already taken\n";
			check = false;
			break;
		}else if (user.getLogin() == all.getLogin())
		{
			user.clearLogin();
			std::cout << "This login is already taken\n";
			check = false;
			break;
		}
		else
			check = true;
	}
	if (!check)
	{
			userDataInput(user);
			isAvailable(user, check);
	}
			
}


void Chat::setActiveUser(bool* userExist, int id, std::string name, std::string login)
{
	*userExist = true;
	userID = id;
	_activeUserName = name;
	_activeUserLogin = login;
}

bool Chat::checkForActiveUser()
{
	if (_activeUserName.empty() && _activeUserLogin.empty()) {
		return false;
	}
	else
		return true;
}

std::string Chat::getActiveUserName()
{
	return _activeUserName;
}

std::string Chat::getActiveUserLogin()
{
	return _activeUserLogin;
}

void Chat::setResName(int id, std::string name) 
{
	resID = id;
	_activeResLogin = name;
}

std::string Chat::getActiveResLogin()
{
	return _activeResLogin;
}

int Chat::getActiveUserID()
{
	return userID;
}

void Chat::showUserList()
{
	int id{ 0 };
	std::cout << "\nUser list:\n";
	
	for (User user : _userList)
	{
		id++;
		std::cout << id << " - ";
		user.showUserName();
	}
}

void Chat::addUserToList(User &user)
{
	_userList.push_back(user);
}

size_t Chat::listSize()
{
	return _userList.size();
}

void Chat::privateChat()
{
	Message message;
	showUserList();
		if (listSize() == 1) {
			std::cout << "Only you are registered" << std::endl;
			return;
		}
		else {
			std::cout << "Welcome to private chat!" << std::endl;
			std::cout << "To exit enter 99 and ENTER" << std::endl;
			int res_id;   
			std::cin >> res_id;
			if (res_id == 99) { return; }
			else if (res_id < 1 || res_id > listSize())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Non-existent user number" << std::endl;
				return;
			}
			else
			{
				res_id -= 1;
				setResName(res_id, getResipient(res_id));
				std::cout << "Message for: " << getResipient(res_id) << std::endl;
                message.createMessage_priv(getActiveUserName(), getActiveResLogin());
                _messageList_priv.push_back(message);
			}
		}
}

void Chat::generalChat() 
{
	Message message;
		if (listSize() == 1) {
			std::cout << "" << std::endl;
			std::cout << "This is general chat. But there is only you here" << std::endl;
			message.createMessage(getActiveUserName());
			_messageList.push_back(message);
		}
		else {
			std::cout << "This is general chat" << std::endl;
			message.createMessage(getActiveUserName());
			_messageList.push_back(message);
		}
}

std::string Chat::getResipient(int idResipient)
{
	return _userList.at(idResipient).getName();
}

void Chat::receive_priv_Message()
{
    std::string line;
    std::ifstream file("Message_list_priv.txt");
    if (file.peek() == std::ifstream::traits_type::eof())
            std::cout<< "No messages" << std::endl;
                else{
                while (std::getline(file, line)){
                    std::cout << line;
                    line.clear();
                }
            }
}

void Chat::recive_Message()
{
    std::string line;
    std::ifstream file("Message_list_general.txt");
    if (file.peek() == std::ifstream::traits_type::eof())
        std::cout<< "No messages" << std::endl;
            else{
        while (std::getline(file, line)){
            std::cout << line << std::endl;
            line.clear();
        }
    }

}

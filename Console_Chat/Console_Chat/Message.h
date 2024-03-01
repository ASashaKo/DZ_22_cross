#pragma once
#include <iostream>
#include <string>
class Message
{
private:
	std::string _message; //текст сообщения
	std::string _name; //имя отправителя
	std::string _login; //логин отправителя
	std::string _name_recipient;

public:
	Message(std::string login, std::string name, std::string _name_recipient, std::string _message);
	Message(std::string login, std::string name, std::string message);
	Message(std::string name, std::string message);
	Message(std::string name);
	Message();
	~Message();
	void setSender(std::string& sender);
	std::string getSender();
	void setRecipient(std::string& recipient);
	std::string getRecipient();

	std::string inputAndClearStream(std::string& message);
	void createMessage(std::string name);
	void showMessage();
	void setMessage(std::string& message);
	std::string getMessage();

	void createMessage_priv(std::string name, std::string name_recipient);
	void showMessage_priv();

	};


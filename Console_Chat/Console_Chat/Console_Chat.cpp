#include <iostream>
#include "Chat.h"
#include <fstream>
#include <iterator>
#include <sstream>

int actions(Chat* chat, bool* user_exist, User *user,User &user1)
{
    if((chat->_userList.empty()))
    {
        std::ifstream file ("UserList.txt");
        std::string line;
        while (std::getline(file, line)){
            std::stringstream sline(line);
            std::istream_iterator<std::string> begin(sline);
            std::istream_iterator<std::string>end;
            std::vector<std::string>vline(begin,end);
            if(!vline.empty()){
            user->setName(vline[0]);
            user->setLogin(vline[1]);
            user->setPassword(vline[2]);
            chat->addUserToList(user1);}
        }
    }

    if (*user_exist == false)
    {
        std::cout << "\nTake instruction : \n1 - Registration \n2 - Login \n10 - Exit" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "\nNew User Registration" << std::endl;
            chat->regUser(user_exist);
            break;
        }
        case 2:
        {
            std::cout << "\nAutorization" << std::endl;
            chat->logInUser(user_exist);
            break;
        }
        case 10:
        {
            std::cout << "\nClosing chat...\nBye!" << std::endl;
            exit(0);
        }
        default:
            std::cout << "\nPlease, enter the correct command number" << std::endl;
        }
    } else 
    {
        std::cout << "\nEnter the command number : \n1 - LogOut \n2 - Send a private message \n3 - General chat \n4 - User list \n5 - View personal message \n6 - View general chat \n10 - Exit" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "\nLogOut" << std::endl;
            chat->logOutUser(user_exist);
            break;
        }
        case 2:
        {
            std::cout << "\nSend a private message" << std::endl;
            chat->privateChat();
            break;
        }
        case 3:
        {
            std::cout << "\nGeneral chat" << std::endl;
            chat->generalChat();
            break;
        }
        case 4:
        {
            chat->showUserList();
            break;
        }
        case 5:
        {
            std::cout << "View personal message" << std::endl;
            chat->receive_priv_Message();
            break;
        }
        case 6:
        {
            std::cout << "View general chat" << std::endl;
            chat->recive_Message();
            break;
        }
        case 10:
        {
            std::cout << "\nClosing chat...\nBye!" << std::endl;
            exit(0);
        }
        default:
            std::cout << "\nPlease, enter the correct command number" << std::endl;
    }
    }

    actions(chat, user_exist,user,user1);
}

int main()
{
    Chat chat;
    User user;
    bool user_exist{ false };
    actions(&chat, &user_exist,&user,user);
    return 0;
}



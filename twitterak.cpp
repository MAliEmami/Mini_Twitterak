#include <iostream>
#include <string>
#include <unordered_map>
#include "twitterak.hpp"
#include "signup.hpp"
#include "signin.hpp"
#include "functions.hpp"

using namespace std;

unordered_map<std::string, std::string> userData;

void twitterak::run()//menu
{
    std::cout << "-------------*Twitterak*-------------\n";
    std::cout << "-             *Welcome*             -\n";
    std::cout << "-        *please type 'Help'*       -\n";
    std::cout << "-------------------------------------\n";
    string command = "0";
    while (command != "exit" || command != "quit" || command != "q")
    {
        std::cout << "> ";
        cin >> command;
        lowerCase(command);//string should be lowercase
        if (command == "help")
        {
            help();
        }
        else if (command == "signup")
        {
            displaySignupMenu(userData);
        }
        else if (command =="signin")
        {
            displaySigninMenu(userData);
        }
        else//if command not match with menu
        {
            std::cout << "! Wrong command.\n";
        }
    }
}


void twitterak::help()//showing all command that user can use
{
    std::cout << "------------------------------------------------\n";
    std::cout << "-                   Help                       -\n";
    std::cout << "------------------------------------------------\n";

    std::cout << "You can type one of these commands\n";
    std::cout << "<signup>\n";
    std::cout << "<signin>\n";
    std::cout << "<exit>\n";
}

void twitterak::displaySignupMenu(std::unordered_map<std::string, std::string>& userData) 
{
    std::cout << "------------------------------------------------\n";
    std::cout << "-                   Signup                     -\n";
    std::cout << "------------------------------------------------\n";

    string choice;
    std::cout << "Which type of user would you Sign Up?\n";
    std::cout << "Personal\n" << "Company\n" << "Anonymous\n";
    //std::cout << "If you want to go back write Back\n";

    User* newUser = nullptr;
    while(1)
    {
        if (choice == "personal") 
        {
            newUser = new PersonalUser();
            break;
        } 
        else if (choice == "company") 
        {
            newUser = new CompanyUser();
            break;
        } 
        else if (choice == "Anonymous") 
        {
            newUser = new AnonymousUser();
            break;
        } 
        else 
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    }

    if (newUser) 
    {
        std::cout << "Username: ";
        std::cin.ignore();
        std::getline(std::cin, newUser->username);

        std::cout << "Password: ";
        std::cin >> newUser->password;

        newUser->signUp();
        newUser->saveData(userData);
        delete newUser;
    }
}

void twitterak::displaySigninMenu(const std::unordered_map<std::string, std::string>& userData) 
{
    std::cout << "------------------------------------------------\n";
    std::cout << "-                   Login                      -\n";
    std::cout << "------------------------------------------------\n";

    bool isloggedIn = login(userData);
    if (isloggedIn) 
    {
        std::cout << "Welcome to the program\n";
    }
}


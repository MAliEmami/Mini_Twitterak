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
    std::cout << "------------------*Twitterak*-------------------\n";
    std::cout << "-                  *Welcome*                   -\n";
    std::cout << "-             *please type 'Help'*             -\n";
    std::cout << "------------------------------------------------\n";
    string command = "";
    while (command != "exit" || command != "quit" || command != "q")
    {
        std::cout << "> ";
        cin >> command;
        lowerCase(command);//string should be lowercase
        if (command == "help")
        {
            displayHelpMenu();
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


void twitterak:: displayHelpMenu()//showing all command that user can use
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
    std::cout << "Personal\n" << "Company\n" << "Anonymous\n\n";
    //std::cout << "If you want to go back write Back\n";

    cin >> choice;

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
        std::cout << "------------------------------------------------\n";
        std::cout << "-          compelete the Information           -\n";
        std::cout << "------------------------------------------------\n";

        std::cout << "Username: ";
        std::cin.ignore();
        std::getline(std::cin, newUser->username);

        std::cout << "Password: ";
        std::cin >> newUser->password;

        newUser->signUp();
        newUser->saveData(userData);
        delete newUser;
    }
    run();
}

void twitterak::displaySigninMenu(const std::unordered_map<std::string, std::string>& userData) 
{
    std::cout << "------------------------------------------------\n";
    std::cout << "-                   Login                      -\n";
    std::cout << "------------------------------------------------\n";

    std::string username, password;
    while(1)
    {
        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        auto userEntry = userData.find(username);

        if (userEntry != userData.end() && userEntry->second == password) 
        {
            std::cout << "Login successful!\n";
            std::cout << "Welcome to the program\n";
            inToApp(username);
        } 
        else 
        {
            std::cout << "Login failed. Invalid username or password.\n";
            std::cout << "Try Again\n";
        }
    }
}


void twitterak::inToApp(string usernameInToApp)//after login => user can write every command from tweet and manage account
{
    cout << "------------------------------------------------\n";
    cout << "-                  Twitterak                   -\n";
    cout << "-             *please type 'Help'*             -\n";
    cout << "------------------------------------------------\n";
    string command = "0";
    
    while (command != "logout")
    {
        bool canIGoTo = false;
        cout << "> " << usernameInToApp << "> ";
        getline(cin, command);
        lowerCase(command);//string should be lowercase
        
        vector<string> words = wordSeparator(command);

        if (words[0] == "help")
        {
            cout << "------------------------------------------------\n";
            cout << "-                   Help                       -\n";
            cout << "------------------------------------------------\n";

            cout << "<Delete Account>\n";
            cout << "<Profile or me>\n";
            cout << "<Edit Profile>\n";
            cout << "<Logout>\n";
            cout << "<Tweet>\n\n";
        }

        if (command == "delete account")
        {
            cout << "? Are you sure?(y/n)\n";
            string areYouSure;
            while (1)
            {
                cin >> areYouSure;
                lowerCase(areYouSure);
                if (areYouSure == "y")
                {
                    userData.erase(usernameInToApp);//delete account from unordered_map
                    cout << "! Delete account successful\n";
                    run();
                }
                else if (areYouSure == "n")
                {
                    cout << "! Delete account was unsuccessful\n";
                    break;
                }
                else
                {
                    cout << "! Wrong command\n";
                }
            }
        }
    }

}
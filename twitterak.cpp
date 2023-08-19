#include <iostream>
#include <string>
#include <unordered_map>
#include "twitterak.hpp"
#include "signup.hpp"
#include "signin.hpp"
#include "functions.hpp"

using namespace std;
unordered_map<string, string> userData;

void twitterak::run()//menu
{
    cout << "------------------*Twitterak*-------------------\n";
    cout << "-                  *Welcome*                   -\n";
    cout << "-             *please type 'Help'*             -\n";
    cout << "------------------------------------------------\n";
    string command = "";
    while (command != "exit" || command != "quit" || command != "q")
    {
        cout << "> ";
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
            cout << "! Wrong command.\n";
        }
    }
}


void twitterak:: displayHelpMenu()//showing all command that user can use
{
    cout << "------------------------------------------------\n";
    cout << "-                   Help                       -\n";
    cout << "------------------------------------------------\n";

    cout << "You can type one of these commands\n";
    cout << "<signup>\n";
    cout << "<signin>\n";
    cout << "<exit>\n";
}

void twitterak::displaySignupMenu(unordered_map<string, string>& userData) 
{
    cout << "------------------------------------------------\n";
    cout << "-                   Signup                     -\n";
    cout << "------------------------------------------------\n";

    string choice;
    cout << "Which type of user would you Sign Up?\n";
    cout << "Personal\n" << "Company\n" << "Anonymous\n\n";
    //cout << "If you want to go back write Back\n";

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
            cout << "Invalid choice. Please try again." << endl;
        }

    }

    if (newUser) 
    {
        cout << "------------------------------------------------\n";
        cout << "-          compelete the Information           -\n";
        cout << "------------------------------------------------\n";

        cout << "Username: ";
        cin.ignore();
        getline(cin, newUser->username);

        cout << "Password: ";
        cin >> newUser->password;

        newUser->signUp();
        newUser->saveData(userData);
        delete newUser;
    }
    run();
}

void twitterak::displaySigninMenu(const unordered_map<string, string>& userData) 
{
    cout << "------------------------------------------------\n";
    cout << "-                   Login                      -\n";
    cout << "------------------------------------------------\n";

    string username, password;
    while(1)
    {
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        auto userEntry = userData.find(username);

        if (userEntry != userData.end() && userEntry->second == password) 
        {
            cout << "Login successful!\n";
            cout << "Welcome to the program\n";
            inToApp(username);
        } 
        else 
        {
            cout << "Login failed. Invalid username or password.\n";
            cout << "Try Again\n";
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
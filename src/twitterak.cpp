#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "twitterak.hpp"
#include "signup.hpp"
#include "signin.hpp"
#include "tweet.hpp"
#include "functions.hpp"
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

void twitterak::run()//menu
{
    unordered_map<string, string> userData;// save user information to map 

    cout << "------------------*Twitterak*-------------------\n";
    cout << "-                  *Welcome*                   -\n";
    cout << "-             *please type 'Help'*             -\n";
    cout << "------------------------------------------------\n";
    string command = "";
    while (1)
    {
        cout << "> ";
        cin >> command;
        lowerCase(command); // string should be lowercase
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
        else if(command == "exit" || command == "quit" || command == "q")
        {
            cout << "Goodbye";
            break;
        }
        else // if command not match with menu
        {
            cout << "! Wrong command.\n";
        }
    }
}


void twitterak::displayHelpMenu()// showing all command that user can use
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

    User* newUser = nullptr; //  initializes a pointer to a user object with a null value
    while(1)
    {
        cout << "> ";
        cin >> choice;

        if (choice == "personal") 
        {
            newUser = new PersonalUser(); // signup with personal user
            break;
        } 
        else if (choice == "company") 
        {
            newUser = new CompanyUser(); // signup with company user
            break;
        } 
        else if (choice == "Anonymous") 
        {
            newUser = new AnonymousUser(); // signup with anonymous user
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
        while(1)
        {
            cin >> newUser->username;
            if (newUser->username[0] != '@') // add @ if user dont add
            {
                newUser->username = '@' + newUser->username;
            }
            if (userData.find(newUser->username) != userData.end()) // error for if user chose a username that is exists in the files 
            {
                cout << "! Username already exists.\n";
            }
            else
            {
                break;
            }
        }

        cout << "Password: ";
        cin >> newUser->password;
        
        newUser->password = encryptPassword(newUser->password);

        newUser->saveData(userData); // save user to map
        newUser->saveDataToFile(userData , newUser->username); // save user to file
        newUser->signUp(); // user will be sign up
        delete newUser; // free the memory allocated
    }
    displaySigninMenu(userData); // go to login to app
}

void twitterak::displaySigninMenu(unordered_map<string, string>& userData)
{

    cout << "------------------------------------------------\n";
    cout << "-                   Login                      -\n";
    cout << "------------------------------------------------\n";

    string username, password;
    while(1)
    {
        cout << "Username: ";
        cin >> username;
        if (username[0] != '@') // if user not have @ in first index its will add
        {
            username = '@' + username;
        }

        cout << "Password: ";
        cin >> password;

        unordered_map<string, string> userData = loadData(username); // load data from file to map

        auto userEntry = userData.find(username);

        if (userEntry != userData.end() && userEntry->second == encryptPassword(password)) // validation to login in to app
        {
            cout << "Login successful!\n";
            cout << "Welcome to the program\n";
            inToApp(username);
            break;
        } 
        else 
        {
            cout << "! Login failed. Invalid username or password.\n";
            run();
        }
    }
}


void twitterak::inToApp(string usernameInToApp)//after login => user can write every command from tweet and manage account
{
    cout << "------------------------------------------------\n";
    cout << "-                  Twitterak                   -\n";
    cout << "-             *please type 'Help'*             -\n";
    cout << "------------------------------------------------\n";
    string command = "";
    
    while (command != "logout")
    {
        bool canIGoTo = false;
        cout << "> ";
        cout << usernameInToApp << '\n'; 
        cout << "> ";
        // getline(cin, command);
        // cin.ignore();
        cin >> command;
        lowerCase(command); // string should be lowercase
        

        if (command == "help")
        {
            displayInToAppHelpMenu();
        }

        if (command == "delete account")
        {
            displayInToAppDeleteAccountMenu(usernameInToApp);
        }
        else if (command == "tweet")
        {
            displayInToAppTweetMnue(usernameInToApp);
        }

    }
}

void twitterak::displayInToAppHelpMenu()
{
    cout << "------------------------------------------------\n";
    cout << "-                   Help                       -\n";
    cout << "------------------------------------------------\n";

    //cout << "<Delete Account>\n";
    //cout << "<Profile or me>\n";
    //cout << "<Edit Profile>\n";
    cout << "<Logout>\n";
    cout << "<Tweet>\n\n";

}

void twitterak::displayInToAppDeleteAccountMenu(string usernameInToApp)
{
    cout << "? Are you sure?(y/n)\n";
    string areYouSure;
    while (1)
    {
        cin >> areYouSure;
        lowerCase(areYouSure);
        if (areYouSure == "y")
        {
            userData.erase(usernameInToApp); // delete account from unordered_map
            cout << "! Delete account successful\n";

            cout << "here shoud compelete. its not redy!";
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

void twitterak::displayInToAppTweetMnue(string usernameInToApp)
{
    cout << "------------------------------------------------\n";
    cout << "-                    *Tweet*                   -\n";
    cout << "------------------------------------------------\n";
    cout << "You can type one of these bellow command.";
    cout << '\n' << "<Tweet>" << '\n' << "<Retweet>" << '\n' << "Quote Tweet" << '\n';
    //should display file

    
    string command = "";
    cin >> command;

    while(1)
    {
        if (command == "tweet")
        {
            string tweet;
            cout << "Enter tweet: ";
            getline(cin, tweet);
            cout <<'\n';
            tweetCreator(tweet,usernameInToApp);
        }
        else if (command == "quote tweet")
        {
            
        }
        else if (command == "retweet")
        {

        }
        // else if (command == "mention")
        // {

        // }
        // else if (command == "Like")
        // {

        // }
    }

}


#include <iostream>
#include <string>
#include <unordered_map>
#include "signup.hpp"
#include "signin.hpp"

void displaySignupMenu(std::unordered_map<std::string, std::string>& userData);
void displaySigninMenu(const std::unordered_map<std::string, std::string>& userData);

int main() 
{
    char choice;
    std::unordered_map<std::string, std::string> userData;

    do 
    {
        std::cout << "=== Main Menu ===" << std::endl;
        std::cout << "1. Sign Up" << std::endl;
        std::cout << "2. Sign In" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == '1') 
        {
            displaySignupMenu(userData);
        } 
        else if (choice == '2') 
        {
            displaySigninMenu(userData);
        } 
        else if (choice == '3') 
        {
            std::cout << "Goodbye!" << std::endl;
        } 
        else 
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != '3');

    return 0;
}

void displaySignupMenu(std::unordered_map<std::string, std::string>& userData) 
{
    char choice;

    std::cout << "=== Sign Up Menu ===" << std::endl;
    std::cout << "1. Sign Up as a Company" << std::endl;
    std::cout << "2. Sign Up as a Personal User" << std::endl;
    std::cout << "3. Sign Up Anonymously" << std::endl;
    std::cout << "4. Go Back" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    User* newUser = nullptr;
    while(1)
    {
        if (choice == '1') 
        {
            newUser = new CompanyUser();
            break;
        } 
        else if (choice == '2') 
        {
            newUser = new PersonalUser();
            break;
        } 
        else if (choice == '3') 
        {
            newUser = new AnonymousUser();
            break;
        } 
        else if (choice == '4')
        {
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

void displaySigninMenu(const std::unordered_map<std::string, std::string>& userData) 
{
    bool loggedIn = SignIn::login(userData);
    if (loggedIn) 
    {
        // Proceed with the logged-in user's actions
        std::cout << "Welcome to the program, logged-in user!" << std::endl;
    }
}
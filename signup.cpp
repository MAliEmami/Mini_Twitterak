#include "signup.hpp"
#include <iostream>


PersonalUser::PersonalUser() : User("Personal") {}
void User::saveData(std::unordered_map<std::string, std::string>& userData) 
{
    userData[username] = newUser ;
    // "Type: "       + userType +
    // ", Username: " + username + 
    // ", Password: " + password;
}

void PersonalUser::signUp() 
{
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Number: ";
    std::cin >> number;

    std::cout << "Country: ";
    std::cin.ignore();
    std::getline(std::cin, country);

    std::cout << "Birthday: ";
    std::cin.ignore();
    std::getline(std::cin, birthday);

    std::cout << "Link: ";
    std::cin.ignore();
    std::getline(std::cin, link);

    std::cout << "Biography: ";
    std::cin.ignore();
    std::getline(std::cin, biography);
}

CompanyUser::CompanyUser() : User("Company") {}

void CompanyUser::signUp() 
{
    std::cout << "Company Name: ";
    std::cin.ignore();
    std::getline(std::cin, companyName);

    std::cout << "Country: ";
    std::cin.ignore();
    std::getline(std::cin, country);

    std::cout << "Link: ";
    std::cin.ignore();
    std::getline(std::cin, link);

    std::cout << "Biography: ";
    std::cin.ignore();
    std::getline(std::cin, biography);
}

AnonymousUser::AnonymousUser() : User("Anonymous") {}

void AnonymousUser::signUp() 
{
    // No additional fields needed for anonymous user
}

User::User(std::string _userType) : userType(_userType) {}

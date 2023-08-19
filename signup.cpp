#include "signup.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

PersonalUser::PersonalUser() : User("Personal") {}

void User::saveData(unordered_map<string, string>& userData) 
{
    userData[username] = password ;
}

void PersonalUser::signUp() 
{
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Number: ";
    cin >> number;

    cout << "Country: ";
    cin.ignore();
    getline(cin, country);

    cout << "Birthday: ";
    cin.ignore();
    getline(cin, birthday);

    cout << "Link: ";
    cin.ignore();
    getline(cin, link);

    cout << "Biography: ";
    cin.ignore();
    getline(cin, biography);
}

CompanyUser::CompanyUser() : User("Company") {}

void CompanyUser::signUp() 
{
    cout << "Company Name: ";
    cin.ignore();
    getline(cin, companyName);

    cout << "Country: ";
    cin.ignore();
    getline(cin, country);

    cout << "Link: ";
    cin.ignore();
    getline(cin, link);

    cout << "Biography: ";
    cin.ignore();
    getline(cin, biography);
}

AnonymousUser::AnonymousUser() : User("Anonymous") {}

void AnonymousUser::signUp() 
{
}

User::User(string _userType) : userType(_userType) {}

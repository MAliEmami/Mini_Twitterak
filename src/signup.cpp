#include "signup.hpp"
#include "tweet.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PersonalUser::PersonalUser() : User("Personal") {}

void User::saveData(unordered_map<string, string>& userData) 
{
    userData[username] = password ;
}

// save the users data to file
void User::saveDataToFile(unordered_map<string, string>& userDate ,string fileName) 
{
    ofstream file(fileName + ".txt");
    for (const auto& pair : userDate) 
    {
        file << pair.first << " " << pair.second << "\n";
    }
}

// unordered_map<string, string> loadData(string fileName) 
// {
//     unordered_map<string, string> userDate;
//     ifstream file(fileName + ".txt");
//     string username, password;
    
//     while (file >> username >> password) 
//     {
//         userDate[username] = password;
//     }

//     return userDate;
// }

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

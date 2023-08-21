#include "signup.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

PersonalUser::PersonalUser() : User("Personal") {} // personal user type

void User::saveData(unordered_map<string, string>& userData)// save user to map ==> key=username , value = password
{
    userData[username] = password ;
}

// save the user data to file
void User::saveDataToFile(unordered_map<string, string>& userDate ,string fileName) 
{
    ofstream file(fileName + ".txt"); // i have (username of that user).txt
    for (const auto& pair : userDate) 
    {
        file << pair.first << " " << pair.second << "\n";
    }
}



// void User::saveAllDataToFile(unordered_map<string, string>& userAllData ,string fileName) 
// {
//     ofstream file("all" + fileName + ".txt");
//     for (const auto& pair : userAllData) 
//     {
//         file << pair.first << " " << pair.second << "\n";
//     }
// }


void PersonalUser::signUp()  // get informations "personal"
{
    cout << "Name: ";
    cin >> name;

    cout << "Number: ";
    cin >> number;

    cout << "Country: ";
    cin >> country;

    cout << "Birthday: ";
    cin >> birthday;

    cout << "Link: ";
    cin >> link;
    
    cout << "Biography: ";
    cin >> biography;
}

CompanyUser::CompanyUser() : User("Company") {} // personal usr type

void CompanyUser::signUp() // get informations "personal"
{
    cout << "Company Name: ";
    cin >> companyName;

    cout << "Country: ";
    cin >> country;

    cout << "Link: ";
    cin >> link;

    cout << "Biography: ";
    cin >> biography;
}

AnonymousUser::AnonymousUser() : User("Anonymous") {} // anonymous usr type

void AnonymousUser::signUp() 
{
}

User::User(string _userType) : userType(_userType) {}

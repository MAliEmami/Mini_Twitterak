#include "signin.hpp"
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>

bool login(const unordered_map<string, string>& userData) 
{
    string username, password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    auto userEntry = userData.find(username);

    if (userEntry != userData.end() && userEntry->second == password) 
    {
        cout << "* Login successful!" << endl;
        return true;
    } 
    else 
    {
        cout << "! Login failed. Invalid username or password." << endl;
        return false;
    }
}



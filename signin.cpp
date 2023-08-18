#include "signin.hpp"
#include "twitterak.hpp"
#include <iostream>

bool login(const std::unordered_map<std::string, std::string>& userData) 
{
    std::string username, password;

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    std::cin >> password;

    auto userEntry = userData.find(username);

    std::cout << "userEntry: " << std::endl ;
    std::cout << "first: " << userEntry->first << std::endl;
    std::cout << "second: " << userEntry->second << std::endl;

    if (userEntry != userData.end() && userEntry->second == password) 
    {
        std::cout << "Login successful!" << std::endl;
        return true;
    } 
    else 
    {
        std::cout << "Login failed. Invalid username or password." << std::endl;
        return false;
    }
}

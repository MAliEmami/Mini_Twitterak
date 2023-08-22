#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void lowerCase(string &str) //  a function to convert every comand to lowercase
{    
    for(char& i : str)
    {
        i = tolower(i) ;
    }
} 

bool validatePassword(const string& password) 
{
    if (password.length() < 8) 
    {
        return false; 
    }

    bool hasNumber = false; // is password have number
    bool hasCharacter = false; // is password have char
    bool hasSpecial = false; // is password have special key

    for (char c : password) 
    {
        if (isdigit(c)) 
        {
            hasNumber = true;
        } 
        else if (isalpha(c)) 
        {
            hasCharacter = true;
        } 
        else if (!isalnum(c)) 
        {
            hasSpecial = true;
        }

        if (hasNumber && hasCharacter && hasSpecial) // if password have all of that return true 
        {
            return true;
        }
    }

    return false; // if password do not have that validations
}

bool validateBiography(const string& paragraph) // validate to do not input morthan 160 char
{
    return paragraph.length() <= 160;
}

bool validateUsername(const std::string& input) 
{
    static const std::unordered_set<std::string>

    // the user couldn't input program command for username 
    invalidWords = {"tweet"    , "signin"  , "signup"      , "logout" , "quit" ,
                    "personal" , "company" , "Anonymous"   , "logout" , "help" ,
                    "mention"  , "retweet" , "quote tweet" , "Like"   , "exit" , 
                    "delete account"};
    
    if (input.size() < 5 || !std::isalpha(input[0])) // username couldnt be less than 5 char
    {
        return false;
    }

    for (char c : input) // returns false if any char is '@' or non-alphanumeric
    {
        if (c == '@' || !std::isalnum(c)) 
        {
            return false;
        }
    }
    
    return invalidWords.find(input) == invalidWords.end();
}

string encryptPassword(string& password) // a func to encryp the user password
{
    std::string encryptedPassword = password;
    string key = "encryption_key";
    for (size_t i = 0; i < encryptedPassword.length(); ++i) 
    {
        encryptedPassword[i] = password[i] ^ key[i % key.length()];
    }
    return encryptedPassword;
}

unordered_map<string, string> loadData(string& fileName) // load form file to map
{
    unordered_map<string, string> userDate;
    ifstream file(fileName + ".txt");
    string username, password;
    
    while (file >> username >> password) 
    {
        userDate[username] = password;
    }

    return userDate;
}

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

#endif

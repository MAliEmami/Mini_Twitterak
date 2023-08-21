#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void lowerCase(std::string &str); // a function to convert every comand to lowercase

bool validatePassword(const std::string& password); // password validation
bool validateBiography(const string& paragraph); // bio validation
bool validateUsername(const std::string& input);  // username validation

std::string encryptPassword(std::string& password);

std::unordered_map<std::string, std::string> loadData(std::string& fileName);

// vector <std::string> wordSeparator(std::string command);// seperate words of "edit" command
//void updateInformation(unordered_map<string, string>& users, const string& username, const string& newPassword);
//void saveDataToFile(const unordered_map<string, string>& users ,string fileName);
//unordered_map<string, string> loadData(string fileName);// i dont know



#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std ;

void lowerCase(std::string &str);// every command should be lowercase

vector <std::string> wordSeparator(std::string command);// seperate words of "edit" command

std::string bringImportant(const std::string& command, size_t start ); //sugest to pass argument for delete

bool validatePassword(const std::string& password);
bool validateBiography(const string& paragraph);
bool validateUsername(const std::string& input); 

void updateInformation(unordered_map<string, string>& users, const string& username, const string& newPassword);
void saveData(const unordered_map<string, string>& users ,string fileName);
unordered_map<string, string> loadData(string fileName);// i dont know






#endif
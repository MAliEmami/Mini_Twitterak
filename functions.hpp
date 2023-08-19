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

#endif
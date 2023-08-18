#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std ;

void lowerCase(string &str);// every command should be lowercase

vector <string> wordSeparator(string command);// seperate words of "edit" command

string bringImportant(const string& command, size_t start ); //sugest to pass argument for delete

#endif
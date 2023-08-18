#include <iostream>
#include <vector>
#include "functions.hpp"
#include "twitterak.hpp"

using namespace std;

void lowerCase(string &str)// every command should be lowercase
{
    for(char& i : str)
    {
        i = tolower(i) ;
    }
} 

vector <string> wordSeparator(string command)// seperate words of "edit" command
{
    vector <string> words;
    string tempCommand;

    for (size_t i = 0 ; i < command.size() ; ++i)
    {
        if (command[i] != ' ' && command[i] != ':') // confutoin
        {
            tempCommand  += command[i]; 
        }

        else if (tempCommand != "")
        {
            words.push_back(tempCommand);
            tempCommand = "" ;
        }
    }

    if (tempCommand.size() > 0 && command[command.size() - 1] != ' ')
    {
        words.push_back(tempCommand);
    }
    else
    {
        words.push_back(" ") ;
    }
    
    return words;
}

string bringImportant(const string& command, size_t start ) //sugest to pass argument for delete
{
    string important {} ;

    for(size_t i = start ; i < command.size() ; ++i)
    {
        if(command[i] != '"'  && command[i] != '@')
            important += command[i] ;
    }

    return important ;
}

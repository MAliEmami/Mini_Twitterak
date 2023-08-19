#ifndef TWITTERAK_H
#define TWITTERAK_H
#include "twitterak.hpp"
#include "signup.hpp"
#include "signin.hpp"
#include "functions.hpp"
#include <iostream>

class twitterak
{
    public:
        void run();
        void  displayHelpMenu();
        // void signup();
        // void signin();
        void inToApp(std::string usernameInToApp);
        // void addUser(user);
        // bool isCorrect(std::string usernameCheck, std::string passwordCheck);
        // //void addUser();

        void displayInToAppHelpMenu();
        void displayInToAppDeleteAccountMenu(std::string usernameInToApp);
        void displayInToAppTweetMnue(std::string usernameInToApp);


        //bool login(const std::unordered_map<std::string, std::string>& userData);
        void displaySignupMenu(std::unordered_map<std::string, std::string>& userData);
        void displaySigninMenu(const std::unordered_map<std::string, std::string>& userData);

        std::unordered_map<std::string, std::string> userData;


    private:
       // std::unordered_map<std::string , user> users;

};

#endif
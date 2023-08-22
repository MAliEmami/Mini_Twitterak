#ifndef TWITTERAK_H
#define TWITTERAK_H

#include <iostream>
#include "signup.hpp"
#include "signin.hpp"

class twitterak
{
    public:
        void run();

        void displayHelpMenu();
        void displaySignupMenu(std::unordered_map<std::string, std::string>& userData);
        void displaySigninMenu(std::unordered_map<std::string, std::string>& userData);

        void inToApp(std::string usernameInToApp);

        void displayInToAppHelpMenu();
        void displayInToAppDeleteAccountMenu(std::string usernameInToApp);
        void displayInToAppTweetMnue(std::string usernameInToApp);

        std::unordered_map<std::string, std::string> userData;
        std::unordered_map<std::string, std::string> userAllData;

};

#endif
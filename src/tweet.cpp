#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "signup.hpp"
#include "signin.hpp"
#include "tweet.hpp"

using namespace std;


void tweet::tweetCreator(string tweet, string username) // to tweeting
{
    int tweetNumber = count(userTweet[username].begin(), userTweet[username].end(), '\n') + 1;
    userTweet[username] += (to_string(tweetNumber) + ". " + tweet + "\n");

    for (const auto &pair : userTweet)
    {
        cout << pair.first << " tweet: \n"
            << pair.second << "\n";
    }
}
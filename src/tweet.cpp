#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "twitterak.hpp"
#include "signup.hpp"
#include "signin.hpp"
#include "functions.hpp"
#include "tweet.hpp"

using namespace std;


void tweetCreator(string tweet, string username)
{
    int tweetNumber = count(userTweet[username].begin(), userTweet[username].end(), '\n') + 1;
    userTweet[username] += (to_string(tweetNumber) + ". " + tweet + "\n");

    for (const auto& pair : userTweet) 
    {
        cout << pair.first << " tweet: \n" << pair.second << "\n";
    }
}
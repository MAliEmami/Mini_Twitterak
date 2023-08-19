#ifndef TWEET_HPP
#define TWEET_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include "twitterak.hpp"
#include "signup.hpp"
#include "signin.hpp"
#include "functions.hpp"
#include <algorithm>

// void displayTweetMnue();
void tweetCreator(unordered_map<string, string>& userTweet, string username);

std::unordered_map<std::string, std::string> userTweet;



#endif // !TWEET_HPP
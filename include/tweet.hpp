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

std::unordered_map<std::string, std::string> userTweet;

void tweetCreator(std::string tweet, std::string username);




#endif // !TWEET_HPP
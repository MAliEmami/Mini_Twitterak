#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void tweetCreator(unordered_map<string, string>& userTweet, string username)
{
    string tweet;
    cout << "Enter tweet: ";
    getline(cin, tweet);
    cout <<'\n';

    int tweetNumber = count(userTweet[username].begin(), userTweet[username].end(), '\n') + 1;
    userTweet[username] += (to_string(tweetNumber) + ". " + tweet + "\n");

    for (const auto& pair : userTweet) 
    {
        cout << pair.first << " tweet: \n" << pair.second << "\n";
    }
}

int main()
{
    unordered_map<std::string, std::string> userTweet;

    string username = "@11111111111";
    for (int i=0; i<2; i++)
    {
        tweetCreator(userTweet , username);
    }

    for (int i=0; i<1; i++)
    {
        tweetCreator(userTweet , username);
    }

    username = "@2222222222";
    for (int i=0; i<2; i++)
    {
        tweetCreator(userTweet , username);
    }

    username = "@3333333333";
    for (int i=0; i<2; i++)
    {
        tweetCreator(userTweet , username);
    }
    

    return 0;
}

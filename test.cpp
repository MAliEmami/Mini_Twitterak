#include <iostream>
#include <vector>
#include <string>
#include <sstream> // Add this include for std::istringstream

void clearLastCommandLine() 
{
    std::cout << "\x1b[2K\r";
}

int main() 
{
    std::string tweet;
    std::cout << "Enter your Tweet:";
    std::getline(std::cin, tweet);
    //clearLastCommandLine();
    std::cout << "@username:" << "tweet: " << tweet << '\n';


    std::vector<std::string> sentences;
    std::string input;

    std::cout << "Enter your comment:\n";

    std::getline(std::cin, input);

    sentences.push_back(input);

    // std::cout << "\nEnter sentence numbers to comment:\n";

    // std::string commentInput;
    // std::getline(std::cin, commentInput);

    // std::vector<std::string> comments;
    // std::istringstream iss(commentInput);
    // int sentenceIndex;

    // while (iss >> sentenceIndex) 
    // {
    //     if (sentenceIndex > 0 && sentenceIndex <= static_cast<int>(sentences.size())) 
    //     {
             comments.push_back("Commented: " + sentences);
    //     }
    // }

    std::cout << "\nComments:\n";

    std::cout << "@username comment: " << "tweet: " << tweet << '\n' << '\t';            
    for (const std::string& comment : comments) 
    {
        std::cout << comment << "\n";
    }

    return 0;
}
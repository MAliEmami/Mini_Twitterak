#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() 
{
    std::vector<std::string> sentences;
    std::string input;

    std::cout << "Enter sentences (type 'end' to finish):\n";

    while (true) {
        std::getline(std::cin, input);

        if (input == "end") {
            break;
        }

        sentences.push_back(input);
    }

    std::cout << "\nSentences entered:\n";
    for (size_t i = 0; i < sentences.size(); ++i) {
        std::cout << i + 1 << ". " << sentences[i] << "\n";
    }

    std::cout << "\nEnter sentence numbers to comment (separated by spaces):\n";

    std::string commentInput;
    std::getline(std::cin, commentInput);

    std::vector<std::string> comments;
    std::istringstream iss(commentInput);
    int sentenceIndex;

    while (iss >> sentenceIndex) {
        if (sentenceIndex > 0 && sentenceIndex <= static_cast<int>(sentences.size())) {
            comments.push_back("// Commented: " + sentences[sentenceIndex - 1]);
        }
    }

    std::cout << "\nComments:\n";
    for (const std::string& comment : comments) {
        std::cout << comment << "\n";
    }

    return 0;
}

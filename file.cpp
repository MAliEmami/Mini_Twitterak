#include "signup.hpp"
#include "signin.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

void saveUserDataToFile(const std::unordered_map<std::string, std::string>& userData, const std::string& filename);
void loadUserDataFromFile(std::unordered_map<std::string, std::string>& userData, const std::string& filename);
void displaySignupMenu(std::unordered_map<std::string, std::string>& userData);
void displaySigninMenu(const std::unordered_map<std::string, std::string>& userData);

int main() {
    std::unordered_map<std::string, std::string> userData;

    // Load user data from file
    loadUserDataFromFile(userData, "userdata.txt");

    char choice;

    do {
        std::cout << "=== Main Menu ===" << std::endl;
        std::cout << "1. Sign Up" << std::endl;
        std::cout << "2. Sign In" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == '1') {
            displaySignupMenu(userData);
        } else if (choice == '2') {
            displaySigninMenu(userData);
        } else if (choice == '3') {
            // Save user data to file before quitting
            saveUserDataToFile(userData, "userdata.txt");
            std::cout << "Goodbye!" << std::endl;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != '3');

    return 0;
}

void saveUserDataToFile(const std::unordered_map<std::string, std::string>& userData, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& entry : userData) {
            outputFile << entry.first << " " << entry.second << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

void loadUserDataFromFile(std::unordered_map<std::string, std::string>& userData, const std::string& filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string username, data;
            if (iss >> username) {
                std::getline(iss, data);
                userData[username] = data;
            }

        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}


// The rest of the code remains the same

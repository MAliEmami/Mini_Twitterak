#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

// Function to save the user data to a file
void saveData(const std::unordered_map<std::string, std::string>& users ,std::string fileName) 
{
    std::ofstream file(fileName + ".txt");
    for (const auto& pair : users) 
    {
        file << pair.first << " " << pair.second << "\n";
    }
}

void updatePassword(std::unordered_map<std::string, std::string>& users, const std::string& username, const std::string& newPassword) 
{
    users[username] = newPassword;
    saveData(users , username);
    std::cout << "Password updated successfully.\n";
}


// Function to load user data from a file
std::unordered_map<std::string, std::string> loadData(std::string fileName) 
{
    std::unordered_map<std::string, std::string> users;
    std::ifstream file(fileName + ".txt");
    std::string username, password;
    
    while (file >> username >> password) 
    {
        users[username] = password;
    }
    
    return users;
}

int main() 
{
    std::unordered_map<std::string, std::string> users;

    while (true) 
    {
        std::cout << "1. Sign Up\n2. Sign In\n3. Quit\n4. change\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) 
        {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;

            if (users.find(username) != users.end()) 
            {
                std::cout << "Username already exists.\n";
                continue;
            }

            std::cout << "Enter password: ";
            std::cin >> password;
            users[username] = password;
            saveData(users , username);
            std::cout << "Account created successfully.\n";
        } 
        else if (choice == 2) 
        {
            std::string username, password;
            std::cout << "Enter username: ";
            std::cin >> username;

            std::unordered_map<std::string, std::string> users = loadData(username);

            if (users.find(username) == users.end()) 
            {
                std::cout << "Username not found.\n";
                continue;
            }

            std::cout << "Enter password: ";
            std::cin >> password;

            if (users[username] == password) 
            {
                std::cout << "Logged in successfully.\n";
            } 
            else 
            {
                std::cout << "Incorrect password.\n";
            }
        } 
        else if (choice == 3) 
        {
            break;
        }
        else if (choice == 4)
        {
            std::string username, newPassword;
            std::cout << "Enter username: ";
            std::cin >> username;

            if (users.find(username) == users.end()) 
            {
                std::cout << "Username not found.\n";
                continue;
            }

            std::cout << "Enter new password: ";
            std::cin >> newPassword;
            updatePassword(users, username, newPassword);
        }
        else 
        {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}

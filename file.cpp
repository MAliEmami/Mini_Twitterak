#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;
// Function to save the user data to the file
void saveData(const unordered_map<string, string>& users ,string fileName) 
{
    ofstream file(fileName + ".txt");
    for (const auto& pair : users) 
    {
        file << pair.first << " " << pair.second << "\n";
    }
}

void updateInformation(unordered_map<string, string>& users, const string& username, const string& newPassword)
{
    users[username] = newPassword;
    saveData(users , username);
    cout << "Password updated successfully.\n";
    // Not compelete
}


// Function to load user data from the file
unordered_map<string, string> loadData(string fileName) 
{
    unordered_map<string, string> users;
    ifstream file(fileName + ".txt");
    string username, password;
    
    while (file >> username >> password) 
    {
        users[username] = password;
    }

    return users;
}

int main() 
{
    unordered_map<string, string> users;

    while (true) 
    {
        cout << "1. Sign Up\n2. Sign In\n3. Quit\n4. change\n";
        int choice;
        cin >> choice;

        if (choice == 1) 
        {
            string username, password;
            cout << "Enter username: ";
            cin >> username;

            if (users.find(username) != users.end()) 
            {
                cout << "Username already exists.\n";
                continue;
            }

            cout << "Enter password: ";
            cin >> password;
            users[username] = password;
            saveData(users , username);
            cout << "Account created successfully.\n";
        } 
        else if (choice == 2) 
        {
            string username, password;
            cout << "Enter username: ";
            cin >> username;

            unordered_map<string, string> users = loadData(username);

            if (users.find(username) == users.end()) 
            {
                cout << "Username not found.\n";
                continue;
            }

            cout << "Enter password: ";
            cin >> password;

            if (users[username] == password) 
            {
                cout << "Logged in successfully.\n";
            } 
            else 
            {
                cout << "Incorrect password.\n";
            }
        } 
        else if (choice == 3) 
        {
            break;
        }
        else if (choice == 4)
        {
            string username, newPassword;
            cout << "Enter username: ";
            cin >> username;

            if (users.find(username) == users.end()) 
            {
                cout << "Username not found.\n";
                continue;
            }

            cout << "Enter new password: ";
            cin >> newPassword;
            updateInformation(users, username, newPassword);
        }
        else 
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

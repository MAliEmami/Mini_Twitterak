#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include <string>
#include <unordered_map>

// ... Previous code ...

// Function to update user data in the map and the file
void updatePassword(std::unordered_map<std::string, std::string>& users, const std::string& username, const std::string& newPassword) {
    users[username] = newPassword;
    saveData(users);
    std::cout << "Password updated successfully.\n";
}


int main() {
    // ... Previous code ...

    while (true) {
        std::cout << "1. Sign Up\n2. Sign In\n3. Change Password\n4. Quit\n";
        // ... Previous code ...

        if (choice == 4) {
            break;
        } 
        else if (choice == 3) {
            std::string username, newPassword;
            std::cout << "Enter username: ";
            std::cin >> username;

            if (users.find(username) == users.end()) {
                std::cout << "Username not found.\n";
                continue;
            }

            std::cout << "Enter new password: ";
            std::cin >> newPassword;
            updatePassword(users, username, newPassword);
        } else {
            // ... Previous code ...
        }
    }

    // ... Previous code ...
}
=======

using namespace std;

int main()
{
    int i;
    do
    {
        cout << "i=";
        cin >> i;
    } while (i!=20);

    return 0;
}
>>>>>>> 71d7a9df48c790eefb29a8bd34b09afd64d23ef0

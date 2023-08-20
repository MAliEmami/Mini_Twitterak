#include <iostream>
using namespace std;

int main()
{
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
    
}
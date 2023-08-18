#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct UserProfile {
    std::string username;
    std::string name;
    std::string password;
    std::string number;
};

void saveProfiles(const std::vector<UserProfile>& profiles, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const UserProfile& profile : profiles) {
            file << profile.username << "," << profile.name << "," << profile.password << "," << profile.number << "\n";
        }
        file.close();
        std::cout << "Profiles saved to " << filename << "\n";
    } else {
        std::cout << "Unable to open file for saving.\n";
    }
}

std::vector<UserProfile> loadProfiles(const std::string& filename) {
    std::vector<UserProfile> profiles;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string username, name, password, number;
            getline(iss, username, ',');
            getline(iss, name, ',');
            getline(iss, password, ',');
            getline(iss, number, ',');
            profiles.push_back({username, name, password, number});
        }
        file.close();
    } else {
        std::cout << "Unable to open file for loading.\n";
    }
    return profiles;
}

int main() {
    const std::string filename = "user_profiles.txt";
    std::vector<UserProfile> profiles = loadProfiles(filename);

    std::string command;
    std::cout << "Enter a command ('new' to create a new profile, 'edit' to edit a profile, 'exit' to exit): ";
    std::cin >> command;

    if (command == "new") {
        UserProfile newUser;
        std::cout << "Enter username: ";
        std::cin >> newUser.username;
        std::cout << "Enter name: ";
        std::cin >> newUser.name;
        std::cout << "Enter password: ";
        std::cin >> newUser.password;
        std::cout << "Enter number: ";
        std::cin >> newUser.number;
        profiles.push_back(newUser);
        saveProfiles(profiles, filename);
    } else if (command == "edit") {
        std::string editNumber;
        std::cout << "Enter profile number to edit: ";
        std::cin >> editNumber;
        for (UserProfile& profile : profiles) {
            if (profile.number == editNumber) {
                std::string newPassword;
                std::cout << "Enter new password: ";
                std::cin >> newPassword;
                profile.password = newPassword;
                saveProfiles(profiles, filename);
                break;
            }
        }
    }

    return 0;
}

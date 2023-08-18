#include <iostream>
#include <cstdlib>

int main() {
    // Print something on the current line
    std::cout << "This is a test command.";

    // Wait for user input
    std::cin.get();

    // Clear the last command line
    system("read -e -p ' '");

    return 0;
}


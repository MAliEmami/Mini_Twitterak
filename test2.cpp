#include <iostream>
#include <windows.h>

// Function to erase the input line
void eraseInputLine() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    COORD startPos = { 0, csbi.dwCursorPosition.Y };
    DWORD numCharsWritten;
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X, startPos, &numCharsWritten);
    SetConsoleCursorPosition(hConsole, startPos);
}

int main() {
    // Print a prompt
    std::cout << "Enter a command: ";

    // Read and erase user input
    std::string input;
    std::getline(std::cin, input);
    eraseInputLine();

    // Print the cleared line
    std::cout << "You entered: " << input << std::endl;

    return 0;
}

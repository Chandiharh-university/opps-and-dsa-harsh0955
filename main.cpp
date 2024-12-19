#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

using namespace std;

int main() {
    // Declare variables
    string input;
    cout << "Enter an integer and a character: ";
    
    // Get the user input
    getline(cin, input);

    // Loop through the input string
    string digits = "";     // To store integer part
    string characters = ""; // To store characters, including brackets

    // Split input into digits and characters
    bool isIntegerPart = true;
    for (char ch : input) {
        if (isdigit(ch) && isIntegerPart) {
            digits += ch; // Add digits to integer part
        } else {
            isIntegerPart = false;
            characters += ch; // Add remaining characters, including brackets
        }
    }

    // Reverse both integer part and character part
    reverse(digits.begin(), digits.end());
    reverse(characters.begin(), characters.end());

    // Output the reversed results
    cout << "Reversed integer: " << digits << endl;
    cout << "Reversed characters: " << characters << endl;

    return 0;
}

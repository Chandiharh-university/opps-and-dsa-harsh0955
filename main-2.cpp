/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

// Function with one integer parameter
void print(int a) {
    cout << "Integer: " << a << endl;
}

// Function with one double parameter
void print(double a) {
    cout << "Double: " << a << endl;
}

// Function with two integer parameters
void print(int a, int b) {
    cout << "Two integers: " << a << ", " << b << endl;
}

// Function with two double parameters
void print(double a, double b) {
    cout << "Two doubles: " << a << ", " << b << endl;
}

// Function with one string parameter
void print(string a) {
    cout << "String: " << a << endl;
}

int main() {
    // Calling overloaded functions with different argument types
    print(5);               // Calls print(int a)
    print(3.14);            // Calls print(double a)
    print(10, 20);          // Calls print(int a, int b)
    print(2.71, 3.14);      // Calls print(double a, double b)
    print("Hello, World!"); // Calls print(string a)

    return 0;
}

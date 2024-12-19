#include <iostream>
using namespace std;

void passByValue(int x) {
    x = 10; 
    cout << "Inside passByValue function: x = " << x << endl;
}

void passByReference(int &x) {
    x = 20;  
    cout << "Inside passByReference function: x = " << x << endl;
}

int main() {
    int a = 5;
    int b = 5;

    cout << "Before passByValue, a = " << a << endl;
    passByValue(a);  // Pass 'a' by value
    cout << "After passByValue, a = " << a << endl;  // 'a' remains unchanged

    cout << "Before passByReference, b = " << b << endl;
    passByReference(b);  // Pass 'b' by reference
    cout << "After passByReference, b = " << b << endl;  // 'b' is modified

    return 0;
}

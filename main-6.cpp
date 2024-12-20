#include <iostream>
using namespace std;

class Base {
public:
    
    virtual void display(int a) {
        cout << "Base class display with integer: " << a << endl;
    }

    virtual void display(double b) {
        cout << "Base class display with double: " << b << endl;
    }
};

class Derived : public Base {
public:

    void display(int a) override {
        cout << "Derived class display with integer: " << a * 2 << endl; // Example of overriding
    }

    void display(int a, int c) {
        cout << "Derived class display with two integers: " << a << " and " << c << endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    basePtr->display(5);        
    
    derivedObj.display(3, 7);   
    derivedObj.display(3.14);    

    return 0;
}
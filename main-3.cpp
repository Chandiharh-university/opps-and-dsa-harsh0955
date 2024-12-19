#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    
    virtual void makeSound() const {
        cout << "Animal makes a sound." << endl;
    }
    
    virtual ~Animal() {
        cout << "Animal destroyed." << endl;
    }
};

class Dog : public Animal {
public:

    void makeSound() const override {
        cout << "Dog barks." << endl;
    }
    
    ~Dog() {
        cout << "Dog destroyed." << endl;
    }
};

class Cat : public Animal {
public:
    
    void makeSound() const override {
        cout << "Cat meows." << endl;
    }
    
    ~Cat() {
        cout << "Cat destroyed." << endl;
    }
};

int main() {
    
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
    animal1->makeSound(); 
    animal2->makeSound();  
    
    delete animal1;
    delete animal2;
    
    return 0;
}

#include <iostream>

class MyClass {
public:

    static void staticFunction() {
        std::cout << "This is a static function!" << std::endl;
    }
    
    void nonStaticFunction() {
        std::cout << "This is a non-static function!" << std::endl;
    }
};

static void outsideStaticFunction() {
    std::cout << "This is a static function outside the class!" << std::endl;
}

int main() {
    
    MyClass::staticFunction();

    MyClass obj;
    obj.nonStaticFunction();
    
    outsideStaticFunction();
    
    return 0;
}

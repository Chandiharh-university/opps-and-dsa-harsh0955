#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack; 
    int maxSize;            

public:

    Stack(int size) : maxSize(size) {}

    void push(int value) {
        if (stack.size() >= maxSize) {
            std::cout << "Stack overflow! Cannot push " << value << std::endl;
            return;
        }
        stack.push_back(value);
        std::cout << "Pushed " << value << " to the stack." << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow! Cannot pop from an empty stack." << std::endl;
            return;
        }
        int value = stack.back();
        stack.pop_back();
        std::cout << "Popped " << value << " from the stack." << std::endl;
    }

    int top() {
        if (isEmpty()) {
            std::cout << "Stack is empty! No top element." << std::endl;
            return -1; 
        }
        return stack.back();
    }

    bool isEmpty() {
        return stack.empty();
    }

    int size() {
        return stack.size();
    }
};

int main() {
    Stack myStack(5); 
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    std::cout << "Top element is: " << myStack.top() << std::endl;

    myStack.pop();
    std::cout << "Top element after pop is: " << myStack.top() << std::endl;

    myStack.pop();
    myStack.pop();
    myStack.pop(); // Attempt to pop from an empty stack

    return 0;
}
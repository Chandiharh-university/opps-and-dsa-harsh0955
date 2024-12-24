#include <iostream>
#include <vector>

class Queue {
private:
    std::vector<int> queue; 
    int maxSize;            
public:
    
    Queue(int size) : maxSize(size) {}

    void enqueue(int value) {
        if (queue.size() >= maxSize) {
            std::cout << "Queue overflow! Cannot enqueue " << value << std::endl;
            return;
        }
        queue.push_back(value);
        std::cout << "Enqueued " << value << " to the queue." << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow! Cannot dequeue from an empty queue." << std::endl;
            return;
        }
        int value = queue.front();
        queue.erase(queue.begin());
        std::cout << "Dequeued " << value << " from the queue." << std::endl;
    }

    int front() {
        if (isEmpty()) {
            std::cout << "Queue is empty! No front element." << std::endl;
            return -1; 
        }
        return queue.front();
    }

    int rear() {
        if (isEmpty()) {
            std::cout << "Queue is empty! No rear element." << std::endl;
            return -1; 
        }
        return queue.back();
    }

    bool isEmpty() {
        return queue.empty();
    }

    int size() {
        return queue.size();
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue items: ";
        for (int item : queue) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue myQueue(5); 

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    
    std::cout << "Front element is: " << myQueue.front() << std::endl;
    std::cout << "Rear element is: " << myQueue.rear() << std::endl;
    std::cout << "Current size of the queue: " << myQueue.size() << std::endl;

    myQueue.display();

    myQueue.dequeue();
    std::cout << "Front element after dequeue is: " << myQueue.front() << std::endl;
    std::cout << "Rear element after dequeue is: " << myQueue.rear() << std::endl;
    std::cout << "Current size of the queue after dequeue: " << myQueue.size() << std::endl;

    myQueue.display();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue(); 

    return 0;
}
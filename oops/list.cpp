#include <iostream>

class LIST {
public:
    virtual void store() = 0;    // Pure virtual function for storing
    virtual void retrieve() = 0; // Pure virtual function for retrieving
};

class Stack : public LIST {
public:
    void store() override {
        std::cout << "Stack: Storing a value." << std::endl;
        // Add code to store a value in the stack
    }

    void retrieve() override {
        std::cout << "Stack: Retrieving a value." << std::endl;
        // Add code to retrieve a value from the stack
    }
};

class Queue : public LIST {
public:
    void store() override {
        std::cout << "Queue: Enqueuing a value." << std::endl;
        // Add code to enqueue a value in the queue
    }

    void retrieve() override {
        std::cout << "Queue: Dequeuing a value." << std::endl;
        // Add code to dequeue a value from the queue
    }
};

int main() {
    Stack stackObj;
    Queue queueObj;

    stackObj.store();
    stackObj.retrieve();

    queueObj.store();
    queueObj.retrieve();

    return 0;
}

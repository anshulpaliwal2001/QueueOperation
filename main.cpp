/*
 *  Author : Anshul Paliwal
 *  For : Practice
 *  */
#include <iostream>

#define Size 10


using namespace std;

class Queue {
private:
    int items[Size], front, rear;

public:
    //Getter Setter
    int getFront() const;

    int getRear() const;

    void setRear(int rear);

    void setFront(int front);

    // Default Constructor
    Queue();                        // Puts -1 to both rear and front initially

    // Utilities
    bool isEmpty();                 // returns true is the Queue is empty else false

    bool isFull();                  // returns true if Queue is Full

    int peek();                     // returns the first element of the Queue if not empty else -1

    //Operations
    void enQueue(int val);          // function to enQueue

    int deQueue();                  // function deQueue

    void display();                 // function to display the queue


};

void Queue::setRear(int rear) {
    Queue::rear = rear;
}

int Queue::getRear() const {
    return rear;
}

void Queue::setFront(int front) {
    Queue::front = front;
}

int Queue::getFront() const {
    return front;
}

Queue::Queue() {
    setFront(-1);
    setRear(-1);
}

bool Queue::isEmpty() {
    if (getFront() == -1)
        return true;
    return false;
}

bool Queue::isFull() {
    if (getFront() == 0 && getRear() == Size - 1)
        return true;
    return false;
}

int Queue::peek() {
    if (isFull()) {
        cout << "Underflow!" << endl;
        return 0;
    }
    cout << "Peek  : " << items[getFront()];
    return items[getFront()];
}

void Queue::enQueue(int val) {
    if (isFull())
        cout << "Overflow !" << endl;
    else {
        if (getFront() == -1)
            setFront(0);
        setRear(getRear() + 1);
        items[getRear()] = val;
        cout << val << " EnQueued successfully" << endl;
    }
}

int Queue::deQueue() {
    int element;
    if (isEmpty()) {
        cout << "Underflow !" << endl;
        return -1;
    } else {
        element = items[getFront()];
        if (getFront() >= getRear()) {
            setRear(-1);
            setFront(-1);
        } else {
            setFront(getFront() + 1);
        }
    }
    cout << "Successfully deQueued " << element << endl;
    return element;
}

void Queue::display() {
    if (isEmpty())
        cout << "Underflow!" << endl;
    else {
        cout << "Front : " << items[getFront()] << endl;
        cout << "Items : ";
        for (int i = getFront(); i <= getRear(); i++) {
            cout << items[i];
            if (i == getRear())
                cout << endl;
            else
                cout << " ";

        }
        cout << "Rear  : " << items[getRear()] << endl;

    }
}

int main() {
    Queue q1;
    q1.enQueue(5);
    q1.enQueue(6);
    q1.enQueue(8);
    q1.enQueue(9);
    q1.display();
    q1.deQueue();
    q1.display();
    q1.peek();
    return 0;
}

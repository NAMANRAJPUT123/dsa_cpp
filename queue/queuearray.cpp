// #include <iostream>
// #define MAX 5
// using namespace std;
// class Queue {
//     int arr[MAX];
//     int front, rear;
// public:
//     Queue() {
//         front = -1;
//         rear = -1;
//     }
//     bool isEmpty() {
//         return (front == -1);
//     }
//     bool isFull() {
//         return (rear == MAX - 1);
//     }
//     void enqueue(int x) {
//         if (isFull()) {
//             cout << "Queue Overflow\n";
//             return;
//         }
//         if (front == -1) front = 0;
//         arr[++rear] = x;
//         cout << x << " inserted into queue\n";
//     }
//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue Underflow\n";
//             return;
//         }
//         cout << arr[front] << " removed from queue\n";
//         if (front == rear) { // Queue becomes empty
//             front = rear = -1;
//         } else {
//             front++;
//         }
//     }
//     void display() {
//         if (isEmpty()) {
//             cout << "Queue is empty\n";
//             return;
//         }
//         cout << "Queue elements: ";
//         for (int i = front; i <= rear; i++)
//             cout << arr[i] << " ";
//         cout << endl;
//     }
// };
// int main() {
//     Queue q;
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.display();
//     q.dequeue();
//     q.display();
//     return 0;
// }

// CIRCULAR QUEUE IMPLEMENTATION
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(50);
    q.enqueue(60); // wraps around
    q.display();
    q.enqueue(70); // should show overflow
    q.display();
    return 0;
}

#include <iostream>
using namespace std;

struct Queue {
    int size = 10;
    int q[10];
    int currsize = 0;
    int front = -1;
    int rear = -1;

    void push(int x) {
        if (currsize == size) {
            cout << "Overflow" << endl;
            return;
        }

        if (currsize == 0) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        q[rear] = x;
        currsize++;
    }

    int pop() {
        if (currsize == 0) {
            cout << "Underflow" << endl;
            return -1;
        }

        int element = q[front];

        if (currsize == 1) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }

        currsize--;
        return element;
    }

    void show() {
        if (currsize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.show();
    
    cout << "Popped: " << q.pop() << endl;
    q.show();
    
    q.push(40);
    q.push(50);
    q.show();
    
    return 0;
}

#include <iostream>
using namespace std;

#define max 6
int queue[max];
int front = -1, rear = -1;

// enqueue
void enqueue(int value) {
    if (rear == max - 1) {
        cout << "queue penuh\n";
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value; // simpan ke array
        cout << value << " masuk ke queue\n";
    }
}

// dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "queue kosong\n";
    } else {
        cout << queue[front] << " keluar dari queue\n";
        front++;
    }
}

// tampilkan isi queue
void display() {
    if (front == -1 || front > rear) {
        cout << "queue kosong\n";
    } else {
        cout << "Isi queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();
    
    enqueue(6);
    display();

    dequeue();
    display();
    
    return 0;
}

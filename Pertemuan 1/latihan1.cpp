#include <iostream>
using namespace std;

#define max 5
int stack[max];
int top = -1; 

// push
void push(int value) {
    if (top == max - 1) { 
        cout << "stack penuh\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " masuk ke stack.\n";
    }
}

// pop
void pop() {
    if (top == -1) {
        cout << "stack kosong\n";
    } else {
        cout << stack[top] << " keluar dari stack.\n";
        top--;
    }
}

// tampilkan isi stack
void display() {
    if (top == -1) {
        cout << "Stack kosong!\n";
    } else {
        cout << "Isi stack: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    
    display();

    
    while (top != -1) {
        pop();
        display();
    }

    return 0;
}
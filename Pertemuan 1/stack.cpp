#include <iostream>
#include <iomanip>

using namespace std;

#define max 5
int stack[max];
int top = -1; 

// push
void push(int value) {
    if (top == max - 1) { 
        cout << "stack penuh\n";
    }
    else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dalam stack\n";
    }
}

// pop
void pop() {
    if (top == -1) {
        cout << "stack kosong\n";
    }
    else {
        cout << stack[top] << " dihapus dari stack.\n";
        top--;
    }
}

// nampilin stack
void display() {
    if (top == -1) {
        cout << "stack kosong\n";
    }
    else {
        cout << "\nIsi stack (dari atas ke bawah): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }

        cout << "\nIsi array (index 0 ke max-1):\n";
        for (int i = 0; i <= top; i++) {
            cout << "[ " << i << " ] " << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display();

    return 0;
}

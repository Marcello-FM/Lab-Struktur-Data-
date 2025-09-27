#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push (int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed to stack\n";
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is empty, cannot pop\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << temp->data << " popped from stack\n";
    delete temp;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    system ("cls");
    int choice, value;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
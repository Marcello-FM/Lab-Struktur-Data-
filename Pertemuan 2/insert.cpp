#include <iostream>
using namespace std;

// Deklarasi struktur node
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; // inisialisasi head
Node* tail = nullptr; // inisialisasi tail

// Fungsi insert di depan
void insertFront(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        // Jika list kosong
        newNode->next = nullptr;
        head = tail = newNode;
    } else {
        // Jika list tidak kosong
        newNode->next = head;
        head = newNode;
    }

    cout << value << " masuk di depan.\n";
}

// Fungsi insert di belakang
void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        // Jika list kosong
        head = tail = newNode;
    } else {
        // Tambah di belakang
        tail->next = newNode;
        tail = newNode;
    }

    cout << value << " masuk di belakang.\n";
}

// Insert setelah node dengan nilai tertentu 
void insertAfter(int value, int check) {
    if (head == nullptr) {
        cout << "List kosong, tidak bisa insert setelah " << check << ".\n";
        return;
    }

    Node* current = head;
    while (current != nullptr && current->data != check) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node dengan nilai " << check << " tidak ditemukan.\n";
    } else {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = current->next;
        current->next = newNode;

        if (current == tail) {
            tail = newNode; 
        }

        cout << value << " masuk setelah " << check << ".\n";
    }
}

// Cetak isi linked list
void printList() {
    Node* temp = head;
    cout << "Isi linked list: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertFront(10);    
    insertFront(20);     
    insertLast(30);      
    insertLast(40);      
    insertAfter(25, 20); 
    insertFront(5);      

    printList(); 

    return 0;
}

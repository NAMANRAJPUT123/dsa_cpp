#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// Insert at the beginning
void insertAtBeginning(struct Node*& head, int value) { // in c you must write struct in cpp not required
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}
// Insert at the end
void insertAtEnd(struct Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) { // empty list
        newNode->prev = nullptr;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
// Delete at the end
void deleteAtEnd(struct Node*& head) {
    if (head == nullptr) return; // empty list
    if (head->next == nullptr) { // single node
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}
// Insert at a given position (1-based index)
void insertAtPosition(struct Node*& head, int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}
// Delete at head
void deleteAtHead(struct Node*& head) {
    if (head == nullptr) return; // empty list
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}
// Delete at a given position (1-based index)
void deleteAtPosition(struct Node*& head, int pos) {
    if (head == nullptr) return; // empty list
    if (pos == 1) {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++) // moving to the position
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }
    if (temp->next != nullptr)  // handle tail case
        temp->next->prev = temp->prev;
    if (temp->prev != nullptr)  // handle head case
        temp->prev->next = temp->next;

    delete temp;
}
// Get at a given position (1-based index)
Node* getAtPosition(struct Node* head, int pos) {
    Node* temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++)
        temp = temp->next;
    return temp; // returns nullptr if position is out of range
}
// Display list forward
void display(struct Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    insertAtEnd(head, 10);       // 10
    insertAtBeginning(head, 5);  // 5 10
    insertAtEnd(head, 20);       // 5 10 20
    insertAtPosition(head, 15, 3); // 5 10 15 20
    display(head);
    deleteAtPosition(head, 2);   // 5 15 20
    display(head);
    return 0;
}

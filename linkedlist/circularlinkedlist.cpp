// circular linked list
// #include <iostream>
// using namespace std;
// struct Node {
//     int data;
//     struct Node* next;
// };
// // Insert at the beginning
// void insertAtBeginning(struct Node*& head, int value) { // in c you must write struct in cpp not required
//     Node* newNode = new Node();
//     newNode->data = value;
//     if (head == nullptr) {
//         newNode->next = newNode; // point to itself
//         head = newNode;
//         return;
//     }
//     Node* temp = head;
//     while (temp->next != head) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->next = head;
//     head = newNode;
// }
// // Insert at the end
// void insertAtEnd(struct Node*& head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     if (head == nullptr) { // empty list
//         newNode->next = newNode; // point to itself
//         head = newNode;
//         return;
//     }
//     Node* temp = head;
//     while (temp->next != head) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->next = head;
// }
// // Insert at a given position (1-based index)
// void insertAtPosition(struct Node*& head, int value, int pos) {
//     if (pos == 1) {
//         insertAtBeginning(head, value);
//         return;
//     }
//     Node* temp = head;
//     for (int i = 1; i < pos - 1 && temp->next != head; i++)
//         temp = temp->next;
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = temp->next; // could be head if inserting at end
//     temp->next = newNode;           
// }
// // Delete at head
// void deleteAtHead(struct Node*& head) {
//     if (head == nullptr) return; // empty list
//     if (head->next == head) { // single node
//         delete head;
//         head = nullptr;
//         return;
//     }
//     Node* temp = head;
//     while (temp->next != head) {
//         temp = temp->next;
//     }
//     Node* toDelete = head;
//     head = head->next;
//     temp->next = head;
//     delete toDelete;
// }
// // Get at a given position (1-based index)
// Node* getAtPosition(struct Node* head, int pos) {
//     if (head == nullptr) return nullptr; // empty list
//     Node* temp = head;
//     for (int i = 1; i < pos; i++) {
//         temp = temp->next;
//         if (temp == head) return nullptr; // position out of range
//     }
//     return temp;
// }
// // Display list
// void display(struct Node* head) {
//     if (head == nullptr) {
//         cout << "List is empty\n";
//         return;
//     }
//     Node* temp = head;
//     do {
//         cout << temp->data << " ";
//         temp = temp->next;
//     } while (temp != head);
//     cout << endl;
// }
// int main() {
//     struct Node* head = nullptr;
//     insertAtEnd(head, 10);       // 10
//     insertAtBeginning(head, 5);  // 5 10
//     insertAtEnd(head, 20);       // 5 10 20
//     insertAtPosition(head, 15, 3); // 5 10 15 20
//     display(head);
//     deleteAtHead(head);          // 10 15 20
//     display(head);
//     Node* node = getAtPosition(head, 2); // should return node with value 15
//     if (node) cout << "Node at position 2: " << node->data << endl;
//     else cout << "Position out of range\n";
//     return 0;
// }
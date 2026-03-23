#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};
struct linkedlist {
    node* head;
    node* tail;
    int size;
    // Constructor
    linkedlist() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // Destructor (frees all nodes)
    ~linkedlist() {
        node* current = head;
        while (current != NULL) {
            node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
        tail = NULL;
        size = 0;
        cout << "Linked list destroyed!" << endl;
    }
    // Insert at end
    void insertAtTail(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        size++;
    }
    // Insert at beginning
    void insertAtHead(int val) {
        node* n = new node(val);
        if (size == 0) {
            head = n;
            tail = n;
        } else {
            n->next = head;
            head = n;
        }
        size++;
    }
    // Insert at a specific position
    void insertAtPosition(int val, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0) {
            insertAtHead(val);
            return;
        }
        if (pos == size) {
            insertAtTail(val);
            return;
        }
        node* n = new node(val);
        node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        size++;
    }
    void insertBeforeKey(int val, int key) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    node* n = new node(val);
    // Case 1: insert before head
    if (head->data == key) {
        n->next = head;
        head = n;
        size++;
        return;
    }
    // Case 2: search for key
    node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    // Case 3: key found
    if (temp->next != NULL) {
        n->next = temp->next;
        temp->next = n;
        size++;
    }
    else {
        cout << "Key not found" << endl;
        delete n; // avoid memory leak
    }
}
    void insertAfterKey(int val,int key){
        node* n = new node(val);
        node* temp = head;
        if(key==head->data){
            n->next = head->next;
            head->next= n;
            size++;
            return;
        }
        while(temp!=NULL && temp->data!=key){
            temp = temp->next;
        }
        if(temp!=NULL && temp->next!=NULL){
            n->next = temp->next;
            temp->next = n;
            size++;
            return;
        }
        if(temp!=NULL && temp->next == NULL){
            tail->next = n;
            tail = n;
            size++;
            return;
        }
        else cout<<"Key not found"<<endl; delete n;
    }
    // Display list
    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Get element at position
    int getAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
            return -1;
        }
        node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    // Delete node at position
    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
            return;
        }
        node* temp = head;
        if (pos == 0) {
            head = temp->next;
            if (size == 1) tail = NULL; cout<<"Index "<<pos<<" Deleted"<<endl;
            delete temp;
        } else {
            for (int i = 0; i < pos-1; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next; cout<<"Index "<<pos<<" Deleted"<<endl;
            if (pos == size - 1) tail = temp;
        }
        size--;
    }
    // Search for a value
    node* searching(int key) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) return temp;
            temp = temp->next;
        }
        return NULL;
    }
    // Display reverse using recursion
    void displayReverse(node* head) {
        if (head == NULL) {
            return;
        }
        displayReverse(head->next);
        cout << head->data << " ";
    }
};
int main() {
    linkedlist ll;
    ll.insertAtTail(5);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtHead(10);
    ll.insertAtPosition(6, 2);
    ll.insertAtTail(7);
    ll.display();
    cout << "Element at index 3: " << ll.getAt(3) << endl;
    ll.deleteAt(3);
    ll.display();
    cout << "Size: " << ll.size << endl;
    node* found = ll.searching(7);
    if (found != NULL) {
        cout << "Found: " << found->data << endl;
    } else {
        cout << "Not Found" << endl;
    }
    cout << "Reverse display: ";
    ll.displayReverse(ll.head);
    cout << endl;
    ll.insertBeforeKey(45,6);
    ll.display();
    cout<<"Size : "<<ll.size<<endl;
    ll.insertAfterKey(49,6);
    ll.display();
    cout<<"Size : "<<ll.size<<endl;
    // Destructor will run automatically when ll goes out of scope
    return 0;
}

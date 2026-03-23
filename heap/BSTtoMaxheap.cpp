//BST to Max Heap Conversion   

#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Step 1: Inorder traversal (store sorted values)
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
// Step 2: Postorder traversal (assign values from array)
void postorderAssign(Node* root, vector<int>& arr, int &index) { // postorder travel krte krte value assign krni hai tree nodes ko
    if (!root) return;
    postorderAssign(root->left, arr, index);
    postorderAssign(root->right, arr, index);
    root->data = arr[index++]; // assign next smallest value
}
// Step 3: Convert BST to Max Heap
void convertToMaxHeap(Node* root) {
    vector<int> arr;
    inorder(root, arr);        // store sorted values
    int index = 0;
    postorderAssign(root, arr, index); // assign in postorder
}
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    cout << "BST (Preorder): ";
    preorder(root);
    cout << endl;
    convertToMaxHeap(root);
    cout << "Converted Max Heap (Preorder): ";
    preorder(root);
    cout << endl;
    return 0;
}

// // BST to MinHeap Conversion
// #include <iostream>
// #include <vector>
// using namespace std;
// struct Node {
//     int data;
//     Node *left, *right;
//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };
// // Step 1: Inorder traversal — store sorted values
// void inorder(Node* root, vector<int>& arr) {
//     if (!root) return;
//     inorder(root->left, arr);
//     arr.push_back(root->data);
//     inorder(root->right, arr);
// }

// // Step 2: Preorder traversal — assign values from sorted array
// void preorderAssign(Node* root, vector<int>& arr, int &index) {
//     if (!root) return;
//     root->data = arr[index++];  // assign smallest available value
//     preorderAssign(root->left, arr, index);
//     preorderAssign(root->right, arr, index);
// }

// // Step 3: Convert BST → Min Heap
// void convertToMinHeap(Node* root) {
//     vector<int> arr;
//     inorder(root, arr);          // get sorted values
//     int index = 0;
//     preorderAssign(root, arr, index); // assign values in preorder
// }
// void preorder(Node* root) {
//     if (!root) return;
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }
// int main() {
//     Node* root = new Node(4);
//     root->left = new Node(2);
//     root->right = new Node(6);
//     root->left->left = new Node(1);
//     root->left->right = new Node(3);
//     root->right->left = new Node(5);
//     root->right->right = new Node(7);
//     cout << "BST (Preorder): ";
//     preorder(root);
//     cout << endl;
//     convertToMinHeap(root);
//     cout << "Converted Min Heap (Preorder): ";
//     preorder(root);
//     cout << endl;
//     return 0;
// }

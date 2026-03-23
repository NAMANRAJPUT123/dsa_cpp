#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
// Step 1: Check if tree is Complete Binary Tree
bool isCompleteTree(Node* root) {
    if (!root) return true;
    queue<Node*> q;
    q.push(root);
    bool nullFound = false; // flag to detect NULL node
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr == NULL) {
            nullFound = true;
        } else {
            if (nullFound) 
                return false; // found a non-null after null → not complete
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return true;
}
// Step 2: Check Max-Heap property
bool isMaxHeapProperty(Node* root) {
    if (!root) return true;
    // Leaf node
    if (!root->left && !root->right) 
        return true;
    // Only left child
    if (root->left && !root->right)
        return (root->data >= root->left->data) && isMaxHeapProperty(root->left);

    // Both children
    if (root->left && root->right)
    return (root->data >= root->left->data) && (root->data >= root->right->data) && isMaxHeapProperty(root->left) && isMaxHeapProperty(root->right);
    return true;
}
bool isBinaryTreeMaxHeap(Node* root) {
    return isCompleteTree(root) && isMaxHeapProperty(root);
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(1);
    root->right->right = new Node(4);
    if (isBinaryTreeMaxHeap(root))
        cout << "The binary tree is a Max Heap\n";
    else
        cout << "The binary tree is NOT a Max Heap\n";
    
    return 0;
}

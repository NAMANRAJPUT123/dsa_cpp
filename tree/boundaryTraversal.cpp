#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
class node {  
public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node* construct(int arr[], int n) {
    if(n==0) return NULL;
    queue<node*> q;
    node* root = new node(arr[0]);
    q.push(root);
    int i = 1;
    while(!q.empty() && i < n) {
        node* temp = q.front();
        q.pop();

        if(arr[i] != INT_MIN) {
            temp->left = new node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(i < n && arr[i] != INT_MIN) {
            temp->right = new node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
void leftBoundary(node* root) {
    node* temp = root->left;
    while(temp) {
        if(temp->left || temp->right) cout << temp->data << " ";
        temp = (temp->left) ? temp->left : temp->right;
    }
}
void rightBoundary(node* root) {
    node* temp = root->right;
    stack<int> s;
    while(temp) {
        if(temp->left || temp->right) s.push(temp->data);
        temp = (temp->right) ? temp->right : temp->left;
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
void leafNodes(node* root) {
    if(!root) return;
    if(!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }
    leafNodes(root->left);
    leafNodes(root->right);
}
void boundaryTraversal(node* root) {
    if(!root) return;
    cout << root->data << " ";
    leftBoundary(root);
    leafNodes(root->left);
    leafNodes(root->right);
    rightBoundary(root);
}
int main() {
    int arr[] = {1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,27,INT_MIN,INT_MIN,28,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = construct(arr,n);
    boundaryTraversal(root);
    return 0;
}

#include<iostream>
#include<climits>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void display(node* root){ // preorder display
    if(root == NULL) return;
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}
int sum(node* root){
    if(root == NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}
int productAllNodes(node* root){
    if(root == NULL) return 1;
    return root->data*productAllNodes(root->left)*productAllNodes(root->right);
}
int size(node* root){
    if(root==NULL) return 0;
    return 1+ size(root->left) + size(root->right); 
}
int maxINTree(node* root){
    if(root == NULL) return INT_MIN;
    return max(root->data, max(maxINTree(root->left), maxINTree(root->right)));
}
int heightOfTree(node* root){
    if(root == NULL) return -1;  // empty tree height = -1
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(9);
    root->left->right = new node(5);
    display(root);
    cout<<endl;
    cout<<sum(root)<<endl;
    cout<<size(root)<<endl;
    cout<<maxINTree(root)<<endl;
    cout<<productAllNodes(root)<<endl;
    cout<<heightOfTree(root);
    return 0;
}
#include<iostream>
#include<queue>
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
void displaypre(node* root){ // preorder display  (root-left-right)
    if(root == NULL) return;
    cout<<root->data<<" ";
    displaypre(root->left);
    displaypre(root->right);
}
void levelOrder(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(9);
    root->left->left->right = new node(10);
    root->left->right = new node(5); 
    root->right->left = new node(6);
    displaypre(root);
    cout<<endl;
    levelOrder(root);
    return 0;
}
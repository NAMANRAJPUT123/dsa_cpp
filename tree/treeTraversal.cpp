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
void displaypre(node* root){ // preorder display  (root-left-right)
    if(root == NULL) return;
    cout<<root->data<<" ";
    displaypre(root->left);
    displaypre(root->right);
}
void displaypost(node* root){ // postorder display  (left-right-root)
    if(root == NULL) return;
    displaypost(root->left);
    displaypost(root->right);
    cout<<root->data<<" ";
}
void displayin(node* root){ // inorder display (left-root-right )
    if(root == NULL) return;
    displayin(root->left);
    cout<<root->data<<" ";
    displayin(root->right);
}
void printnthlr(node* root,int curr,int level){  // left to right print of nth level
    if(root==NULL) return;
    if(curr==level){
        cout<<root->data<<" ";
        return;  // to avoid further calls after printing the required level
    } 
    printnthlr(root->left,curr+1,level);
    printnthlr(root->right,curr+1,level);
}
void printnthrl(node* root,int curr,int level){  // right to left print of nth level
    if(root==NULL) return;
    if(curr==level){
        cout<<root->data<<" ";
        return;  // to avoid further calls after printing the required level
    } 
    printnthrl(root->right,curr+1,level);
    printnthrl(root->left,curr+1,level);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(9);
    root->left->right = new node(5);
    displaypre(root);
    cout<<endl;
    displayin(root);
    cout<<endl;
    displaypost(root);
    cout<<endl;
    printnthlr(root,0,2);
    cout<<endl;
    printnthrl(root,0,2);
}
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
node* construct(int arr[], int n){
    queue<node*> q;
    node* root = new node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        node* temp = q.front();
        q.pop();
        node* l;
        node* r;
        if(arr[i]!=INT_MIN) l = new node(arr[i]);
        else l = NULL;
        if(j!=n && arr[j]!=INT_MIN) r = new node(arr[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}
void levelOrderqueue(node* root){
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
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = construct(arr,n);
    levelOrderqueue(root);
    return 0;
}
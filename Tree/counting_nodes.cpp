#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node *left=nullptr;
    Node *right=nullptr;

    Node(int val):data(val) {}

};

int count(Node *root){
    if(root==nullptr) return 0;
    return 1+ count(root->left) + count(root->right);
}

int main(){
    Node *root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(3);
    (root->left)->left=new Node(5);
    (root->left)->right=new Node(6);
    (root->right)->left=new Node(7);
    (root->left->left)->left=new Node(8);
    cout<<count(root)<<endl;
    
    return 0;
}
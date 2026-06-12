#include<iostream>
#include<vector>
using namespace std; 

struct Node{
    int data;
    Node* left=nullptr;
    Node* right=nullptr;

    Node(int val):data(val) {}
};

int findMax(Node *root){
    if(root==nullptr) return 0;

    int maxval=root->data;
    int left=findMax(root->left);
    int right=findMax(root->right);

    return max(maxval,max(left,right));
}

void createADJ(Node *root,vector<vector<int>> & adj){
    if(root==nullptr) return;

    if(root->left){
        adj[root->data].push_back(root->left->data);
        adj[root->left->data].push_back(root->data);
    }
    if(root->right){
        adj[root->data].push_back(root->right->data);
        adj[root->right->data].push_back(root->data);
    }

    createADJ(root->left,adj);
    createADJ(root->right,adj);
}

int main(){
    Node *root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(3);
    (root->left)->left=new Node(5);
    (root->left)->right=new Node(6);
    (root->right)->left=new Node(7);
    (root->left->left)->left=new Node(8);    
    long n=findMax(root);

    vector<vector<int>> adj(n+1);
    createADJ(root,adj);

    for(int i=0;i<adj.size();++i){
        if(!adj[i].empty()){
            cout<<"Nodes of "<<i<<":= ";
            for(auto j:adj[i]){
                cout<<j<<"-->";
            }
            cout<<"Null"<<endl;
        }
    }

    return 0;
}
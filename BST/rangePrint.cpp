// You are given an array of integers. First of all , You have to form a binary search tree from given integers. 
// Now you have provided two integers k1 and k2.
// You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* built(node*root, int d){

    if(root==NULL){
        root= new node(d);
        return root;
    }
    if(d < root->data){
        root->left= built(root->left,d);
        return root;
    }
    else{
        root->right= built(root->right,d);
        return root;
    }
}

void print(node*root, int k1, int k2){
    if(root==NULL){
        return;
    }
    if(root->data>=k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
    print(root->left,k1,k2);
    print(root->right,k1,k2);
}

int main(){
    int t;
    cin>>t;
    while (t>0){
        int n,d;
        cin>>n;
        int a[10000];
        node*root = NULL;
        for(int i=0;i<n;i++){
            cin>>d;
            root= built(root,d);
        }
        int k1,k2;
        cin>>k1>>k2;
        print(root,k1,k2);
        t--;
    }
    
    return 0;
}
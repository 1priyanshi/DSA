// You are given a sorted data of n integers. 
// You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

node* printBST(int *a, int s,int e){

    int m=(s+e)/2;
    if(s>e){
        return NULL;
    }
    node* root= new node(a[m]);
    root->left= printBST(a,s,m-1);
    root->right= printBST(a,m+1,e);
    return root;
}

void print(node*root){
    if(root== NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main(){
    int t;
    cin>>t;
    while (t>0){
        int n,a[10000];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        node* root= printBST(a,0,n-1);
        print(root);
        t--;
    }
    
    return 0;
}
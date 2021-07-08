// You are given an array A1 of integers. You have to form first Binary Search tree and then you 
// are provided another array A2. You have to delete each node from the BST which is present in the array A2. 
// Now you have to print preorder traversal of the tree. It is assured that the elements of array A2 will be present in the tree.
// Note : In case of node with 2 children, consider its inorder successor as its replacement.

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data=d;
            left= NULL;
            right=NULL;
        }
};

node* build(int d, node*root){
    if(root==NULL){
        root= new node(d);
        return root;
    }
    if(d<root->data){
        root->left=build(d,root->left);
        return root;
    }
    else{
        root->right=build(d,root->right);
        return root;
    }
}

node* deleteTree(int d, node*root){
    if(root==NULL){
        return NULL;
    }
    if(d<root->data){
        root->left=deleteTree(d,root->left);
        return root;
    }
    else if(d==root->data){
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            node* temp= root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            node* temp= root->right;
            delete(root);
            return temp;
        }

        node* replace= root->right;
        while (replace->left!=NULL){
            replace=replace->left;
        }
        root->data=replace->data;
        root->right= deleteTree(replace->data,root->right);
        return root;
    }
    else{
        root->right=deleteTree(d,root->right);
        return root;
    }
}

void print(node*root){

    if(root==NULL){
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
        int n,m,a[1000],b[1000];
        cin>>n;
        node*root= NULL;
        for(int i=0;i<n;i++){
            cin>>a[i];
            root= build(a[i],root);
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>b[i];
            root= deleteTree(b[i],root);
        }
        print(root);
        cout<<endl;
        t--;
    }
    return 0;
}
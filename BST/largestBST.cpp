// Given a Binary Tree, write a program that returns the size of the largest subtree which is also a Binary Search Tree (BST)
// The first line of input will contain an integer n. 
// The next line will contain n integers denoting the the preorder traversal of the BT.
// The next line will contain n more integers denoting the inorder traversal of the BT.

#include<iostream>
#include<climits>
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


node* build(int*pre, int*in, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }

    node* root= new node(pre[i]);
    int index=-1;
    for(int j=0;j<=e;j++){
        if(in[j]== pre[i]){
            index=j;
            break;
        }
    }
    i++;
    root->left= build(pre, in, s, index-1);
    root->right=build(pre,in,index+1,e);
    return root;
}

bool isBST(node*root, int minv, int maxv){
    if(root==NULL){
        return true;
    }
    if(root->data>=minv && root->data<maxv && isBST(root->left,minv,root->data) && isBST(root->right,root->data,maxv)){
        return true;
    } 
    return false;
}

int nodes(node*root){
    if(root==NULL){
        return 0;
    }
    return nodes(root->left)+ nodes(root->right)+1;
}

int isvalid(node*root){
    if(root==NULL){
        return 0;
    }
    if(isBST(root,INT_MIN,INT_MAX)){
        return nodes(root);
    }
    return max(isvalid(root->left),isvalid(root->right));
}

int main(){
    int n;
    cin>>n;
    int a[1000],b[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    node* root= build(a,b,0,n-1);
    cout<< isvalid(root);
    return 0;
}
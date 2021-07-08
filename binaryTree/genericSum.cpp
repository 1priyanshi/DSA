#include<iostream>
#include<queue>
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

node* buildTree(){
    pair<int,int>p;
    cin>>p.first>>p.second;  
    node*root= new node(p.first);
    if(p.second==0){
        return root;
    }
    root->left= buildTree();
    root->right=buildTree();
    return root;
}

int sumtree(node*root, int k){
    if(root==NULL){
        return 0;
    }
    if(k==0){
        return root->data;
    }
    int l= sumtree(root->left,k-1);
    int r= sumtree(root->right,k-1);
    return l+r;
}

int main(){
    node* root= buildTree();
    int k;
    cin>>k;
    
    int s= sumtree(root,k);
    cout<<s;
    return 0;
}
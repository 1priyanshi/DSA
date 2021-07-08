// Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. 
// Include the current node's data also.

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

node* build(int *a, int s, int e){
    static int sum=0;
    int m=(s+e)/2;
    if(s>e){
        return NULL;
    }
    node* root= new node(a[m]);
    root->left= build(a,s,m-1);
    root->right= build(a,m+1,e);
    return root;
}

node* sumNode(node* root){
    static int s=0;
    if(root==NULL){
        return NULL;
    }
    sumNode(root->right);
    s = s + root->data;
    root->data= s;
    sumNode(root->left);
    return root;
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
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    node* root= build(a,0,n-1);
    node* root2= sumNode(root);
    print(root2);
    return 0;
}
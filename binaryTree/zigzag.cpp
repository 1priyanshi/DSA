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


node* build(string s){
    if(s=="true"){
        int d;
        cin>>d;
        node* root= new node(d);
        string l;
        cin>>l;
        if(l=="true"){
            root->left= build(l);
        }
        string r;
        cin>>r;
        if(r=="true"){
            root->right= build(r);
        }
        return root;
    }
    return NULL;
}

int height(node*root){
    if(root==NULL){
        return 0;
    }

    int ls= height(root->left);
    int rs= height(root->right);
    return max(ls,rs)+1;
}

void printkp(node *root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    printkp(root->left,k-1);
    printkp(root->right,k-1);
}

void printkn(node *root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    printkp(root->right,k-1);
    printkp(root->left,k-1);
}

void print(node*root){
    if(root==NULL){
        return;
    }
    int h= height(root);
    for(int i=1;i<=h;i++){
        if(i%2==0){
            printkn(root,i);
        }
        else{
            printkp(root,i);
        }
    }
}
int main(){
    node* root= build("true");
    print(root);
    return 0;
}
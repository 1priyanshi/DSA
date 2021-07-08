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

node* buildTree(string s){

    if(s=="true"){
        int d;
        cin>>d;
        node* root = new node(d);
        string l;
        cin>>l;
        if(l=="true"){
            root->left= buildTree(l); 
        }
        string r;
        cin>>r;
        if(r=="true"){
            root->right= buildTree(r);
        }
        return root;
    }  
    return NULL;
}

bool compare(node*root1,node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL ||root2==NULL){
        return false;
    }
    if(!compare(root1->left,root2->left)){
        return false;
    }
    if(!compare(root1->right,root2->right)){
        return false;
    }
    return true;
}


int main(){
    node* root= buildTree("true");
    node* root2= buildTree("true");
    if(compare(root,root2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
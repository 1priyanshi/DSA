#include<iostream>
#include<math.h>
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

class hbpair{
    public:
    int height;
    bool balance;
};

hbpair isBalanced(node* root){
    hbpair p;
    if(root==NULL){
        p.height= 0;
        p.balance= true;
        return p;
    }
    hbpair l= isBalanced(root->left);
    hbpair r= isBalanced(root->right);

    p.height= max(l.balance,r.balance)+1;

    if(abs(l.height-r.height)<=1 && l.balance && r.balance){
        p.balance= true;
    }
    else{
        p.balance=false;
    }
    return p;
}

int main(){
    node* root= build("true");
    if(isBalanced(root).balance){
        cout<<"true";
    }
    else
    cout<<"false";
    return 0;
}
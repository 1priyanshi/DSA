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


node* build(){
    int d;
    cin>>d;
    node*root=NULL;

    if(d!=-1){
        root=new node(d);
        queue<node*>q;
        q.push(root);
        while (!q.empty()){
            node*f= q.front();
            q.pop();
            int d1,d2;
            cin>>d1>>d2;
            if(d1!=-1){
                f->left=new node(d1);
                q.push(f->left);
            }
             if(d2!=-1){
                    f->right= new node(d2);
                    q.push(f->right);
            }
        }   
    }
    return root;
}

void topviewl(node*root, int l, int maxl){
    if(root==NULL){
        return;
    }
    if(maxl<l){
        cout<<root->data<<" ";
        maxl=l;
    }
    topviewl(root->left,l+1,maxl);
    topviewl(root->right,l-1,maxl);
}


void topviewr(node*root, int l, int maxl, int a){
    if(root==NULL){
        return;
    }

    if(maxl<l){
        if(root->data!=a)
        cout<<root->data<<" ";
        maxl=l;
    }
    topviewr(root->right,l+1,maxl,a);
    topviewr(root->left,l-1,maxl,a);
}


int main(){
    node*root=build();
    int a= root->data;
    topviewl(root,0,-1);
    topviewr(root,0,-1,a);
    return 0;
}
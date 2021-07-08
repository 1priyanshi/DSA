// Given a binary tree, a target node in the binary tree, and an integer value k, 
// print all the nodes that are at distance k from the given target node. 
// No parent pointers are available. Print 0 if no such node exist at distance k.

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

void printkthlevel(node*root, int k){

    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
}

int printAtDistanceK(node*root, int target, int k, bool &value){

    if(root==NULL)
        return -1;
    
    if(root->data==target){
        printkthlevel(root,k);
        return 0;
    }

    int DL= printAtDistanceK(root->left,target,k,value);

    if(DL!=-1){
        if(DL+1==k){
            cout<<root->data<<" ";
            value= true;
        }
        else{
            printkthlevel(root->right, k-2-DL);
        }
        return 1+DL;
    }

     int DR= printAtDistanceK(root->right,target,k,value);

    if(DR!=-1){
        if(DR+1==k){
            cout<<root->data<<" ";
            value=true;
        }
        else{
            printkthlevel(root->left, k-2-DR);
        }
        return 1+DR;
    }
    return -1;
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
   
    int t;
    cin>>t;
    while (t>0){
        int k,a;
        cin>>a>>k;
        bool value= false;
        printAtDistanceK(root,a,k,value);
        if(value==false){
        cout<<'0';
        }
        cout<<endl;
        t--;
    }
    return 0;
}
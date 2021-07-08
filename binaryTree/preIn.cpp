#include<iostream>
using namespace std;


class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data =d;
            left=NULL;
            right=NULL;
        }
};

node* preIn(int *in, int*pre, int s, int e){

    static int i=0;
    if(s>e){
        return NULL;
    }

    node* root= new node(pre[i]);
    int index=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index= j;
            break;
        }
    }
    i++;

    root->left= preIn(in,pre,s,index-1);
    root->right= preIn(in, pre, index+1,e);
    return root;
}

void print(node*root){

    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right!=NULL){
        cout<<"END"<<" => "<<root->data<<" <= "<<root->right->data;
        cout<<endl;
    }
    else if(root->left!=NULL && root->right!=NULL){
        cout<<root->left->data<<" => "<<root->data<<" <= "<<root->right->data;
        cout<<endl;
    }
    else if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data<<" => "<<root->data<<" <= "<<"END";
        cout<<endl;
    }
    else if(root->left==NULL && root->right==NULL){
         cout<<"END"<<" => "<<root->data<<" <= "<<"END";
        cout<<endl;
    }
    print(root->left);
    print(root->right);
}


int main(){
    int n,m,a[100000],b[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    node*root= preIn(b,a,0,n-1);
    print(root);
    return 0;
}
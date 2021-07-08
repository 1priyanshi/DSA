#include<iostream>
#include<queue>
#include<climits>
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

node* insertinBST(node*root,int d){
    if(root==NULL){
        return new node(d);
    }
    if(d<=root->data){
        root->left=insertinBST(root->left,d);
    }
    else{
        root->right= insertinBST(root->right,d);
    }
    return root;
}

bool search(node*root, int k){
    if(root==NULL){
        return 0;
    }
    if(root->data==k){
        return 1;
    }
    if(k<=root->data){
        return search(root->left,k);
    }
    else{
        return search(root->right,k);
    }
}

void bfs(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        node*f =q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
         else{
                cout<<f->data<<",";
                q.pop();

                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
    
}

node* build(){
    int d;
    cin>>d;

    node*root=NULL;

    while(d!=-1){
        root=insertinBST(root,d);
        cin>>d;
    }
    return root;
}

void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}


node* deleteInBST(node*root,int data){
    
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left=deleteInBST(root->left,data);
        return root;
    }
    else if(data==root->data){
        if(root->left==NULL&& root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        
        node* replace = root->right;
        while (replace->left!=NULL){
            replace=replace->left;
        }

        root->data=replace->data;
        root->right=deleteInBST(root->right,replace->data);
        return root;

    }
    else{
        root->right= deleteInBST(root->right,data);
        return root;
    }
}

bool isBST(node* root, int minv=INT_MIN, int maxv= INT_MAX){
    if(root==NULL){
        return true;                //check
    }
    if(root->data>=minv && root->data<=maxv && isBST(root->left,minv,root->data)&& isBST(root->right,root->data,maxv)){
        return true;
    }
    else{
        return false;
    }
}

class Linkedlist{
    public:
        node*head;
        node*tail;
};

Linkedlist flattern(node*root){
    Linkedlist l;

    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }

    if(root->left==NULL && root->right==NULL){
        l.head=l.tail=root;
        return l;
    }


    if(root->left!=NULL && root->right==NULL){
        Linkedlist leftll = flattern(root->left);
        leftll.tail->right=root;     
        l.head= leftll.head;
        l.tail=root;
        return l;
    }

    if(root->left==NULL && root->right!=NULL){
        Linkedlist rightll = flattern(root->right);
        root->right= rightll.head;
        l.head=root;
        l.tail=rightll.tail;
        return l;
    }

    Linkedlist leftll = flattern(root->left);
    Linkedlist rightll = flattern(root->right);

    leftll.tail->right=root;
    root->right= rightll.head;
    l.head=leftll.head;
    l.tail = rightll.tail;
    return l;
}

int main(){
    node*root=build();
    inorder(root);
    cout<<endl;
    bfs(root);
    // bfs(root);
    // int s;
    // cin>>s;

    // root= deleteInBST(root,s);
    // inorder(root);
    // cout<<endl;
    // bfs(root);
    // if(search(root,s)){
    //     cout<<"present";
    // }
    // else{
    //     cout<<"not p";
    // }
    if(isBST(root)){
        cout<<"Yes";
    }
    else{
        cout<<"No";

    }
    // Linkedlist l= flattern(root);
    // node* temp= l.head;

    // while (temp!=NULL){
    //     cout<<temp->data<<"-->";
    //     temp= temp->right;
    // }
    // cout<<endl;
    
    return 0;
}
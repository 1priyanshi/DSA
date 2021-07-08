// Given a Binary Tree, we need to print the bottom view from left to right. 
// A node x is there in output if x is the bottommost node at its horizontal distance. 
// Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, 
// and that of right child is horizontal distance of x plus 1. 

// Examples: 

//                       20
//                     /    \
//                   8       22
//                 /   \      \
//               5      3      25
//                     / \      
//                   10    14


// The following are steps to print Bottom View of Binary Tree. 
// 1. We put tree nodes in a queue for the level order traversal. 
// 2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the 
// horizontal distance as hd-1 and right child as hd+1. 
// 3. Also, use a TreeMap which stores key value pair sorted on key. 
// 4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the 
// node data for the horizontal distance as key. For the first time it will add to the map, 
// next time it will replace the value. This will make sure that the bottom most element for that 
// horizontal distance is present in the map and if you see the tree from beneath that you will see that element.



#include<iostream>
#include<climits>
#include<map>
#include<queue>
using namespace std;

class node{
    public:
        int data,hd;
        node*left;
        node*right;

        node(int d){
            data=d;
            left= NULL;
            right=NULL;
            hd=INT_MAX;
        }
};

void bottomview(node*root){

    if(root==NULL){
        return;
    }
    int hd=0;
    map<int,int>m;

    queue<node*>q;

    root->hd=hd;
    q.push(root);

    while (!q.empty()){
        node* temp= q.front();
        q.pop();

        hd= temp->hd;
        m[hd]=temp->data;

        if(temp->left!=NULL){
            temp->left->hd=hd-1;
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            temp->right->hd=hd+1;
            q.push(temp->right);
        }
    }
    for(auto i=m.begin(); i!=m.end();++i){
        cout<<i->second<<" ";
    }
}

int main(){
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(5);
    root->left->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(25);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomview(root);
    return 0;
}
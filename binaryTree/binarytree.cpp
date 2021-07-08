#include<iostream>
#include<cmath>
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
    int d;    
    cin>>d;

    if(d==-1){
        return NULL;
    }  

    node* root = new node(d);
    root->left= buildTree();
    root->right= buildTree();
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

void printIn(node*root){
    if(root==NULL){
        return;
    }

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printpost(node*root){
    if(root==NULL){
        return;
    }

    printpost(root->left);
    printpost(root->right);
    cout<<root->data<<" ";
}

int height(node*root){
    if(root==NULL){
        return 0;
    }

    int ls= height(root->left);
    int rs= height(root->right);
    return max(ls,rs)+1;
}

void printkthlevel(node*root, int k){
    if(root==NULL){
        return;
    }

    if(k==1){
        cout<<root->data<<" ";
        // return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
}

void printAllLevels(node*root){
    int h= height(root);

    for(int i=1; i<=h ; i++){
        printkthlevel(root,i);
        cout<<endl;
    }
}

int count(node*root){

    if(root==NULL){
        return 0;
    }
    return 1+ count(root->left)+count(root->right);
}

int diameter(node*root){
    if(root==NULL){
        return 0;
    }

    int h1= height(root->left);
    int h2= height(root->right);
    int opt1 = h1+h2;
    int opt2= diameter(root->left);
    int opt3= diameter(root->right);

    return max(opt1,max(opt2,opt3));
}

class Pair{
    public:
    int height;
    int diameter;
};

Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }

    Pair left= fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height= max(left.height,right.height)+1;
    p.diameter= max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
}

//sum of children + node
int sum(node*root){

    if(root==NULL){
        return 0;
    }
    
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int l= sum(root->left);
    int r= sum(root->right);

    int temp = root->data;
    root-> data= l+r;
    return temp + root->data;
}

// tree is balanced or not
class hbPair{
    public:
        int height;
        bool balance;
};

hbPair isHeightBalanced(node* root){
    hbPair p;
    if(root==NULL){
        p.height=0;
        p.balance=true;
        return p;
    }
    hbPair left= isHeightBalanced(root->left);
    hbPair right= isHeightBalanced(root->right);

    p.height= max(left.height,right.height)+1;

    if(abs(left.height-right.height)<=1 && left.balance && right.balance){
        p.balance=true;
    }
    else
    p.balance=false;
    return p;
}


//building tree from array
node* buildTreeFromArray(int *a, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;

    node*root = new node(a[mid]);
    root->left= buildTreeFromArray(a,s,mid-1);
    root->right= buildTreeFromArray(a,mid+1,e);
    return root;

}

node* createTreeFromTrav(int *in,int *pre, int s,int e){
    static int i=0;
    if(s>e){
        return NULL;
    }

    node*root= new node(pre[i]);

    int index=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }

    i++;
    root->left= createTreeFromTrav(in,pre,s,index-1);
    root->right= createTreeFromTrav(in,pre,index+1,e);
    return root;
}

void rightView(node* root,int l, int &maxl){

    if(root==NULL){
        return;
    }
    if(maxl<l){
        cout<<root->data<<" ";
        maxl=l;
    }
    rightView(root->right,l+1,maxl);
    rightView(root->left,l+1,maxl);

}

//print all nodes at distance k
int printAtDistanceK(node*root, node*target, int k){

    if(root==NULL)
        return -1;
    
    if(root==target){
        printkthlevel(target,k);
        return 0;
    }

    int DL= printAtDistanceK(root->left,target,k);

    if(DL!=-1){
        if(DL+1==k){
            cout<<root->data<<" ";
        }
        else{
            printkthlevel(root->right, k-2-DL);
        }
        return 1+DL;
    }

     int DR= printAtDistanceK(root->right,target,k);

    if(DR!=-1){
        if(DR+1==k){
            cout<<root->data<<" ";
        }
        else{
            printkthlevel(root->left, k-2- DR);
        }
        return 1+DR;
    }
    return -1;
}


//lowest common root
node* lca(node* root,int a,int b){

    if(root==NULL){
        return NULL;
    }

    if(root->data==a || root->data==b){
        return root;
    }

    node* leftans= lca(root->left,a,b);
    node* rightans= lca(root->right,a,b);

    if(leftans!=NULL && rightans!=NULL){
        return root;
    }                        

    if(leftans!=NULL){
        return leftans;
    }
    return rightans;
}


class pa{

    public:
    int branchSum;
    int maxSum;

    pa(){
        branchSum=0;
        maxSum=0;
    }
};

//max sum path in tree
pa maxSumPath(node*root){
    pa p;

    if(root==NULL){
        return p;
    }

    pa leftp= maxSumPath(root->left);
    pa rightp= maxSumPath(root->right);

    int opt= root->data;
    int opt2= leftp.branchSum + root->data;
    int opt3= rightp.branchSum+ root->data;
    int opt4= rightp.branchSum + leftp.branchSum + root->data;

    int current_ans= max(opt,max(opt2,max(opt3,opt4)));

    p.branchSum= max(leftp.branchSum,max(rightp.branchSum,0))+ root->data;
    p.maxSum= max(leftp.maxSum,max(rightp.maxSum,current_ans));
    return p;
}


//search node
int search(node* root, int key, int level){
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return level;
    }
    int left= search(root->left,key,level+1);
    if(left!=-1){
        return left;
    }
    return search(root->right,key,level+1);
}


//min distance b/w 2 nodes
int findDistance(node*root, int a, int b){
    node* lca_node= lca(root,a,b);
    int l1= search(lca_node,a,0);
    int l2= search(lca_node,b,0);
    return l1+l2;
}

int main(){

    node* root= buildTree();
    // print(root);
    // cout<<endl;
    // printIn(root);
    // cout<<endl;
    // printpost(root);
    // cout<<endl;
    // cout<<height(root);
    // cout<<endl;
    // printAllLevels(root);
    // cout<<endl;
    // cout<<count(root);
    // cout<<endl;
    // cout<<diameter(root);
    // Pair p= fastDiameter(root);
    // cout<<p.height<<endl;
    // cout<<p.diameter<<endl;
    // sum(root);
    // printAllLevels(root);
    // cout<<endl;

    // if(isHeightBalanced(root).balance){
    //     cout<<"Balanced Tree";
    // }
    // else{
    //     cout<<"Not balanced";
    // }
    // return 0;

    // int a[]={1,2,3,4,5,6,7};
    // int n=7;

    // node*root= buildTreeFromArray(a,0,n-1);
    // printAllLevels(root);

    // int in[]={3,2,8,4,1,6,7,5};
    // int pre[]={1,2,3,4,8,5,6,7};
    // int n= sizeof(in)/sizeof(int);

    // node* root= createTreeFromTrav(in,pre,0,n-1);
    // printAllLevels(root);

    // int maxlevel=-1;
    // rightView(root,0,maxlevel);

    // node* target= root->left->left;
    // printAtDistanceK(root,target,2);

    // int a=2,b=9;
    // cout<<"lcd of 4 and 7 is "<<lca(root,4,7)->data<<endl;
    // cout<<"lca of 6 and 9 is "<<lca(root,6,9)->data<<endl;

    // cout<<"max sum path "<<maxSumPath(root).maxSum<<endl;
    
    int a,b;
    cin>>a>>b;
    int ans = findDistance(root,a,b);
    cout<<"min distance is b/w "<<a<<" & "<<b<<": "<<ans<<endl;
    return 0;
}
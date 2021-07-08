#include<iostream>
using namespace std;

class node{
    public:

    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};

int length(node*head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}


void insertAtHead(node*&head,int d){

    if(head==NULL){
        head= new node(d);
        return;
    }
    node *n = new node(d);
    n->next=head;
    head=n;
}

void insertAtTail(node *&head, int data){
    if(head==NULL){
        head= new node(data);
        return;
    }
    node*tail= head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next= new node(data);
    return;
}

void insertATMiddle(node*&head, int data, int p){
    if(head==NULL || p==0){
        insertAtHead(head,data);
    }
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        int j=1;
        node*temp=head;
        while(j<=p-1){
            temp=temp->next;
            j++;
        }
        node*n = new node(data);
        n->next= temp->next;
        temp->next=n;
    }
}

void deleteHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp=head->next;
    delete head;
    head= temp;  
}

bool search(node*head, int key){

    node*temp=head;
    while(temp!=NULL){
        if(head->data==key){
            return true;
        }
        head=head->next;
    }
    return false;
}

bool serchRecursive(node*head, int key){
    if(head==NULL){  
        return false;
    }
    if(head->data==key){
        return true;
    }
    else{
        return serchRecursive(head->next,key);
    }
}

void reverse(node*&head){
    node* c=head;
    node* p= NULL;
    node*n;

    while (c!=NULL){
        n= c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
    
}

node* recReverse(node*head){
    if(head->next==NULL || head==NULL){
        return head;
    }

    node* shead= recReverse(head->next);

    // node* temp= shead;
    // while (temp->next!=NULL){
    //     temp=temp->next;
    // }
    head->next->next= head;
    head->next=NULL;
    // temp->next=head;
    return shead;
    
}

//middle value of linkedlist
node* midpoint(node*head){
    if(head== NULL || head->next==NULL){
        return head;
    }
    node* slow = head;
    node* fast = head->next;

    while (fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

// kth element from last
node * kthfromEnd(node*head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* slow= head;
    node* fast= head;

    int t= k;
    while (t>0){
        fast= fast->next;
        t--;
    }

    while (fast!= NULL){
        fast= fast->next;
        slow= slow->next;
    }
    return slow;
   
}


//merge 2 linkeedlist
// 7 5 3 1 -1
// 9 6 4 2 -1
// 1 ->3 ->5 ->7 ->
// 2 ->4 ->6 ->9 ->
// 1 ->2 ->3 ->4 ->5 ->6 ->7 ->9 ->

node* merge(node* a, node* b){

    if(a==NULL){
        return b;
    }
    if(b== NULL){
        return a;
    }

    node*c;
    if(a->data < b->data){
        c=a;
        c->next= merge(a->next,b);
    }
    
    else{
        c=b;
        c->next= merge(a, b->next);
    }

    return c;
}

node* take_input(){
    int d;
    cin>>d;

    node *head=NULL;

    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

void print(node*head){
    while (head!=NULL){
        cout<<head->data<<" ->";
        head=head->next;
    }
    cout<<endl;
}

ostream& operator<<(ostream &os, node *head){
    print(head);
    return os;
}

istream& operator>>(istream &is, node *&head){
    head= take_input();
    return is;
}

int main(){

    node*head1;
    node*head2;
    cin>>head1>>head2;
    cout<<head1<<head2;
    node* newHead= merge(head1, head2);
    cout<<newHead<<endl;
    //node *head= take_input();
    // node *head;
    // cin>>head;
    // cout<<head;
    // int k;
    // cin>>k;
    // node* kth= kthfromEnd(head,k);
    // cout<<kth->data<<" ";
    // node*head= NULL;
    // insertAtHead(head,3);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,0);
    // insertATMiddle(head,4,3);
    // insertAtTail(head,7);
    // deleteHead(head);
    // print(head);

    // if(serchRecursive(head,1)){
    //     cout<<"Found";
    // }
    // else{
    //     cout<<"Not Found";
    // }

    return 0;
}
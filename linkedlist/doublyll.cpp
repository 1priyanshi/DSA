#include<iostream>
using namespace std;


class node{
    public:
        int data;
        node *next;
        node *prev;

        node(int d){
            data = d;
            next=NULL;
            prev=NULL;
        }
};

int length(node*head){
    int c=0;
    while (head->next!=NULL){
        c++;
        head=head->next;
    }
    return c;
}

void insertAtHead(node*&head, int d){
    if(head==NULL){
        head= new node(d);
        return;
    }
    node *n= new node(d);
    n->next=head;
    head->prev= n;
    head=n;
    head->prev= NULL;
}

void insertAtTail(node*&head, int d){

    if(head==NULL){
        head= new node(d);
        return;
    }
    
    node*tail= head;

    while (tail->next!=NULL){
        tail=tail->next;
    }
    
    node* n= new node(d);
    tail->next= n;
    n->prev= tail;
    n->next=NULL;
    return;
}

void insertAtMiddle(node*&head, int d, int p){

    if(head == NULL || p==0){
        insertAtHead(head,d);
    }
    else if(p>length(head)){
        insertAtTail(head,d);
    }
    else{
        int j=1;
        node*temp= head;
        while(j<p){
            temp=temp->next;
            j++;
        }
        node*n= new node(d);
        n->next= temp->next;
        n->prev= temp;
        temp->next=n;
        temp=temp->next;
        temp->prev=n;
    }
}

void deleteHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp= head->next;
    delete head;
    head=temp;
    head->prev=NULL;
}

bool serch(node*head, int k){
    node*temp= head;
    while (temp!=NULL){
        if(temp->data==k){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

// node* reverse(node* head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//     node* shead= recReverse(head->next);

//     node*n= shead->prev;
//     shead->next= shead->prev;
//     shead->prev=NULL;
    
// }

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

ostream& operator<<(ostream &os, node*head){
    print(head);
    return os;
}

istream& operator>>(istream &is, node*&head){
    head= take_input();
    return is;
}

int main(){
    node*head;
    cin>>head;
    cout<<head;
    int k;
    cin>>k;
    if(serch(head, k))
    cout<<"Found";
    else{
        cout<<"NOT Found";
    }
    return 0;
}
#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            data= d;
            next=NULL;
        }
};

int length(Node*head){
    int c=0;
    while(head!=NULL){
        head=head->next;
        c++;
    }
    return c;
}

int _yshape(Node*head1, Node*head2, int d){

    Node*curr1 = head1;
    Node*curr2= head2;

    for(int i=0;i<d;i++){
        if(curr1==NULL){
            return -1;
        }
        curr1=curr1->next;
    }

    while(curr1!=NULL && curr2!=NULL){
        if(curr1->data==curr2->data){
            return curr1->data;
        }
        curr1= curr1->next;
        curr2= curr2->next;
    }
    return -1;
}

int yshape(Node*head1, Node*head2){

    int h1= length(head1);
    int h2= length(head2);

    if(h1>h2){
        int d= h1-h2;
        return _yshape(head1,head2,d);
    }
    else{
        int d= h2-h1;
        return _yshape(head2,head1,d);
    }
}

void insertAtHead(Node*&head,int d){

    if(head==NULL){
        head= new Node(d);
        return;
    }
    Node *n = new Node(d);
    n->next=head;
    head =n;
}

Node* take_input(){
    int d;
    cin>>d;

    Node *head=NULL;

    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

void print(Node*head){
    while (head!=NULL){
        cout<<head->data<<" ->";
        head=head->next;
    }
    cout<<endl;
}

ostream& operator<<(ostream &os, Node *head){
    print(head);
    return os;
}

istream& operator>>(istream &is, Node *&head){
    head= take_input();
    return is;
}

int main(){
    Node*head1;
    Node*head2;
    cin>>head1>>head2;
    cout<<head1<<head2;
    int ans= yshape(head1,head2);
    cout<<ans<<" ";
    
    return 0;
}
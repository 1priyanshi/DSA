//to find prefix of all words present in array
#include<iostream>
#include<unordered_map>
using namespace std;

class node{
    public:
        char data;
        unordered_map<char,node*>children;
        bool terminal;
        int freq;

        node(char d){
            data=d;
            freq=0;
            terminal=false;
        }
};

class trie{

    node* root;
    int cnt;
    public:

    trie(){
        root=new node('\0');
        cnt=0;
    }

    void insert(char *w){

        node*temp= root;
        for(int i=0;w[i]!='\0';i++){
            char ch= w[i];
            if(temp->children.count(ch)){
                temp= temp->children[ch];
                temp->freq+=1;

            }
            else{
                node* n= new node(ch);  //temp node
                temp->children[ch]=n;
                temp=n;
                temp->freq+=1;
            }
        }
        temp->terminal=true;
    }


    void prefix(char *w){
        node*temp=root;
        int j=0;
        for(int i=0;w[i]!='\0';i++){
            char ch=w[i];
                temp=temp->children[ch];
                if(temp->freq>1){
                    j++;
                }
        }

        for(int k=0;k<=j;k++){
            cout<<w[k];
        }
    }
};

int main(){
    trie t;
    char words[][10]= {"a","hello","not","news","apple"};

    for(int i=0;i<5;i++){
        t.insert(words[i]);
    }

    for(int i=0;i<5;i++){
        t.prefix(words[i]);
        cout<<endl;
    }
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class Node{

    public:
        string key;
        T value;
        Node<T>*next;

        Node(string key, T val){
            this->key=key;
            value= val;
            next=NULL;
        }
        ~Node(){                 //destructor to delete individual nodes of linked list
            if(next!=NULL){
                delete next;
            }
        }
};

template<typename T>
class Hashtable{

    Node<T>**table;          
    int current_size;
    int table_size;

     int hashFn(string key){                //to calculate index of string
            int idx=0; 
            int p=1;
            for(int j=0;j<key.length();j++){
                idx= idx + (key[j]*p) % table_size;          // %table_size to ensure idx fit into table size
                idx= idx%table_size;
                p=(p*27)%table_size;
            }
            return idx;   
        }


    void rehash(){            
        Node<T>** oldTable = table;
        int old_table= table_size;
        table_size= 2*table_size;
        table = new Node<T>*[table_size];          //create new table

        for(int i=0;i<table_size;i++){              //initializing New table values to null
            table[i]=NULL;
        }
        current_size=0;


        for(int i=0;i<old_table;i++){
            Node<T>*temp= oldTable[i];             
            while (temp!=NULL){
                insert(temp->key,temp->value);     
                temp=temp->next;
            }

            if(oldTable[i]!=NULL){                //deleting old table linked list
                delete oldTable[i];
            }
            
        }

        delete [] oldTable;                       //deleting old hashtable
    }

    public:
        Hashtable(int ts=7){                      
            table_size= ts;
            table= new Node<T>*[table_size];
            current_size=0;
            for(int i=0;i<table_size;i++){
                table[i]=NULL;
            }
        }

        void insert(string key, T value){
            int idx= hashFn(key);                    //index value in hash table

            Node<T>*n = new Node<T>(key,value);      //creating node
            n->next=table[idx];                      //n->next=NULL i.e table[idx] initial value
            table[idx]=n;                            //table[idx] is n i.e new node
            current_size++; 

            float load_factor = current_size/(1.0*table_size);      

            if(load_factor>0.7){
                rehash();
            }
        }

        void print(){
             
             for(int i=0;i<table_size;i++){
                 cout<<"Bucket "<<i<<"->";
                 Node<T>*temp= table[i];
                 while (temp!=NULL){
                     cout<<temp->key<<"->";             
                     temp= temp->next;
                 }
                 cout<<endl;
             }
        }

        T* search(string key){

            int idx = hashFn(key);           //index value of key we want to search
            Node<T>*temp= table[idx];        //temp variable to store value at idx
            while (temp!=NULL){              //checking if key is present in linked list
                if(temp->key==key){
                    return &temp->value;
                }
                temp=temp->next;
            }
            return NULL;                      // if not present return NULL
        }

        T& operator[](string key){
            T* f= search(key);
            if(f==NULL){
                //insert key,value in the hashmap
                T garbage;
                insert(key,garbage);
                f= search(key);
            }
            return *f;
        }
};

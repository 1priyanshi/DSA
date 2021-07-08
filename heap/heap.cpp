#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>v){
    for(auto x= v.begin()+1; x< v.end();x++){
        cout<<*x<<" ";
    }
    cout<<endl;
}

class Heap{
    vector<int>v;
    bool minHeap;

    bool compare(int a, int b){
        return a>b;
    }

    void heapify(int idx){
        int left= 2*idx;
        int right= left+1; 

        int min_idx=idx;
        int last= v.size()-1;

        if(left<=last && compare(v[left],v[idx])){
            min_idx=left;
        }
        if(right<=last && compare(v[right],v[min_idx])){
            min_idx=right;
        }

        if(min_idx!=idx){
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }

    public:

    Heap(int default_size=10, bool type=true){
        v.reserve(default_size);
        v.push_back(-1);
        minHeap=type; 
    }

    void push(int d){
        v.push_back(d);
        int idx= v.size()-1;
        int parent= idx/2;

        while (idx>1 && compare(v[idx],v[parent])){
            swap(v[idx],v[parent]);
            idx= parent;
            parent=parent/2;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        int last= v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty(){
        return v.size()==1;
    }

    //for heap sort
       void heapify2(vector<int>&v, int idx, int size){
        int left= 2*idx;
        int right= left+1;

        int min_idx=idx;
        int last= size-1;

        if(left<=last && compare(v[left],v[idx])){
            min_idx=left;
        }
        if(right<=last && compare(v[right],v[min_idx])){
            min_idx=right;
        }

        if(min_idx!=idx){
            swap(v[idx],v[min_idx]);
            heapify2(v, min_idx, size);
        }
    }
    
};

//maxheap from vector
void buildHeap(vector<int>&v){
    for(int i=2;i<v.size();i++){
        int idx= i;
        int parent= i/2;
        while (idx>1 && v[idx]>v[parent]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    } 
}


  void heapSort(vector<int>&arr){

      Heap h;
        buildHeap(arr);
        int n= arr.size();

        print(arr);

        while (n>1){
            swap(arr[1],arr[n-1]);
            n--;
            h.heapify2(arr,1,n);
            //print(arr);
        } 
    }
int main(){
    // Heap h;
    // int n;
    // cin>>n;

    // for(int i=0;i<n;i++){
    //     int no;
    //     cin>>no;
    //     h.push(no); 
    // }

    // while (!h.empty()){
    //     cout<<h.top()<<" ";
    //     h.pop();
    // }
    
    // vector<int> v{-1,10,20,5,6,1,8,9,4};
    // print(v);
    // buildHeap(v);
    // print(v);


    Heap h(false);
    vector<int>v;
    v.push_back(-1);
    int n;
    cin>>n;

    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }
    heapSort(v);

    print(v);
    return 0;
}
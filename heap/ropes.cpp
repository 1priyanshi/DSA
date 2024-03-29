#include<iostream>
#include<queue>
using namespace std;

int join(int ropes[],int n){

    //min heap
    priority_queue<int,vector<int>,greater<int>>pq(ropes,ropes+n);

    int cost=0;

    while (pq.size()>1){

        int a= pq.top();
        pq.pop();

        int b= pq.top();
        pq.pop();

        int new_rope=(a+b);
        cost+=new_rope;
        pq.push(new_rope);
    }
    return cost;
}

int main(){

    int ropes[]={4,3,2,6};
    int n=4;

    cout<<join(ropes,n)<<endl;
    return 0;
}
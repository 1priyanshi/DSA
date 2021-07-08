#include<iostream>
#include<vector>
using namespace std;


void primefactor(int n){

    vector<pair<int,int>> factor;
    int cnt;

    for(int i=2; i*i<n; i++){
        if(n%i==0){
            cnt=0;
            while (n%i==0){
                cnt++;
                n=n/i;
            }
            factor.push_back(make_pair(i,cnt));
        }
    }
    if(n!=1){
        factor.push_back(make_pair(n,1));
    }
    for(auto p:factor){
        cout<<p.first<<"^"<<p.second<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    primefactor(n);
    return 0;
}
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    int n,m,a[10000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);

    int min_diff = INT_MAX;
    for(int i=0;i+m-1<n;i++){
        int diff = a[i+m-1]-a[i];
        if(diff< min_diff){
            min_diff= diff;
        }
    }
    cout<<min_diff;
    return 0;
}


#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v(1,1);
    int k=1;
    int carry = 0;

    for(int i=2;i<=n;i++){
        for(int j=k-1;j>=0;j--){
            v[j] = v[j]*i+carry;
            carry = v[j]/10;
            v[j] = v[j]%10;
        }

        
        while(carry>0){
            k++;
            v.insert(v.begin(), carry%10);
            carry = carry/10;
        }
    }


    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
    return 0;
}
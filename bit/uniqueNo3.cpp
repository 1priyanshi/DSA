#include<iostream>
using namespace std;

int main(){
    int n,cnt[64]={0};;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    
    for(int i=0;i<n;i++){
        int j=0;
        while (a[i]>0){
            int last_bit= (a[i]&1);                      // making array of sum of bits
            cnt[j]+= last_bit;
            j++;
            a[i]= a[i]>>1;
        }
    }

    int p=1,ans=0;

    for(int i=0;i<64;i++){
        cnt[i]%=3;                                        // forming unique number
        ans+= cnt[i]*p;
        p=p<<1;
    }

    cout<<ans;
    return 0;
}
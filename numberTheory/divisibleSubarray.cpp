// You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
// A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.
#include<iostream>
#include<cstring>
using namespace std;

#define ll long

ll a[1000005], pre[1000005];

int main(){
    int t;
    cin>>t;
    while (t>0){
        int n;
        cin>>n;
        memset(pre,0,sizeof(pre));
        pre[0]=1;

        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+= a[i];
            sum%=n;
            sum=(sum+n)%n;
            pre[sum]++;
        }

        ll ans=0;
        for(int i=0;i<n;i++){
            int m= pre[i];
            ans+= m*(m-1)/2;
        }
        cout<<ans<<endl;
        t--;
    }
    
    return 0;
}
// abc

// a
// b
// ab
// c
// ac
// bc
// abc

#include<iostream>
#include<cstring>
using namespace std;

void substring(int n, char a[]){
    int j=0;
    while (n>0){
        int lb = (n&1);
        if(lb==1){
            cout<<a[j];
        }
        j++;
        n= n>>1;
    }
    cout<<endl;
}

int main(){
    char a[100];
    cin>>a;
    int n= strlen(a);

    for(int i=0;i<(1<<n);i++){
     substring(i,a);
    }
    
    return 0;
}
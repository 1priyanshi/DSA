#include<iostream>
#include<cstring>
using namespace std;

int main(){

    int n;
    cin>>n;
    char a[1000],largest[1000];
    cin.get();      // for removing one extra empty string 

    int len=0,max=0;
    for(int i=0;i<n;i++){
        cin.getline(a,1000);
        len= strlen(a);
        if(len>=max){
            max= len;
            strcpy(largest,a);
        }
    }

    cout<<max<<" ";
    cout<<largest;
    return 0;
}
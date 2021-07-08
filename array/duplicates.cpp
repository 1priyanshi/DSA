#include<iostream>
#include<cstring>
using namespace std;

int main(){

    char a[1000];
    cin.getline(a, 1000);

    int n= strlen(a);

    int i= 0, j=i+1;

    while(j<n){
        if(a[i]==a[j]){
        j++;
        }
        else{
            a[i+1]= a[j];
            i++;
            j++;
        }
    }

    for(int k=0;k<=i;k++){
        cout<<a[k];
    }
    return 0;
}
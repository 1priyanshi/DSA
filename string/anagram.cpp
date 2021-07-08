//anagrams
#include<iostream>
#include<string>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;

    int arr[26]={0},flag=0;

    if(a.length()==b.length()){
            for(int i=0;i<a.length();i++){
            int l= a[i] - 97;
            arr[l]= arr[l]+1;
            }
            for(int i=0;i < b.length();i++){
                int l= b[i]-97;
                arr[l]= arr[l]-1;
            }

            for(int i=0;i<26;i++){
            if(arr[i]==0){
                flag =0;
            }
            else{
                flag =1;
                break;
            }
        }
    }
    else{
        flag=1;
    }


    if(flag==1){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}
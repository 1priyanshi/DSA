#include<iostream>
using namespace std;

int main(){

    string s, x;
    cin>>s>>x;
                                                              
    int i=0,k=0,flag=0;
    while (i<s.length()){

        if(s[i]==x[k]){
            int z=i+1,y=k+1;
            if(s[z]==s[y]){
                 z++,y++;
                 if(y==x.length()-2){
                     cout<<i;
                     flag=1;
                     break;
                 }
            }
            else{
                i=i+z-1;
                k=0;
            }

            // int z=i+1;
            // k++;
            // for(int j=1;j<x.length();j++){
            //     if(s[z]==x[k]){
            //         z++;k++;
            //         if(j==x.length()-1){
            //             cout<<i;
            //             flag=1;
            //         }
            //     }
            //     else{
            //         break;
            //     }
            // }
            // i= i+ x.length()-1;
            // k=0;
        }
        else{
            i++;
        }
    }
    if(flag==0){
        cout<<"-1";
    }
    
    return 0;
}
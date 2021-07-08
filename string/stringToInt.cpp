// Your task  is to implement the function atoi. 
// The function takes a string(str) as argument and converts it to an integer and returns it.
// Input:
// str = 123
// Output: 123


#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int p=0,flag=0;

    if(s[0]!='-'){
        flag=1;
        for(int i=0;i<s.length();i++){
            if(s[i]>=48 && s[i]<58){
                p=p + s[i]-48;
                p=p*10;
    
            }
            else{
                cout<<"-1";
            }
        }
    }

    else{
        flag=0;
        for(int i=1;i<s.length();i++){
             if(s[i]>=48 && s[i]<58){
                p=p + s[i]-48;
                p=p*10;
    
            }
            else{
                cout<<"-1";
            }
        }
    }

    if(flag==1){
        cout<<p/10<<endl;
    }
    else{
        cout<<"-"<<p/10<<endl;
    }
   
    return 0;
}
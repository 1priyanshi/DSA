#include<iostream>
#include<string>
using namespace std;

void permute(string s, string ans){

    if(s.length()==0){
        cout<<ans<<" ";
        return;
    }
    for(int i=0; i< s.length(); i++){
        char ch = s[i];
        string left= s.substr(0,i);
        string right = s.substr(i+1);
        string rest= left + right;
        permute(rest, ans+ch);
    }
}

int main(){
    string s;
    string ans="";
    cin>>s;
    permute(s,ans);
    return 0;
}
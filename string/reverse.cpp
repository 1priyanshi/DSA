#include<iostream>
#include<string>
#include<vector>
using namespace std;

// int main(){
//     char s[100]= " Today is a rainy day ";
//     char* ptr= strtok(s," ");
//     // cout<<ptr<<" ";
//     while (ptr!=NULL){
//         ptr= strtok(NULL," ");
//     }
//     return 0;
// }

int main(){
    string s ="today.is.a.rainy.day";
    vector<string> tmp;
    string str= "";

    for(int i=0; i<s.length(); i++){

        if(s[i]=='.'){
            tmp.push_back(str);
            str="";
        }

        else{
            str+=s[i];
        }
    }

        tmp.push_back(str);

     for(int i= tmp.size()-1; i>0; i--){
            cout<<tmp[i]<<" ";
        }
        cout<<tmp[0]<<endl;
    return 0;
}
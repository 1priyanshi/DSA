// #include<iostream>
// using namespace std;

// bool isPalindrome(string s){
//     int l=0;
//     int h=s.length()-1;

//     while (l<=h){
//         if(s[l++]!=s[h--]){
//             return false;
//         }
//     }
//     return true;                                                                 //not done
// }

// int main(){
//     string str;
//     cin>>str;
//     if(isPalindrome(str)){
//         cout<<'0';
//     }
//     else{
//         cout<<str.length()-1;
//     }
//     return 0;
// }

#include<iostream>
#include<string>
#include<cstring>
using namespace std;


void largestPalindrome(string str){
    int n= str.length();
    bool table[n][n];
    memset(table,0,sizeof(table));

    int maxlength= 1;
    for(int i=0;i<n;++i)
        table[i][i]=true;

        int start = 0;
        for(int i=0;i<n-1;i++){
            if(str[i]==str[i+1]){
                 table[i][i+1]= true;
                 start=i;
                 maxlength=2;
            }
        }

        for(int k=3;k<=n;++k){
            for(int i=0;i<=n-k+1;++i){
                int j=i+k-1;
                if(table[i+1][j-1] && str[i]==str[j]){
                    table[i][j]=true;

                    if(k> maxlength){
                        start= i;
                        maxlength=k;
                    }
                }
            }
        }
       cout<<n- maxlength+ start;
}

int main(){
    string s;
    cin>>s;
    largestPalindrome(s);
    return 0;
}
// Given a string without spaces, the task is to remove duplicates from it.
// Note: The original order of characters must be kept the same. 

// Example 1:
// Input: S = "zvvo"
// Output: "zvo"
// Explanation: Only keep the first
// occurrence

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length(), arr[26]={0};
    
    for(int i=0;i<n;i++){
       int l=s[i]-97;
       arr[l]=arr[l]+1;
    }

    for(int i=0;i<n;i++){
        if(arr[s[i]-97] > 0){
            cout<<s[i];
            arr[s[i]-97]=0;
        }
    }
    return 0;
}


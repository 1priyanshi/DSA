// Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

// Example 1:
// Input:
// a = amazon
// b = azonam
// Output: 1
// Explanation: amazon can be rotated anti
// clockwise by two places, which will make
// it as azonam.

// Example 2:
// Input:
// a = geeksforgeeks
// b = geeksgeeksfor
// Output: 0
// Explanation: If we rotate geeksforgeeks by
// two place in any direction , we won't get
// geeksgeeksfor.

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1,sre2;
    cin>>str1>>str2;
    int flag=0;
     if(str1.length()==str2.length()){
        if(str1.length()==1){
            if(str1[0]==str2[0])
            return true;
        else{
            return false;
         }
        }
        
         if(str1[0]==str2[str2.length()-2] || str2[0]==str1[str1.length()-2]){
                flag=0;
        }
        else{
            flag=1;
            return false;
        }

        if(str1[1]==str2[str2.length()-1] || str2[1]==str1[str1.length()-1]){
            flag=0;
        }
        else{
            flag=1;
            return false;
        }


        for(int i=2;i<str1.length();i++){
        if(str1[i]==str2[i-2] || str2[i]==str1[i-2]){
                flag=0;
            }
            else{
                flag=1;
                break;
            }
        }
    }
    else{
        flag=1;
    }
       

    if(flag==0){
        return true;
    }
    else{
        return false;
    }
    }

    return 0;
}
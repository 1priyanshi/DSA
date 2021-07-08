#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int compare(string x, string y){

    string xy= x.append(y);
    string yx= y.append(x);

    return xy.compare(yx) > 0 ? 1: 0; 
}

int main(){
    vector<string> arr;
    int n=5;
    arr.push_back("3");
    arr.push_back("30");
    arr.push_back("34");
    arr.push_back("5");
    arr.push_back("9");
    sort(arr.begin(), arr.end(),compare);
    for (int i = 0; i < 5; i++)
        cout << arr[i];
    return 0;
}
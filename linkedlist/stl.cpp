#include<iostream>
#include<list>
using namespace std;

int main(){

    list<int>l;
    list<int> l1{1,2,3,4,5,10};
    list<string> l2{"apple", "guava", "mango", "banana"};

    l2.push_back("pineapple");

    l2.sort();

    l2.reverse();

    l2.pop_front();

    l2.push_front("kiwi");

    string f;
    cin>>f;
    l2.remove(f);  //remove all occurance of element

    for(string s:l2){
        cout<<s<<"-->";
    }
    return 0;
}
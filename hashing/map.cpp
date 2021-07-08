#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){

    map<string,int> m;

    m.insert(make_pair("Mango",100));

    pair<string,int>p;
    p.first="Apple";
    p.second= 120;

    m.insert(p);

    m["Banana"]=20;

    string fruit;
    cin>>fruit;

    m[fruit]+=22;

    auto it = m.find(fruit);
    //return ans of type iterator
    if(it!=m.end()){
        cout<<"price of "<<fruit<<" is "<< m[fruit]<<endl;
    }
    else{
        cout<<" fruit is not present "<<endl;
    }


    //return of type integer
    if(m.count(fruit)){
        cout<<"Price is "<<m[fruit]<<endl;
    }
    else{
        cout<<"Couldn't find "<<endl;
    }

    m["lichi"]=60;
    m["pineapple"]=80;

    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }

    for(auto p:m){
        cout<<p.first<<" : "<<p.second<<endl;
    }    
    
    return 0;
}
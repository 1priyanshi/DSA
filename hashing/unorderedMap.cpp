#include<iostream>
#include<unordered_map>
using namespace std;

//the only difference from map is that, it is not in order

 
int main(){

    unordered_map<string,int> um;
    um.insert(make_pair("Mango",100));

    pair<string,int>p;
    p.first="Apple";
    p.second= 120;

    um.insert(p);

    um["Banana"]=20;

    string fruit;
    cin>>fruit;

    um[fruit]+=22;

    auto it = um.find(fruit);
    //return ans of type iterator
    if(it!=um.end()){
        cout<<"price of "<<fruit<<" is "<< um[fruit]<<endl;
    }
    else{
        cout<<" fruit is not present "<<endl;
    }


    //return of type integer
    if(um.count(fruit)){
        cout<<"Price is "<<um[fruit]<<endl;
    }
    else{
        cout<<"Couldn't find "<<endl;
    }

    um["lichi"]=60;
    um["pineapple"]=80;

    for(auto it=um.begin();it!=um.end();it++){
        cout<<it->first<<" and "<<it->second<<endl;
    }

    for(auto p:um){
        cout<<p.first<<" : "<<p.second<<endl;
    }    
    return 0;
}
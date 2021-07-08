#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string extractString(string str, int key){
    char *s = strtok((char*)str.c_str()," ");
    while (key>1){
        s= strtok(NULL," ");
        key--;
    }
    return (string)s;
    
}

int convertToInt(string s){
    int ans=0;
    int p=1;
    for(int i=s.length()-1;i>=0;i--){
        ans+=((s[i]-'0')*p);
        p=p*10;
    }
    return ans;
}

bool numericCompare(pair<string,string> s1, pair<string,string>s2){
    string k1,k2;
    k1= s1.second;
    k2= s2.second;

    return convertToInt(k1)<convertToInt(k2);
}

bool lexicoCompare(pair<string,string> s1, pair<string,string>s2){
    string k1,k2;
    k1= s1.second;
    k2= s2.second;

    return k1<k2;
}

int main(){
    int n;
    cin>>n;
    cin.get();

    string a[100];
    for(int i=0;i<n;i++){
        getline(cin,a[i]);
    }

    int key;
    cin>>key;
    string r,o;
    cin>>r>>o;

    pair<string,string> strPair[100];

    for(int i=0;i<n;i++){
        strPair[i].first=a[i];
        strPair[i].second= extractString(a[i],key);
    }

    if(o == "numeric"){
        sort(strPair, strPair+n, numericCompare);
    }
    else{
        sort(strPair, strPair+n, lexicoCompare);
    }

    if(r == "true"){
        for(int i=0;i<n/2;i++){
            swap(strPair[i],strPair[n-i-1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<strPair[i].first<<endl;
    }
    return 0;
}
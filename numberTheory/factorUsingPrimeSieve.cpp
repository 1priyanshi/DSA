#include<iostream>
#include<vector>
using namespace std;

vector<int> primeSieve(int *p, int n){
     for(int i=3;i<=1000;i=i+2){
        p[i]=1;
    }

    for(long long int i=3;i<=1000;i=i+2){
        if(p[i]==1){
            for(long long int j= i*i;j<1000; j= j+i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;

    vector<int> primes;
    primes.push_back(2);

    for(int i=3;i<=n;i=i+2){
        if(p[i]==1){
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> factorize(int m, vector<int> &primes){
    vector<int> factors;
    factors.clear();

    int i=0;
    int p= primes[0];

    while (p*p<=m){
        if(m%p==0){
            factors.push_back(p);
            while (m%p==0){
                m=m/p;
            }
        }
        i++;
        p= primes[i];
    }
    if(m!=1){
        factors.push_back(m);
    }
    return factors;
}

int main(){
    int n=10000;
    int p[n]={0};
    vector<int> primes = primeSieve(p,100);

    int t;
    cin>>t;

    while (t>0){
        int no;
        cin>>no;
        vector<int> factors = factorize(no,primes);
        for(auto f: factors){
            cout<<f<<" "<<endl;
        }
        t--;
    }
    
    return 0;
}
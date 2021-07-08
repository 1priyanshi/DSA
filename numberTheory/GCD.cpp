#include<iostream>
using namespace std;

int GCD(int a, int b){

    return b==0? a: GCD(b,a%b);
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int gcd = GCD(n1,n2);
    int lcm= (n1*n2)/gcd;
    cout<<gcd<<" "<<lcm;
    return 0;
}
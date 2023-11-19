
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int final;
int iterative(int n)
{
    if(n<0) return -1;
    if(n<=1) return n;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    for(int i=2; i<=n;i++)
    {
        v.push_back(v[i-1]+v[i-2]);
    }
    return v[v.size()-1];
}

int rsteps=0;
int recursive(int n)
{
    rsteps++;
    if(n<0) return -1;
    if(n<=1) return n;

    return recursive(n-1)+ recursive(n-2);
}
int main()
{
    int n;
    cin>>n;

    cout<<"Fibonacci series using iterative function "<<iterative(n)<<endl;
    cout<<"Total steps required in iterative fibonacci series is "<<n<<endl;
    cout<<"Fibonacci series using recursive functions "<<recursive(n)<<endl;
    cout<<"Total steps required in recursive fibonacci series is "<<rsteps<<endl;

}
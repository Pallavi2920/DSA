#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c=0;
    cin>>n;
    while(n!=0)
    {
        n = n/10;
        c++;
    }
    cout<<c<<endl;
}

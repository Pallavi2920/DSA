#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        std::vector<string> v;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            if(v[i][0]=='p' || v[i][0]=='b')
            cout<<v[i]<<" "<<i;
        }
    }
}

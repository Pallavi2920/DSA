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
        int w[n];
        int l[n];
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>l[i];
        }
        if(n==2)
        {
            if(w[0]>w[1])
            {
                cout<<"2"<<endl;
            }
            else
            {
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        std::vector<int> v;
        stack<int> s;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if( s.empty())
            {
                  v.push_back(0);
            }
            else if(s.size()>0 && s.top() > arr[i] )
            {
                    v.push_back(s.top());
            }
            else if(s.size()>0  && s.top()<=arr[i] )
            {
                while(s.size()>0 && s.top()<=arr[i])
                {
                    s.pop();
                }
                if(s.size() ==0)
                    v.push_back(0);
                else
                    v.push_back(s.top());
            }
            s.push(arr[i]);
          }
          reverse(v.begin(),v.end());
          for(int i=0;i<n;i++)
          {
              cout<<v[i]<<" ";
          }
          cout<<endl;

    }
    return 0;
}

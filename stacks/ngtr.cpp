/*Nearest Greater to right
for eg:
ip:]
4
1 3 2 4
7
1 3 0 0 1 2 4
op:
3 4 4 -1
3 4 1 1 2 4 -1
*/
#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;
std::vector<int> v;
std::vector<int> v1;
stack<int>st;
int main()
{

      int n;
      cin>>n;
      for(int i=0;i<n;i++)
      {
          int temp;
          cin>>temp;
          v.push_back(temp);
      }

      for(int i=n-1;i>=0;i--)
      {
          if(st.empty())
          {
              v1.push_back(-1);
              st.push(v[i]);
          }
          else if(st.top()>v[i] && st.size()>0)
          {
              v1.push_back(st.top());

          }
          else if(st.size()>0 && st.top()<=v[i])
          {
              while(st.size()>0 && st.top()<=v[i])
              {
                  st.pop();
              }
              if(st.size()>0)
              {
                v1.push_back(-1);
              }
              else
              {
                v1.push_back(st.top());
              }
            }
            st.push(v[i]);
          }

      reverse(v1.begin(),v1.end());
      for(int i=0;i<n;i++)
      {
        cout<<v1[i]<<" ";
      }
      cout<<endl;
}

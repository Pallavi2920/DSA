/*Remove all the duplicate elements from the string

for eg:
ip:bccbdb
op:db

*/

#include<bits/stdc++.h>
#include<stack>
#define SIZE 1000000
using namespace std;
stack<char>st;
void remove_duplicates(string s)
{
  for(int i=0;i<s.length();i++)
  {
    if(st.empty() || s[i]!=st.top())
    {
      st.push(s[i]);
    }
    else if(s[i]==st.top())
    {
      st.pop();
    }
  }
  string s1="";
  while(!st.empty())
  {
    s1=st.top()+s1;
    st.pop();
  }
  cout<<s1<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      string s="";
      cin>>s;
      remove_duplicates(s);
    }
}

/*Length of the longest valid substring
eg:
3
4
<<>>
2
><
4
<>>>
op:
4
0
*/
#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack<char>st;
stack<int>in;
int checkBalanced(string s)
{
  in.push(-1);
  int maxLen=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='<')
    {
      st.push(s[i]);
      in.push(i);
    }
    else
    {
      if(!st.empty() && st.top()=='<')
      {
        st.pop();
        in.pop();
        maxLen=max(maxLen,i-in.top());
      }
      else
      {
        in.push(i);
      }
    }
  }
  return maxLen;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<checkBalanced(s)<<endl;
  }
}

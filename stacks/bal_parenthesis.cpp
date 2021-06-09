#include<bits/stdc++.h>
#include<stack>
using namespace std;
bool arebalanced(char opening,char closing)
{
  if(opening=='(' && closing==')')
    return true;
  else if(opening=='{' && closing=='}')
    return true;
  else if(opening=='[' && closing==']')
    return true;
  else
    return false;
}
bool checkBalanced(string s)
{
  stack<char>st;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='('||s[i]=='{'||s[i]=='[')
    {
      st.push(s[i]);
    }
    else if(s[i]==')'||s[i]=='}'||s[i]==']')
    {
      if( st.empty() || !arebalanced(st.top(),s[i]))
        return false;
      else
        st.pop();
    }
  }
  return st.empty()? true: false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s="";
    cin>>s;
    if(checkBalanced(s))
    {
      cout<<"Valid"<<endl;
    }
    else
      cout<<"Not Valid"<<endl;
  }
  return 0;
}

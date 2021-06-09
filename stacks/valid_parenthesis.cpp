#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char>st;
bool areBal(char opening, char closing)
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
bool valid_parenthesis(string s)
{
  for(int i=0;i<s.size();i++)
  {
      if(s[i]=='('|| s[i]=='{' || s[i]=='[')
      {
          st.push(s[i]);
      }
      else if(s[i]==')' || s[i]=='}' || s[i]==']')
      {
          if(st.empty() || !areBal(st.top(),s[i]))
             return false;
          else
             st.pop();
      }
  }
  return st.empty()?true:false;
}
int main()
{
    string s;
    cin>>s;
    stack<char>st;
    if(valid_parenthesis(s))
      cout<<"True"<<endl;
    else
      cout<<"False"<<endl;
    return 0;
}

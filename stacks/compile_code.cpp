#include<bits/stdc++.h>
#include<stack>
using namespace std;
int balParenthesis(string s)
{
  int sum=0,maxi=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='<')
      sum += 1;
    else
      sum -= 1;
    if(sum<0)
      break;
    if(sum==0)
      maxi = i+1;
  }
  return maxi;
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
    cout<<balParenthesis(s)<<endl;
  }

}

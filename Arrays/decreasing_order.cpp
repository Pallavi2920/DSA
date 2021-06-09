/*2
leetcode
toleeedc
accde
edcca
*/
#include <bits/stdc++.h>
#include<string>
using namespace std;
const int MAX=26;
void sortString(string &s)
{
  int count[26]={0};
  for(int i=0;i<s.length();i++)
  {
    count[s[i]-'a']++;
  }
  for(int i=25;i>=0;i--)
  {
    for(int j=0;j<count[i];j++)
    {
      cout<<(char)('a'+i);
    }
  }
}

int main()
{
  //write your code here
  int t;
  cin>>t;
  while(t--)
  {
    string str="";
    cin>>str;
    sortString(str);
    cout<<endl;
  }


  return 0;
}

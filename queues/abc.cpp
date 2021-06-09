#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::map<char, int> m;
    std::map<char, int>:: iterator it;
    string txt,pat;
    cin>>txt>>pat;
    for(long i=0;i<pat.size();i++)
    {
        m[pat[i]]=0;
    }
    int j=0;
    while(j<txt.size())
    {
      char ch=txt[j];
      if(m.find(ch)!=m.end())
      {
          cout<<ch<<" found "<<endl;
          m[txt[j]]++;

      }
      // if(m.find(txt[i])==m.end())
      // {
      //     cout<<ch<<" found "<<endl;
      //     m[txt[j]]++;
      // }
      else
        cout<<ch<<"Not Found"<<endl;
      j++;

    }
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<"-"<<it->second<<endl;
    }

}

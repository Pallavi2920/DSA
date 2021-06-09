#include<bits/stdc++.h>
using namespace std;
void countAnagrams(string txt, string pat)
{
    std::map<char, int> m;
    std::map<char, int>::iterator itr;
    int k = pat.size(),count=0;
    for(long i=0;i<k;i++)
    {
        m[pat[i]]++;
    }
    count=m.size();
    int i=0,j=0,ans=0;
    while(j<txt.size())
    {
        char ch = txt[j];
        m[ch]--;
        if(m[ch]==0)
        {
            count--;
        }
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
          if(count==0)
          ans++;
          if(m.find(txt[i])==m.end())
            i++;
          else
            m[txt[i]]++;
          if(m[txt[i]]==1)
            count++;
          i++;
          j++;
        }
      }
    cout<<ans<<endl;

}
int main()
{
    string txt,pat;
    cin>>txt>>pat;
    countAnagrams(txt,pat);
}

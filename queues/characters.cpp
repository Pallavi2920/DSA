#include<bits/stdc++.h>
#include<string>
using namespace std;
#define MAX 26

void characters(string s, int n)
{
    int cc[MAX] = {0}, flag=0;
    for(int i = 0; i < n; i++)
    {
        cc[s[i]-'a']++;
    }
    for(int i = 0; i < n; i++)
    {
        if(cc[s[i]-'a'] == 1)
        {
            cout<<s[i]<<" ";
            flag = 1;
            break;
        }
    }
    if(flag !=1)
    {
        cout<<-1;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string str = "";
        cin>>str;
        characters(str , n);
        cout<<endl;
    }
}

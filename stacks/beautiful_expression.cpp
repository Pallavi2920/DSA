#include<bits/stdc++.h>
#include<stack>
using namespace std;
int k=1;
int checkedBal(string s)
{
    int n=-1,x=0;;
    int flag=0,inversion=0;
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-')
        {
            return n;
        }
        else
        {
            flag=1;
            if(s[i]=='}' && !st.empty())
            {
                if(st.top()=='{')
                  st.pop();
                else
                  st.push(s[i]);
            }
            else
            {
                st.push(s[i]);
            }

        }
    }
    int red_len=st.size();
    while(!st.empty() && st.top()=='{')
    {
        st.pop();
        x++;
    }

    return (red_len/2+x%2);
}

int main()
{
    while(1)
    {
        string s;
        cin>>s;
        if(checkedBal(s)!=-1)
        {
          cout<<k<<". "<<checkedBal(s)<<endl;
          k++;
        }

        else
        {
          cout<<""<<endl;
          break;
        }

    }
    return 0;
}

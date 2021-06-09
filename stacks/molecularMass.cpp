#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
stack<int>st;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int i=0;
    int result2=0;
    while(i<n)
    {
        int result=0;
        if(s[i]==')')
        {
            if(i+1<n && s[i+1]>'1' && s[i]<='9')
            {
                while(st.top()!=-1)
                {
                    result+=st.top();
                    st.pop();
                }
                st.pop();
                int x=s[i+1]-'0';
                st.push(result*x);
                i++;
                i++;
              }
              else
              {
                while(st.top()!=-1)
                {
                    result+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(result*1);
                i++;
              }
            }
          else if(s[i]=='(')
          {
              st.push(-1);
              i++;
          }
          else if(s[i]=='C')
          {
            st.push(12);
            i++;
          }
          else if(s[i]=='O')
          {
            st.push(16);
            i++;
          }
          else if(s[i]=='H')
          {
            st.push(1);
            i++;
          }
          else
          {
              int p=st.top();
              st.pop();
              int x=s[i]-'0';
              st.push(p*x);
              i++;
          }
        }
        while(!(st.empty()))
        {
            result2+=st.top();
            st.pop();
        }
        cout<<result2<<endl;
}

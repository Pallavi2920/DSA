#include<bits/stdc++.h>
using namespace std;
int pre(char c)
{
    if(c=='+' || c=='-')  return 1;
    else if(c=='*' || c=='/') return 2;
    else if(c=='^') return 3;
    else return -1;
}

string infixTopostfix(string s)
{
    stack<char>st;
    string post;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') )
        {
            post += s[i];
        }
        else if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i]==')')
        {
            while((!st.empty() && st.top()!='('))
            {
                char ch = st.top();
                st.pop();
                post += ch;
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && pre(s[i])<pre(st.top()))
            {
                char temp = st.top();
                st.pop();
                post += temp;
            }
            st.push(s[i]);
        }
    }
    while(!s.empty())
    {
        char temp = st.top();
        st.pop();
        post += temp;
    }
    return post;
}


int main()
{
    string str,str2;
    cout<<"Enter the infix expression:";
    cin>>str;
    str2 = infixTopostfix(str);
    cout<<str2<<endl;

}

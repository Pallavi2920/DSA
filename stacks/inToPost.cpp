#include<bits/stdc++.h>
using namespace std;
int pre(char c)
{
    if(c=='+' || c=='-')  return 1;
    else if(c=='*' || c=='/') return 2;
    else if(c=='^') return 3;
    else return -1;
}

string infixTopostfix(string str)
{
    stack<char>s;
    string post;
    for(int i=0;i<str.length();i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9') )
        {
            post += str[i];
        }
        else if(str[i]=='(')
        {
            s.push('(');
        }
        else if(str[i]==')')
        {
            while((!s.empty() && s.top()!='('))
            {
                char ch = s.top();
                s.pop();
                post += ch;
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && pre(str[i])<pre(s.top()))
            {
                char temp = s.top();
                s.pop();
                post += temp;
            }
            s.push(str[i]);
        }
    }
    while(!s.empty())
    {
        char temp = s.top();
        s.pop();
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

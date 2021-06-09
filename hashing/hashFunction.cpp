#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[6]={11,145,166,172,293,758};
    int hash[10]={-1};
    for(int i=0;i<6;i++)
    {
        hash[arr[i]%10]=arr[i];
    }
    for(int i=0;i<10;i++)
    {
        if(hash[i]!=0)
        {
            cout<<"Element present at slot index "<<i<<"is: "<<hash[i]<<endl;
        }
    }
}

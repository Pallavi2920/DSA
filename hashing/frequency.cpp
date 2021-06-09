#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[15]={1,1,1,3,4,5,6,7,3,3,3,4,4,4,7};
    int frequency[15]={0};
    for(int i=0;i<15;i++)
    {
        frequency[arr[i]]++;
    }
    for(int i=0;i<15;i++)
    {
        if(frequency[i]!=0)
        {
          cout<<"Frequecncy of "<<i<<" is:"<<frequency[i]<<endl;
        }
    }
}

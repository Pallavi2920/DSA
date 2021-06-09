#include<bits/stdc++.h>
using namespace std;
void truckTour(int gas[], int cost[],int n)
{
    int sum = 0, start = 0, diff = 0;
    for(int i=0;i<n;i++)
    {
        sum += gas[i]-cost[i];
        if(sum<0)
        {
            start = i+1;
            diff += sum;
            sum = 0;
        }
    }
    if(sum+diff>=0)
      cout<<start<<"\n";
    else
      cout<<"-1"<<"\n";
}
int main()
{
    int n;
    cin>>n;
    int gas[n],cost[n];
    for(int i=0;i<n;i++)
    {
        cin>>gas[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    truckTour(gas,cost,n);
}

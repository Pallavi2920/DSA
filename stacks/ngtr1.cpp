// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
//
// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
//
// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
// Output: [-1,3,-1]
// Explanation:
//     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//     For number 1 in the first array, the next greater number for it in the second array is 3.
//     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
#include<iostream>
#include<stack>
#include<vector>
#include <algorithm>
using namespace std;
stack<int>s;
vector<int>v2;
std::vector<int> v;
std::vector<int> v1;
void ngtr(std::vector<int> v)
{
    int n2 = v.size();
    for(int i=n2-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            v2.push_back(-1);
        }
        else if(s.size()>0 && s.top()>v[i])
        {
            v2.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<=v[i])
        {
            while(s.size()>0 && s.top()<=v[i])
            {
                s.pop();
            }
            if(s.size()==0)
                v2.push_back(-1);
            else
                v2.push_back(s.top());
        }
        s.push(v[i]);
    }

}


int main()
{

    int n,n1;
    cin>>n;
    cin>>n1;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    for(int i=0;i<n1;i++)
    {
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }
    reverse(v2.begin(),v2.end());
    for(long unsigned int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
}

// approach 2 -> passing nums by value, you can also use string str
#include<bits/stdc++.h>
using namespace std;

int k;
vector<int>nums;
void permutations(int ind,int n,vector<int> nums)
{
    if(k==0) return;
    if(ind==n)
    {
        k--;
        for(int i=0;i<nums.size();i++)
        {
            printf("%c", nums[i]+65);
        }
        cout<<endl;
        return;
    }
    else
    {
        for(int i=ind;i<n;i++)
        {
            swap(nums[ind],nums[i]);
            permutations(ind+1,n,nums);
        }
        // for(int i = n - 1; i > ind; i--)         // Dont need to do this if passing nums by value.
        //     swap(nums[i], nums[ind]);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        int n;
        cin>>n>>k;
        nums.clear();
        for(int i=0;i<n;i++)
        {
            nums.push_back(i);
        }
        permutations(0,n,nums);
       
    }
}

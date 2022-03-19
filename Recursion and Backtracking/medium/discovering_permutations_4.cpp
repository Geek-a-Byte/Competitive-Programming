// approach 4 -> passing nums by reference
#include<bits/stdc++.h>
using namespace std;

int k;
vector<int>nums;
void permutations(int ind,int n,string str)
{
    if(k==0) return;
    if(ind==n)
    {
        k--;
        cout<<str<<endl;
        return;
    }
    else
    {
        for(int i=ind;i<n;i++)
        {
            swap(str[ind],str[i]);
            permutations(ind+1,n,str);
        }
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
        string str="";
       for(int i=0;i<n;i++)
       {
          str+= (char)i+65;
       }
        permutations(0,n,str);
       
    }
}

// https://iryndin.dev/post/timus-1005-stone-pile/
// https://sjsakib.github.io/psbook/02-easy-problems/timus1005.html
// bruteforce approach

// time complexity : O(n * 2^n)

#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    int n;
    cin>>n;
    vector<int>weights;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        weights.push_back(x);
    }
    int max_mask = 1<<n;
    int ans=INT_MAX;
    for(int i=0;i<max_mask;i++)
    {
        int sum0=0; //sum of weights in pile 0
        int sum1=0; //sum of weights in pile 1
        for(int j=0;j<n;j++)
        {
            // cout<<(1<<j)<<" "<<i<<endl;
            if(((1<<j)&i)==0) sum0+=weights[j];
            else sum1+=weights[j];
            // cout<<sum0<<" "<<sum1<<endl;
        }
        
        ans=min(ans,abs(sum0-sum1));
    }
    cout<<ans;
}


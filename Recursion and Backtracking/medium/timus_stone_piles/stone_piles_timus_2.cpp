// Memory	O(2^n)
// Time	O(2^n)
#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main() {
    int n;
    cin>>n;
    vector<int>weights;
    int total_weight=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        weights.push_back(x);
        total_weight+=x;
    }
    int ans = total_weight;
    
    // 000 -> 0
    
    // 001 -> 000 + weights[0]
    
    // 010 -> 000 + weights[1]
    // 011 -> 001 + weights[1]
    
    // 100 -> 000 + weights[2]
    // 101 -> 001 + weights[2]
    // 110 -> 010 + weights[2]
    // 111 -> 011 + weights[2]
    
    int dp[(1<<n)+5];
    dp[0] = 0;
    int k=1;
    for (int i = 0; i < n; i++) {
        int j=0;
        for (int mask = 0; mask < (1<<i); mask++) {
            dp[k] = dp[j++] +  weights[i];
            ans = min(ans, abs((total_weight - dp[k]*2)));
            k++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

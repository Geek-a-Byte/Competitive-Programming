#include<bits/stdc++.h>
using namespace std;

signed main()
{
    //33 - 10 10 10 2 1 
    // 20 10 2 1 (4)

    // 1 2 5 10 20 50 100
    
    // 33 -
    // 100 - 100
    // 105 - 100 5
    int n;
    cin>>n;
    int i=n;
    
    vector<int>currencies = {1,2,5,10,20,50,100};
    sort(currencies.begin(), currencies.end(),greater<int>());
    vector<int>ans;

    for(int j=0;j<7;j++)
    {
        if(i==0) break;
        if(i>=currencies[j])
        {
            ans.push_back(currencies[j]);
            i=i%currencies[j];
        }
    }
    
    
    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
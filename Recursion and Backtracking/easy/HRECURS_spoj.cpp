#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin>>t;
    int caseno=1;
    while(t--)
    {
        int n;
        cin>>n;
        
        int sum=0;
        while(n--)
        {
            int v;
            cin>>v;
            sum+=v;
        }
        cout<<"Case "<<caseno++<<": "<<sum<<endl;
    }
    
}

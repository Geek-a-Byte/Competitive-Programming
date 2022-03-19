#include<bits/stdc++.h>
using namespace std;
#define int long long int

int count(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n%2==0)
    {
        return 1+count(n/2);
    }
    else
    {
        return 1+count(3*n+1);
    }
}
signed main()
{
    int m,n;
    while(cin>>m>>n){
        int ans=0;
        int b = (m>n)?m:n;
        int a = (m<n)?m:n;
        for(int i=a;i<=b;i++)
        {
            ans=max(ans,count(i));
        }
        cout<<m<<" "<<n<<" "<<ans<<endl;
    }
    
}

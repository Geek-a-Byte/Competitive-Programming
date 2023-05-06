#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int n;
    cin>>n;
    int cnt=0;
    int m=1;
    for(int i=0;i<n;i++)
    {
        string s;
        int x;
        cin>>s;
        if(s=="for"){
            cin>>x;
            m*=x;
        }
        else if(s=="add")
        {
            cnt+=m;
        }
        else if(s=="end")
        {
            m/=x;
        }
        
        //cout<<cnt<<endl;
    }
    if(cnt>=4294967295)
    {
        cout<<"OVERFLOW!!!";
    }
    else cout<<cnt;
}

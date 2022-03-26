#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define endl "\n"
#define IO read write
#define N 10000007
#define int long long
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}
int a[N];
void sieve()
{
    for(int i=2;i<=sqrt(N);i++)
    {
        if(a[i]==0){
            for(int j=i+i;j<=N;j+=i)
            {
                if(a[j]==0) a[j]=i;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(a[i]==0) a[i]=i;
    }
}
void primeFact(int n)
{
    cout<<"1";
    while(n>1)
    {
        int f=a[n];
        if(n%f==0)
        {
            cout<<" x "<<f;
            n/=f;
        }
    }
    cout<<endl;
}
signed main()
{
    FIO;
    sieve();
    //fileOJ();
    int n;
    while(cin>>n)
    {
        primeFact(n);
    }
    return 0;
}
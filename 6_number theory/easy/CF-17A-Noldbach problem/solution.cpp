#include <bits/stdc++.h>
using namespace std;
#define     FIO     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define N 1001
vector<ll>p;
bool a[N];
void sieve()
{
    ll i,j;
    for(i=4;i<=N;i+=2)
        a[i] = 1;
    for(i=3;i<=sqrt(N);i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=N;j+=(2*i))
            {
                a[j] = 1;
            }
        }
    }
    for(i=2;i<=N;i++)
    {
        if(a[i]==0)
        {
            p.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve();
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==0)
        {
            for(int j=0;p[j]<i;j++)
            {
                if(p[j]+p[j+1]+1==i)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    if(cnt>=k)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}
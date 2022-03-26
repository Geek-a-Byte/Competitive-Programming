//accepted
#include <bits/stdc++.h>
using namespace std;
#define     FIO     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define N 3001
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
    FIO;
    sieve();
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<p.size();j++){
            if(i%p[j]==0)
            {
                 a[i]++;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n+1;i++)
    {
        if(a[i]==2) cnt++;
    }
    cout<<cnt<<endl;
}
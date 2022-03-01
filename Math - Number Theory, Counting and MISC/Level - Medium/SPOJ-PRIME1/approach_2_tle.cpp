#include <bits/stdc++.h>
using namespace std;
#define     FIO     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define N 1000000000
bool a[N];
void sieve()
{
    ll i,j;
    a[0]=1;
    a[1]=1;
    for(i=3;i<32000;i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<N;j+=(2*i))
            {
                a[j] = 1;
            }
        }
    }
}

int main()
{
    ll m,n,t;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>m>>n;
        if(m<2)
        {
            cout<<"2\n";
        }
        while(m<=n)
        {
            if(a[m]==0 and m%2!=0 and m!=2)
            {
                cout<<m<<"\n";
            }
            m++;
        }
        cout<<"\n";
    }
}
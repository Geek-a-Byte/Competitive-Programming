#include <bits/stdc++.h>
using namespace std;
#define     FIO     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define     sp(x)                   std::cout << std::fixed << std::setprecision(x)
#define ll long long int
#define N 100000000
vector<ll>p;
bool a[N];
void sieve()
{
    ll i,j;
    for(i=4;i<N;i+=2)
        a[i] = 1;
    for(i=3;i<sqrt(N);i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<N;j+=(2*i))
            {
                a[j] = 1;
            }
        }
    }
    for(i=2;i<N;i++)
    {
        if(a[i]==0)
        {
            p.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    sieve();
    long double x;
    while(cin>>x)
    {
        if(x==0) break;
        auto up=upper_bound(p.begin(),p.end(),x);
        long double nop=up-p.begin();
        //cout<<"nop "<<nop<<endl;
        long double y=x/log(x);
        long double ans= (abs(nop - y) / nop)*100;
        sp(1)<<ans<<"\n"; 
    }
    return 0;
}

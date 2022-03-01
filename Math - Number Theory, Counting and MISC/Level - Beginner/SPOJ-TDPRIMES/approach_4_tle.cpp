#include <bits/stdc++.h>
using namespace std;
#define     FIO                     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int 
#define N 99998954

//here p contains all prime numbers 
vector<ll>p;
bool a[N];

void sieve()
{
    ll i,j;
    for(i=4;i<N;i+=2)
        a[i] = 1;
    for(i=3;i<=sqrt(N);i+=2)
    {
        for(j=i*i;j<N;j+=(2*i))
        {
            a[j] = 1;
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
   FIO;
   sieve();
   for(ll i=0;i<p.size();i+=100)
   {
        cout<<p[i]<<"\n";
   }
}
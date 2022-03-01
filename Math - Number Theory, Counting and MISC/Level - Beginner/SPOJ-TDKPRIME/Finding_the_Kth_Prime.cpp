//accepted
#include <bits/stdc++.h>
using namespace std;
#define     FIO     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int 
#define N 100000000 //keep it 10^8 if not worry about TLE, otherwise u will get runtime error

//here p contains all prime numbers 
vector<ll>p;
bool a[N];

void sieve()
{
    ll i,j;
    for(i=4;i<N;i+=2)
        a[i] = 1;
    for(i=3;i<sqrt(N);i+=2)
    {
        //this condition is needed for avoiding TLE
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
FIO;
   sieve();
   int q;
   cin>>q;
   for(int i=0;i<q;i++)
   {
        ll v;
        cin>>v;
        cout<<p[v-1]<<"\n";
   }
}

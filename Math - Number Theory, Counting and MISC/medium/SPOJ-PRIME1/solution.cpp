#include <bits/stdc++.h>
using namespace std;
#define     FIO     ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define N 1000000000
bool isPrime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main()
{
    ll m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        while(m<=n)
        {
            if(isPrime(m))
            {
                cout<<m<<"\n";
            }
            m++;
        }
        cout<<"\n";
    }
}
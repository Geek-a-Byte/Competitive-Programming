include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll countDivisor(ll n) {
  ll divisor = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (i * i == n) {
      divisor += 1;
    } else if (n % i == 0) {
      divisor += 2;
    }
  }
  return divisor;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--) {
        ll a,b;
        cin>>a>>b;
        ll gcd=__gcd(a,b);
        if(gcd == 1)
        {
            cout<<"1\n";
            continue;
        }
        cout<<countDivisor(gcd)<<"\n";
    }
    return 0;
}

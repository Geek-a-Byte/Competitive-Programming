#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


struct chash {
  const int RANDOM = (long long)(make_unique<char>().get())
      ^ chrono::high_resolution_clock::now()
            .time_since_epoch()
            .count();
  static unsigned long long hash_f(unsigned long long x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  static unsigned hash_combine(unsigned a, unsigned b) {
    return a * 31 + b;
  }
  int operator()(int x) const { return hash_f(x) ^ RANDOM; }
  int operator()(pair<int, int> x) const {
    return hash_combine(x.first, x.second) ^ RANDOM;
  }
};
//gp_hash_table<int, int, chash> mp;
//gp_hash_table<int, vector<pair<int, int>>, chash> mp;

signed main()
{
    int t;
    cin>>t;
    int cas=0;
    while(t--){
          if(cas>0) cout<<endl;
          gp_hash_table<ll, int, chash> mp;
          int n;
          cin>>n;
          vector<ll>a(n),b(n),c(n),d(n);
          for(int i=0;i<n;i++)
          {
              cin>>a[i]>>b[i]>>c[i]>>d[i];
          }
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<n;j++){
                mp[a[i]+b[j]]++;
              }
          }
          int cnt=0;
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<n;j++){
                int x=mp[-c[i]-d[j]];
                  if(x)
                  {
                      cnt+=x;
                  }
              }
          }
          cout<<cnt<<endl;
          cas++;
    }
}

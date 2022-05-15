#include <bits/stdc++.h>
using namespace std;

bitset<1'000'000'00>bs;

signed main()
{

   int q;
   cin>>q;
   while(q--)
   {
       int x;
       cin>>x;
//     bs.set(x);
//     bs.reset(x);
//     bs.flip(x);
       bs[x]=1;
   }
   cout<<bs.count()<<endl;
}


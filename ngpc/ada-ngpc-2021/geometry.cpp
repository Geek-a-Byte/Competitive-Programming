#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
   int n,k;
   cin>>n>>k;
   map<int,pair<int,int>>mp;
   for(int i=0;i<n;i++)
   {
       int x,y;
       cin>>x>>y;
       mp[i]={x,y};
   }
   for(auto i:mp)
  {
      cout<<i.first<<" "<<i.second<<endl;
  }
//   map<int,vector<pair<int,int>>>count;
//   for(int i=0;i<n;i++)
//   {
//       for(int j=i+1;j<n;j++)
//       {
//           int slope=(mp[j].second-mp[i].second)/(mp[j].first-mp[i].first);
//           count[slope].push_back({i,j});
//       }
}
// cout<<count.size()<<endl;
// //   }
//   for(auto i:count)
//   {
//       cout<<i.first<<" ";
//     //   for(int j=0;j<i.size();j++) cout<<j.first<<" "<<j.second<<endl;
//   }
// }
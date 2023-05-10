#include <bits/stdc++.h>
using namespace std;

signed main()
{
   ordered_set os;
//   os.insert(1);
//   os.insert(2);
//   os.erase(3);
//   cout<<*os.find_by_order(1)<<endl;
//   cout<<os.order_of_key(3)<<endl;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        os.insert(i);
    }
    vector<int>ans;
    int att=0;
    int alive=n;
    while(os.size()>1)
    {
        int kill=(att+k-1)%alive;
        ans.push_back(*os.find_by_order(kill)+1);
        os.erase(os.find_by_order(kill));
        alive--;
        att=kill;
    }
    ans.push_back(*os.begin()+1);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}

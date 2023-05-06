#include <bits/stdc++.h>
using namespace std;
#define int long double
#define pi acos(-1)
int res=0;
int a,b;
int binarySearch(int l, int r)
{
    while (l <= r) {
        
        int m = l + (((r-l)*1.0000)/ 2);
        // cout<<m<<endl;
    
        int theta=asin(((l-m)*1.0000)/m);
        int w_d=cos(theta)*m;
        if(w_d>b) break;
        int ww=b-w_d;
        
        if (res>m+m+ww)
        {    
            // cout<<res<<endl;
            res=m+m+ww;
            // cout<<res<<endl;
            return res;
        }
      
        else if (res<=m+m+ww)
        {
            res=m+m+ww;
            l = m + .9999;
        }
        // cout<<res<<endl;
        
    }
    return res;
}
  
signed main()
{
    
    while(cin>>a>>b)
    {
        res=0;
        if(a==0 and b==0)
        {
            break;
        }
        else
        {
            cout<<fixed<<setprecision(4)<<binarySearch(0,a-.9999)<<endl;
        }
    }

}

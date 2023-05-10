#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    //Now its new lower limit is 10000 and upper limit is 6227020800
    //   int res=1;
    //   for(int i=-1;i>=-20;i--)
    //   {
    //       res*=i;
    //       cout<<i<<" "<<res<<endl;
    //   }

     //output analysis
    // 1 1
    // 2 2
    // 3 6
    // 4 24
    // 5 120
    // 6 720
    // 7 5040
    // 8 40320
    // 9 362880
    // 10 3628800
    // 11 39916800
    // 12 479001600
    // 13 6227020800
    // 14 87178291200
    // 15 1307674368000
    // 16 20922789888000
    // 17 355687428096000
    // 18 6402373705728000
    // 19 121645100408832000
    
    int n;
    while(cin>>n)
    {
        if(n<0 and (-n)%2==1) cout<<"Overflow!\n";
        else if(n<0 and (-n)%2==0) cout<<"Underflow!\n";
        else if(n>=0 and n<8) cout<<"Underflow!\n";
        else if(n>13) cout<<"Overflow!\n";
        else
        {
            int res=1;
            for(int i=1;i<=n;i++)
            {
                res*=i;
            }
            cout<<res<<endl;
        }
    }
}

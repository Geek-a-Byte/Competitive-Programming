//accepted
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        /* code */
        ll a,b;
        cin>>a>>b;
        if(b%a==0)
        {
            cout<<a<<" "<<b<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
    }
    return 0;
}
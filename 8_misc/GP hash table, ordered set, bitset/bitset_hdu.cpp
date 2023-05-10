#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    while(cin>>n)
    {
        bitset<20>bs(n);
        int start=0;
        string s=bs.to_string();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                start=1;
            }
            if(start==1)
            {
                cout<<s[i];
            }
        }
        cout<<endl;
    }
}



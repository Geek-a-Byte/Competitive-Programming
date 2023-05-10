#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    int cas=1;
    while(cin>>n>>q){
        if(n==0 and q==0) break;
        cout<<"CASE# "<<cas++<<":"<<endl;
        vector<int>v;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        while(q--)
        {
            int y;
            cin>>y;
            int pointer=lower_bound(v.begin(), v.end(),y)-v.begin();
            if(v[pointer]==y)
            {
                cout<<y<<" found at "<<pointer+1<<endl;
            }
            else
            {
                cout<<y<<" not found"<<endl;
            }
            
        }
    }
}
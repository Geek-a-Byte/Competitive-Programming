//accepted
#include <bits/stdc++.h>
using namespace std;

map<int,int>place;
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
        place.clear();
        for(int i=n-1;i>=0;i--)
        {
             place[v[i]]=i+1;
        }
        while(q--)
        {
            int y;
            cin>>y;
            if(place[y]!=0)
            {
                cout<<y<<" found at "<<place[y]<<endl;
            }
            else
            {
                cout<<y<<" not found"<<endl;
            }
        }
    }
}
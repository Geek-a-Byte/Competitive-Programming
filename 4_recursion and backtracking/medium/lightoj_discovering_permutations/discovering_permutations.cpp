// approach 1
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
vector<int>ds;
map<int,int>visited;
void permutations(int n,int k)
{
    if(ans.size()>=k)
    {
        return;
    }
    if(ds.size()==n)
    {
        ans.push_back(ds);
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                ds.push_back(i);
                permutations(n,k);
                ds.pop_back();
                visited[i]=0;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        int n,k;
        cin>>n>>k;
        visited.clear();
        ds.clear();
        ans.clear();
        permutations(n,k);
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c", ans[i][j]+65);
            }
            cout<<endl;
        }
    }
}

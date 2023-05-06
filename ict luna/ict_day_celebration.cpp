#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

#define int long long
#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define ld long double

#define pii pair<int, int>
#define stlloop(x) for (__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define CLR(p) memset(p, 0, sizeof(p))
#define sp(x) std::cout << std::fixed << std::setprecision(x)

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b))/gcd(a, b)

#define PI acos(-1)
#define N 10000000
const int INF = 0x3f3f3f3f;
const int mod = 100000007;


void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

signed main()
{
    fast
    fileOJ();
    int t;
    cin>>t;
    int cn=1;
    while(t--){
    cout<<"Case "<<cn++<<": ";
    int n;
    cin>>n;
    string grid[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]=="*")
            {
                grid[i][j]="C";
            }
            // cout<<grid[i][j]<<" ";
        }
        // cout<<endl;
    }

    map<string,int>mp;
    string col="";
    for(int i=0; i<n; i++)
    {
        string row="";
        for(int j=0; j<n-2; j++)
        {
        //    cout<<grid[i][j]<<" "<<grid[i][j+1]<<" "<<grid[i][j+2]<<endl;
           if(grid[i][j]=="I" and grid[i][j+1]=="C" and grid[i][j+2]=="T"){
             row+="ICT";
            //  cout<<row<<endl;
             if(row=="ICT"){
                // cout<<i<<" "<<j<<endl;
                mp[row]++;
                row="";
             }
           }
        }
        
    }
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout<<grid[i][j];
    //     }
    //     cout<<endl;
    // }
    for(int j=0; j<n; j++)
    {
        string col="";
        for(int i=0; i<n-2; i++)
        {
           if(grid[i][j]=="I" and grid[i+1][j]=="C" and grid[i+2][j]=="T"){
            // cout<<grid[i][j]<<" "<<grid[i][j+1]<<" "<<grid[i][j+2]<<endl;
             col+="ICT";
            //  cout<<col<<endl;
             if(col=="ICT"){
                // cout<<j<<" "<<i<<endl;
                mp[col]++;
                col="";
             }
           }
        }
        
    }
    cout<<mp["ICT"]<<endl;
    }
}
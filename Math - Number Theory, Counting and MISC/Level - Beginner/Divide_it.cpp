#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define PI acos(-1)
#define rep(i, k, n) for (int i = k; i < n; i++)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define All(p) p.begin(), p.end()
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define PII pair<int, int>

using namespace std;

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for file input output
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    
    while(t--)
    {
    	long long int n;
    	cin>>n;
    	int c=0;
    	while(n!=1){
    		
    	if(n%6==0||n%10==0||n%30==0||n%2==0)
    	{
             n=1ll*(n/2);

    	}
    	else if(n%3==0||n%15==0)
    	{
    		n=2ll*(n/3);
    	}
    	else if(n%5==0)
    	{
    		n=4ll*(n/5);
    	}
    	else
    		break;
    	
    	c++;
    }
    if(n==1){
    cout<<c<<endl;
    }
    else cout<<"-1"<<endl;
    }
    
    return 0;
}
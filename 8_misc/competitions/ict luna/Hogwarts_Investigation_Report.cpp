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

int isLetter(char cc)
{
    if(cc>=65 and cc<=90)
    {
        return 1;
    }
    if(cc>=97 and cc<=122)
    {
        return 1;
    }
    return 0;
}
int isVowel(char cc)
{
    if(cc=='a' or cc=='e' or cc=='i' or cc=='o' or cc=='u')
    {
        return 1;
    }
    if(cc=='A' or cc=='E' or cc=='I' or cc=='O' or cc=='U')
    {
        return 1;
    }
    return 0;
}
signed main()
{
    fast
    fileOJ();
    int t;
    cin>>t;
    string ss;
    getline(cin,ss);
    while(t--){
        getline(cin,ss);
        reverse(ss.begin(),ss.end());
        // cout<<ss<<endl;
        string ans="";
        for(int i=0; i<ss.length(); i++){
             if(ss[i]==' '){
                ans+=' ';
                continue;
             }
             int char_to_int=ss[i];
             char cc=char(char_to_int);
             if(isVowel(cc))
             {
                ans+=cc;
             }
             else{
                char_to_int--;
                char cc;
                if(char_to_int==65)
                {
                    cc='Z';
                }
                else if(char_to_int==97)
                {
                    cc='z';
                }
                else 
                {
                    cc=char(char_to_int);
                }

                if(isVowel(cc))
                {
                    char_to_int--;
                    cc=char(char_to_int);
                    // ans+=char(char_to_int);
                }
                ans+=cc;
             }
        }
        cout<<ans<<endl;
    }
}
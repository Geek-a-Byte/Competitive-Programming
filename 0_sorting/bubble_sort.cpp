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

void bubble_sort(vector<int>&v)
{
    // Time Complexity: O(N^2)
    // Auxiliary Space: O(1) 
    int loop_count=0;
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=0;j<v.size()-i-1;j++)
        {
            // for i = 0, j=0~3
            /**
             * 4 5 3 2 1
             * 4 3 5 2 1
             * 4 3 2 5 1
             * 4 3 2 1 5
             */
            // for i = 1, j=0~2
            /**
             * 3 4 2 1 5
             * 3 2 4 1 5
             * 3 2 1 4 5
             * 
             */
            // for i = 2, j=0~1
            /**
             * 2 3 1 4 5
             * 2 1 3 4 5
             */
            // for i = 3, j=0
            /**
             * 1 2 3 4 5
             * 
             */
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
            }
            loop_count++;
        }
    }
    cout<<"loop count "<<loop_count<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
}

void optimized_bubble_sort(vector<int>&v)
{
    // Time Complexity: O(N^2)
    // Auxiliary Space: O(1) 
    int loop_count=0;
    for(int i=0;i<v.size()-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<v.size()-i-1;j++)
        {
            // for i = 0, j=0~3
            /**
             * 3 1 2 4 5
             * 1 3 2 4 5
             * 1 2 3 4 5
             * 1 2 3 4 5
             */
             // for i = 1, j=0~2
            /**
             no swapping in this iteration of j, so sorting stopped
             */
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                swapped=true;
            }
            loop_count++;
        }
        if(!swapped)
        {
            break;
        }
    }
    cout<<"loop count "<<loop_count<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
}

signed main()
{
    fast
    vector<int>v1 = {5,4,3,2,1};
    vector<int>v2 = {3,1,2,4,5};

    // Bubble sort takes minimum time (Order of n) when elements are already sorted. Hence it is best to check if the array is already sorted or not beforehand, to avoid O(N2) time complexity.

    bubble_sort(v2);
    cout<<endl;
    optimized_bubble_sort(v2);
    cout<<endl;
}
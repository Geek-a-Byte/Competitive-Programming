#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

#define int long long
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

void printarray(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Worst Case Time Complexity is: O(N^2)
// Average Case Time Complexity is: O(N^2)
// Best Case Time Complexity is: O(N^2)
// Space Complexity: O(1)
void selection_sort(vector<int>& arr)
{
    int s = arr.size();
    for (int i = 0; i < s - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < s; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
        printarray(arr);
    }
}



signed main()
{
    fast
    vector<int>v1 = {5,4,3,2,1};
    vector<int>v2 = {1,2,5,3,4};
    
    printarray(v2);
    selection_sort(v2);
    cout<<endl;
    printarray(v2);
}
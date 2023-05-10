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

// Best Case	O(n*logn)
// Average Case	O(n*logn)
// Worst Case	O(n^2)
// Space Complexity: O(n*logn)
//taking middle element as pivot , worst case improves from O(n^2) to O(nlogn)
int partition(vector<int>& arr, int s,int e)
{
    int pivot = arr[e];
    int partitionIndex = s;
    for(int i = s; i < e; i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex], arr[e]);
    return partitionIndex;
}

void quick_sort(vector<int>&arr, int s,int e)
{
    if(s<e)
    {
        int partitionIndex = partition(arr,s,e);
        quick_sort(arr, s, partitionIndex-1);
        quick_sort(arr, partitionIndex+1, e);
    }
}


signed main()
{
    fast
    vector<int>v1 = {5,4,3,2,1};
    vector<int>v2 = {1,2,5,3,4};
    
    printarray(v2);
    quick_sort(v2,0,v2.size()-1);
    cout<<endl;
    printarray(v2);
}
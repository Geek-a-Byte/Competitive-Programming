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

//worst case complexity - O (n^2)
//The worst case occurs when the array is sorted in reverse order.
//best case complexity - O(n)
//The best case occurs when the array is sorted in ascending order.
//average case complexity - O(n^2)
void insertion_sort(vector<int>& arr)
{
    printarray(arr);
    int n = arr.size();
    int j;
    int loop_count=0;
    for (int i = 1; i < n; i++)
    {
        // 5 1 4 3 2, j = 1
        // 1 5 4 3 2, j = 2, 1
        // 1 4 5 3 2, j = 3, 2, 1
        // 1 3 4 5 2, j = 4, 3, 2, 1
        // 1 2 3 4 5
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j], arr[j - 1]);
            }
            loop_count++;
        }
        printarray(arr);
    }
    cout<<"loop count "<<loop_count<<endl;
}



signed main()
{
    fast
    vector<int>v1 = {5,4,3,2,1};
    vector<int>v2 = {1,2,5,3,4};

    insertion_sort(v2);
    printarray(v2);
    cout<<endl;
}
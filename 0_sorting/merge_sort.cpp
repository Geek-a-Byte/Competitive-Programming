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

void merge(vector<int>&l, vector<int>&r, vector<int>&arr, int n)
{
    int ll = l.size();
    int lr = r.size();
    //i is the smallest unpicked element in left array
    //j is the smallest unpicked element in rigth array
    //k is the position that needs to be filled in arr
    int i, j, k;
    i = j = k = 0;

    while (i < ll && j < lr)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < ll)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < lr)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr)
{
    int n=arr.size();
    if (n < 2)
        return;

    int mid = n / 2;
    vector<int>left(mid);
    vector<int>right(n-mid);

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    merge_sort(left);
    merge_sort(right);
    merge(left, right, arr, n);
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

signed main()
{
    fast
    vector<int>v1 = {5,4,3,2,1};
    vector<int>v2 = {3,1,2,4,5};

    // merge sort
    // Worst Case Time Complexity [ Big-O ]: O(n*log n)
    // Best Case Time Complexity [Big-omega]: O(n*log n)
    // Average Time Complexity [Big-theta]: O(n*log n)
    // Space Complexity: O(n)

    merge_sort(v2);
    printarray(v2);
    cout<<endl;
}
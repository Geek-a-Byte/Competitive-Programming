//using middle element as a pivot

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define PI acos(-1)
#define rep(i, k, n) for (int i = k; i < n; i++)
#define PB(x) push_back(x)
#define All(p) p.begin(), p.end()
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define PII pair<int, int>

using namespace std;

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
//taking middle element as pivot , worst case improves from O(n^2) to O(nlogn)
void quick_sort(int a[], int lb, int up, int n)
{
    int i, j, pivot;
    if (lb >= up)
        return;

    i = lb;
    j = up;

    int mid = (lb + up) / 2;
    pivot = a[mid];

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        printarray(a, n);
    }

    // recursion
    quick_sort(a, lb, j, n);
    quick_sort(a, i, up, n);
}

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for file input output
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int arr[] = {56, 10, 32, 6, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1, size);
    printarray(arr, size);
    return 0;
}
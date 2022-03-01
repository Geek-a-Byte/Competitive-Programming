//accepted
//UVA - 11462
//using quick sort -> taking middle element of the array as pivot
#include <iostream>
using namespace std;
void quick_sort(int a[], int lb, int up)
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
    }

    // recursion
    quick_sort(a, lb, j);
    quick_sort(a, i, up);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        quick_sort(arr, 0, n - 1);
        for (int i = 0; i < n - 1; i++)
            cout << arr[i] << " ";
        cout << arr[n - 1];
        cout << "\n";
    }
}
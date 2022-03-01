#include <bits/stdc++.h>
using namespace std;

//worst case complexity - O (n^2)
//The worst case occurs when the array is sorted in reverse order.
//best case complexity - O(n)
//The best case occurs when the array is sorted in ascending order.
//average case complexity - O(n^2)
void insertion_sort(int arr[], int size)
{
    int j;
    for (int i = 1; i <= size - 1; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // //for file input output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int arr[] = {56, 10, 32, 6, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size)
{
    bool all_swapped;
    for (int i = 0; i < size - 1; i++)
    {
        all_swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                all_swapped = true;
            }
        }
        if (all_swapped == false)
        {
            // IF no two elements were swapped by inner loop, then break
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
//optimized with all_swapped
//Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
//Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
//Auxiliary Space: O(1)

//The above function (without optimization) always runs in O(n^2) time even if the array is sorted

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
    bubble_sort(arr, size);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int s)
{
    int steps = 0;
    for (int i = 0; i < s - 1; i++)
    {
        int min_index = i;
        int j = i + 1;
        while (j <= s - 1)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
                steps++;
            }
            j++;
        }
        swap(arr[min_index], arr[i]);
    }
    cout << steps << "\n";
    for (int i = 0; i < s; i++)
    {

        cout << arr[i] << " ";
    }
}
int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for file input output
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int arr[] = {64, 25, 12, 22, 11};
    int arr[] = {56, 10, 32, 6, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);
    return 0;
}
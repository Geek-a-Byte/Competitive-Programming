//no comparison sort
#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void count_sort(int arr[], int n)
{

    int m = max(arr, n);
    // cout << m << endl;
    vector<int> count(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    //cumulative
    for (int i = 1; i < m + 1; i++)
    {
        count[i] = count[i - 1] + count[i];
    }

    int output[n] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        int x = arr[i];
        int y;
        count[x]--;
        y = count[x];
        output[y] = x;
    }
    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 4, 3, 0, 2, 1, 7, 1, 4, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    count_sort(arr, n);
}

//time complexity for counting sort: O(n)
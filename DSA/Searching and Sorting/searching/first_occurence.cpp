#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int s, int l, int r)
{
    int mid, ans = -1;
    static int step = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        step++;
        //base case
        if (arr[mid] == s)
        {
            //cout << "steps: " << step << endl;
            ans = mid;
            r = mid - 1;
        }
        else if (arr[mid] > s)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int main()
{
    int arr[] = {10, 10, 20, 20, 20, 30, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "enter the element you want to search:\n";
    int s;
    cin >> s;
    int result = binary_search(arr, s, 0, size - 1);
    (result == -1) ? cout << "-1\n" : cout << "found at " << result << "\n";
}
/*
Time Complexity : O(log n) 
Auxiliary Space : O(1) 
*/
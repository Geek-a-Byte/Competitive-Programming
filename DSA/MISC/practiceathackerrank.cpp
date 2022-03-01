#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {

        int size;
        cin >> size;
        arr[i].assign(size, 0);
        for (int j = 0; j < size; j++)
        {
            int element;
            cin >> element;
            arr[j].push_back(element);
        }
        }
}
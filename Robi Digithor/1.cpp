#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count;
    int T, y;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        count = 0;
        cin >> y;

        for (int i = y; i >= 2020; i = i - 4)
        {
            count++;
        }
        cout << count << endl;
    }
}
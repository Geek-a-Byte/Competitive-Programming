#include <iostream>
#include <map>
#define max 100000000
using namespace std;
int arr[max];
int main()
{
    int n;
    cin >> n;

    map<long long int, int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
    }

    int cnt = 0;
    for (auto i : v)
    {
        if (i.second > i.first)
        {
            cnt = cnt + i.second - i.first;
        }
        else if (i.second < i.first)
        {
            cnt += i.second;
        }
    }

    cout << cnt << endl;

    return 0;
}
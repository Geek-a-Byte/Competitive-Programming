// 10 20 30 40 50 60
// -> 20
// INDEX : 1
// 10 20 30 40 50 60
// -> 0
// index: -1

#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int linear_search(vector<int> v, int s)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (s == v[i])
            return i;
    }
    return -1;
}
int main()
{
    vector<int> arr;
    int new_element;
    for (int i = 0; i < 6; i++)
    {
        cin >> new_element;
        arr.push_back(new_element);
    }
    printvector(arr);
    cout << "enter the element you want to search:\n";
    int s;
    cin >> s;
    int result = linear_search(arr, s);
    (result == -1) ? cout << "not found\n" : cout << "found\n";
}

//time complexity O(n)
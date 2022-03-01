#include <bits/stdc++.h>
using namespace std;

//finding the last element would take O(n) in previous method, but in this
//method it will take O(1) as the loop will be executed for only once

//if any element is not found in the vector/array then in this method the
//loop will be executed half the time of the previous metgod i.e (O(n/2))
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
    int first = 0;
    int last = v.size() - 1;
    while (first <= last)
    {
        //element finding from left side
        if (v[first] == s)
        {
            return first;
        }
        //element finding from right side
        if (v[last] == s)
        {
            return last;
        }
        first++;
        last--;
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
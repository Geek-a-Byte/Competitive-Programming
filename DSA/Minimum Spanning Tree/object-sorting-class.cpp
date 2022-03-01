#include <bits/stdc++.h>
using namespace std;

class Time
{
public:
    int start, finish;
    Time()
    {
    }
    Time(int s, int f)
    {
        start = s;
        finish = f;
    }
    void print()
    {
        cout << "Start: " << start << " "
             << "finish: " << finish << endl;
    }
};

bool operator<(const Time &t1, const Time &t2)
{
    if (t1.finish < t2.finish)
    {
        return true;
    }
    if (t1.finish > t2.finish)
    {
        return false;
    }
    if (t1.start > t2.start)
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("objectsortinginput.txt", "r", stdin);
    // int a[] = {1, 2, 0, 5, -1};
    // sort(a, a + 5);
    // for (int i : a)
    // {
    //     cout << i << " ";
    // }
    int n;
    cin >> n;
    Time time[n];
    for (int i = 0; i < n; i++)
    {
        // int s, f;
        // cin >> s >> f;
        // Time t(s, f);
        // time[i] = t;

        cin >> time[i].start;
        cin >> time[i].finish;
    }
    for (int i = 0; i < n; i++)
    {
        time[i].print();
    }
    //object array ke sort korte compare function use korte hoy
    //finishing time er ascending order e
    cout << endl;

    //eki time hoile insertion order er upor depend kore sort hobe
    sort(time, time + n);

    for (int i = 0; i < n; i++)
    {
        time[i].print();
    }
}

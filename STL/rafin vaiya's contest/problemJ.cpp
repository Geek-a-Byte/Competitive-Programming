#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        if (n == 1)
        {
            cout << "Discarded cards:" << endl;
            cout << "Remaining card: " << n << endl;
            continue;
        }
        std::deque<int> dqu;
        for (int i = 1; i <= n; i++)
        {
            dqu.push_back(i);
        }
        cout << "Discarded cards: ";

        while (dqu.size() > 1)
        {
            if (dqu.size() != 2)
                cout << dqu.front() << ", ";
            else
            {
                cout << dqu.front() << endl;
            }
            dqu.pop_front();
            dqu.push_back(dqu.front());
            dqu.pop_front();
        }
        cout << "Remaining card: " << dqu.front() << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
long long int p, c;
int main()
{
    int k = 1;
    while (cin >> p >> c)
    {
        if (p == 0 && c == 0)
            break;
        deque<long long int> q;
        cout << "Case " << k << ":\n";
        for (long long int i = 1; i <= p && i <= c; i++)
        {
            q.push_back(i);
        }
        for (int i = 0; i < c; i++)
        {
            char cc;
            cin >> cc;
            if (cc == 'N')
            {
                long long int x = q.front();
                q.pop_front();
                cout << x << "\n";
                q.push_back(x);
            }
            else if (cc == 'E')
            {
                long long int x;
                cin >> x;
                for (auto it = q.begin(); it != q.end(); ++it)
                {
                    if (*it == x)
                    {
                        q.erase(it);
                        break;
                    }
                }
                q.push_front(x);
                // cout << endl;
            }
        }
        k++;
    }
    return 0;
}
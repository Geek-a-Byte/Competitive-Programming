#include <bits/stdc++.h>
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define sp(x) std::cout << std::fixed << std : : setprecision(x);
#define IO read write

void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}
using namespace std;

int main()
{
    fileOJ();

    int p, c;
    int i = 1;
    while (cin >> p >> c)
    {

        if (p == 0 && c == 0)
            break;
        queue<long long int> q;
        cout << "Case " << i << ":\n";
        for (long long int i = 1; i <= p && i <= c; i++)
        {
            q.push(i);
        }
        for (int i = 0; i < c; i++)
        {
            char cc;
            cin >> cc;
            if (cc == 'N')
            {
                long long int x = q.front();
                q.pop();
                cout << x << "\n";
                q.push(x);
            }
            else if (cc == 'E')
            {
                long long int x;
                cin >> x;
                queue<long long int> q1;
                q1.push(x);
                while (!q.empty())
                {
                    if (q.front() == x)
                    {
                        q.pop();
                        continue;
                    }
                    q1.push(q.front());
                    q.pop();
                }
                q = q1;
            }
        }
        i++;
    }
    return 0;
}
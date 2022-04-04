#include <bits/stdc++.h>
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define TC     \
    int tc;    \
    cin >> tc; \
    for (int cn = 1; cn <= tc; ++cn)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define sp(x) std::cout << std::fixed << std : : setprecision(x);
#define IO read write
#define PI acos(-1)
#define MP(x, y) make_pair(x, y)
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define PII pair<int, int>
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

using namespace std;
int main()
{
    FIO
    fileOJ();
    deque<int> q;
    int dir = 1;

    TC
    {
        string str;
        cin >> str;

        if (q.empty() && (str == "back" || str == "front"))
        {
            cout << "No job for Ada?\n";
            continue;
        }
        if (str == "toFront")
        {
            int n;
            cin >> n;
            if (dir == 1)
                q.push_front(n);
            else
                q.push_back(n);
        }
        else if (str == "front")
        {
            if (dir == 1)
            {
                cout << q.front() << endl;
                q.pop_front();
            }
            else
            {

                cout << q.back() << endl;
                q.pop_back();
            }
        }
        else if (str == "back")
        {
            if (dir == 1)
            {
                cout << q.back() << endl;
                q.pop_back();
            }
            else
            {
                cout << q.front() << endl;
                q.pop_front();
            }
        }
        else if (str == "reverse")
        {
            if (q.empty())
                continue;
            else
                dir = -dir;
        }
        else if (str == "push_back")
        {
            int n;
            cin >> n;
            if (dir == 1)
            {
                q.push_back(n);
            }
            else
                q.push_front(n);
        }
    }

    return 0;
}
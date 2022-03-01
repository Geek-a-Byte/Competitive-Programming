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
    string str;
    cin >> str;
    stack<char> st;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (st.empty())
            st.push(str[i]);
        else
        {
            char x = st.top();
            if (x == str[i])
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}
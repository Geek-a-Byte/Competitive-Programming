#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int n = str.size();
    queue<char> q[36];
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            q[str[i] - 48].push(str[i]);
        }
        else if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
        {
            q[toupper(str[i]) - 55].push(str[i]);
        }
    }

    int k = 0;
    for (int i = 0; i < 36; i++)
    {
        int size = q[i].size();
        while (!q[i].empty())
        {
            char front = q[i].front();
            str[k] = front;
            q[i].pop();
            k++;
        }
    }
    str[k] = '\0';
    for (int i = 0; i < k; i++)
    {
        cout << str[i];
    }
}
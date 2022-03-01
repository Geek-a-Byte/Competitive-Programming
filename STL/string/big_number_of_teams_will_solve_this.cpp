#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    char s1[40], s2[40], s3[40];
    getchar();
    for (int j = 1; j <= t; j++)
    {
        gets(s1);
        gets(s2);
        if (strcmp(s1, s2) == 0)
        {
            cout << "Case " << j << ": "
                 << "Yes" << endl;
        }
        else
        {
            int i = 0;
            for (auto x : s1)
            {
                if (x != ' ')
                {
                    s3[i] = x;
                    i++;
                }
            }
            s3[i] = '\0';
            if (strcmp(s3, s2) == 0)
                cout << "Case " << j << ": "
                     << "Output Format Error"
                     << endl;
            else
                cout << "Case " << j << ": "
                     << "Wrong Answer"
                     << endl;
        }
    }
}
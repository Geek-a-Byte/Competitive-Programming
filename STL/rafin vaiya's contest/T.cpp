#include <bits/stdc++.h>
using namespace std;

int isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1 >> s2;
        if (s1.size() != s2.size())
        {
            cout << "No" << endl;
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] != s2[i])
                {
                    if (isVowel(s1[i]) && isVowel(s2[i]))
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                else
                {
                    flag = 1;
                }
            }
            if (flag)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

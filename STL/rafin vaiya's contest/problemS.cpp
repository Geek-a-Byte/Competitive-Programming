#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    set<char> v;
    while (getline(cin, s))
    {
        if (s[0] == '*')
            break;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            char c = tolower(word[0]);
            if (c >= 97 && c <= 122)
            {
                v.insert(c);
            }
        }
        if (v.size() == 1)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        v.clear();
    }
}
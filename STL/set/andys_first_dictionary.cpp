#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> s;
    string s1;
    while (cin >> s1)
    {

        //transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        string word = "";
        for (auto x : s1)
        {
            char c = tolower(x);
            if (c >= 97 && c <= 122)
            {
                word = word + c;
            }
            else if (word != "")
            {
                s.insert(word);
                word = "";
            }
        }
        if (word != "")
        {
            s.insert(word);
        }
    }
    set<string>::iterator it;
    for (it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << endl;
    }
}
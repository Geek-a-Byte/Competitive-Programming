#include <bits/stdc++.h>
using namespace std;

map<char, char> mp;

int main()
{
    mp['q'] = 'a';
    mp['w'] = 'b';
    mp['e'] = 'c';
    mp['r'] = 'd';
    mp['t'] = 'e';
    mp['y'] = 'f';
    mp['u'] = 'g';
    mp['i'] = 'h';
    mp['o'] = 'i';
    mp['p'] = 'j';
    mp['a'] = 'k';
    mp['s'] = 'l';
    mp['d'] = 'm';
    mp['f'] = 'n';
    mp['g'] = 'o';
    mp['h'] = 'p';
    mp['j'] = 'q';
    mp['k'] = 'r';
    mp['l'] = 's';
    mp['z'] = 't';
    mp['x'] = 'u';
    mp['c'] = 'v';
    mp['v'] = 'w';
    mp['b'] = 'x';
    mp['n'] = 'y';
    mp['m'] = 'z';
    mp[' '] = ' ';

    string str;
    getline(cin, str);
    for (int i = 0;; i++)
    {
        if (str[i] != '\0')

            cout << mp[str[i]];
        else
        {
            break;
        }
    }
}
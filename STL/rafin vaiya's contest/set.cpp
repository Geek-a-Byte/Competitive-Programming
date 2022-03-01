#include <bits/stdc++.h>
using namespace std;

int main()
{
    //set  -> std::set ->  ordered_set  we do not write ordered_set bcoz set is implicitely ordered
    //set will store unique integers in ordered form i.e it will sort them out
    //set will store the strings which are different in case but same in alphabets
    //if we use set to store strings, it will store them lexicographically, i.e A>B>....a>b, and would be case sensitive
    //if we store integers as string, it will store them after comparing the first elements of those strings
    set<string> s;
    s.insert("apple");
    s.insert("apple");
    s.insert("Apple");
    s.insert("cat");
    s.insert("bar");
    s.insert("orange");
    s.insert("Orange");
    s.insert("1");
    s.insert("3");
    s.insert("15");
    s.insert("05");
    s.insert("45");
    s.insert("586");
    s.insert("546");

    if (s.find("hi") == s.end())
    {
        cout << "hi doesn't exist in the set" << endl;
    }
    else
    {
        cout << "hi does sexist in the set" << endl;
    }
    for (auto it : s)
    {
        cout << it << " ";
    }
}

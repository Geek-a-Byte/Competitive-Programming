#include <bits/stdc++.h>

using namespace std;

void printString(char *st)
{
    for (int i = 0; i < strlen(st); i++)
        cout << st[i];
    cout << endl;
}

void sortString(char *str)
{
    /** GRADED CODE **/
    /// write your code here with comment
    int n = strlen(str);
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
}

int findValue(char ch, char *st)
{
    /** GRADED CODE **/
    /// write your code here with comment
    int n = strlen(st);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char st[1000000];
    cin.get(st, 1000000);
    int n = strlen(st);

    sortString(st); /// The essay is sorted

    while (1)
    {
        int choice;
        cin >> choice;
        if (choice == 3)
            break;
        switch (choice)
        {
        case 1:
            printString(st); /// Prints the sorted Array.
            break;
        case 2:
            char cs;
            cin >> cs;
            int ret = findValue(cs, st);
            if (ret != -1)
                cout << "Character \'" << cs << "\' found at " << ret << endl;
            else
                cout << "Character \'" << cs << "\' not found." << endl;
            break;
        }
    }
}

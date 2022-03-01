// #include <bits/stdc++.h>

// using namespace std;

// long long fib(int n)
// {
//     if (n == 0)
//         return 0;
//     if (n == 1)
//     {
//         return 1;
//     }
//     return fib(n - 1) + fib(n - 2);
// }

// int main()
// {
//     cout << fib(10);
// }

//considering fibonacci tree as a binary tree
//if there n=4 then node no will 2^n ( or more than that )
//overlapping subproblem
//-1 -> unset

#include <iostream>

using namespace std;

long long dp[100];

void init()
{
    for (int i = 0; i < 100; i++)
    {
        dp[i] = -1;
    }
}

long long fib(int n)
{
    if (dp[n] == -1)
    {
        if (n == 0)
            dp[0] = 0;
        else if (n == 1)
            dp[1] = 1;
        else
        {
            dp[n] = fib(n - 1) + fib(n - 2);
        }
    }
    return dp[n];
}

int main()
{
    cout << fib(10);
}

//order (1)//linear//memoization technique
#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[],
             int i, int **dp)
{

    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W)
    {
        dp[i][W] = knapSack(
            W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else
    {
        dp[i][W] = max(
            val[i] + knapSack(
                         W - wt[i], wt, val, i - 1, dp),
            knapSack(W, wt, val, i - 1, dp));
        return dp[i][W];
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    int **dp;
    dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSack(W, wt, val, n - 1, dp);
}

int main()
{
    int item_no;
    cin >> item_no;
    int max_weight;
    cin >> max_weight;
    int val[4];
    int wt[4];
    for (int i = 0; i < item_no; i++)
    {
        cin >> val[i];
        cin >> wt[i];
    }
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(max_weight, wt, val, n);
    return 0;
}

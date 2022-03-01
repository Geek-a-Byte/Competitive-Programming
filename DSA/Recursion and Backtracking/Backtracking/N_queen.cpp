#include <bits/stdc++.h>
using namespace std;

int board[100][100];
int N;
int CNT;

void init()
{
    CNT = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            board[i][j] = 0;
    }
}

void print()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;
}

int isSafe(int r, int c) //iterative
{
    int i = r;
    int j = c;
    while (1)
    {
        if (i == 0)
            break;
        if (board[i][c] == 1)
            return 0;
        i--;
    }

    i = r;
    j = c;

    while (1)
    {
        if (i == 0 || j == 0)
            break;
        if (board[i][j] == 1)
            return 0;
        i--;
        j--;
    }

    i = r;
    j = c;

    while (1)
    {
        if (i == 0 || j == N + 1)
            break;
        if (board[i][j] == 1)
            return 0;
        i--;
        j++;
    }

    return 1;
}

void N_Queen(int i)
{
    if (i == N + 1)
    {
        cout << "one solution found" << endl;
        CNT++;
        print();
        return;
    }

    for (int j = 1; j <= N; j++)
    {
        ///[i][j].....placeable or not
        if (isSafe(i, j) == 1)
        {
            //cout << " after getting isSafe ==1 " << endl;
            board[i][j] = 1;
            print();
            //cout << "after calling N_queen(i+1): " << endl;
            N_Queen(i + 1);
            //print();
            //cout << "after making board[i][j]=0 again " << endl;
            board[i][j] = 0;
            print();
        }
    }
}

int main()
{
    cin >> N;
    init();
    N_Queen(1);
    cout << CNT << endl;
}

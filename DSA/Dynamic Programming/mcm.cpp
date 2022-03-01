
#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int n;           ///number of matrix
int m[101][101]; ///matrix for storing number of multiplication
int p[101];      ///dimention storing array
//int s[101][101];/// for parenthesis

int mcm(int i, int j)
{
    if (i == j)
        return 0;
    //int N=j-i+1;

    ///value is not set yet.
    if (m[i][j] == 0)
    {
        int min = INF;
        int index = 1;
        for (int k = 1; k <= j - i; k++)
        {
            int x = mcm(i, i + k - 1) + mcm(i + k, j) + p[i - 1] * p[i + k - 1] * p[j];
            if (x < min)
            {
                min = x;
                index = k;
            }
        }
        m[i][j] = min;
        // s[i][j]=index;
        m[j][i] = index;
    }

    return m[i][j];
}

void parenthesis(int i, int j)
{

    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    //k=s[i][j];
    int k = m[j][i];
    parenthesis(i, i + k - 1);
    parenthesis(i + k, j);
    cout << ")";
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int r, c;
        cin >> r >> c;
        p[i - 1] = r;
        p[i] = c;
    }
    for (int i = 0; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    int result = mcm(1, n);
    cout << result << endl;
    mcm(1, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    parenthesis(1, n);
}

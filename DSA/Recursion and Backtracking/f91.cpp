#include <iostream>
using namespace std;
typedef long long ll;

ll f91(int n)
{
  if (n >= 101)
  {
    n = n - 10;
    return n;
  }
  else if (n <= 100)
    return f91(f91(n + 11));
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  while (1)
  {
    int n;
    cin >> n;
    if (n == 0)
      break;
    else if (n >= 101)
    {
      printf("f91(%d) = %d\n", n, n - 10);
    }
    else if (n < 101)
    {
      printf("f91(%d) = %d\n", n, f91(n));
    }
  }
}
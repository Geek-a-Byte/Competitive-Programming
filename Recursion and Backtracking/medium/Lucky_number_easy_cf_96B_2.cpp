// https://quanticdev.com/tools/recursion-visualization/
//method 2
#include <bits/stdc++.h>
using namespace std;

#define int long long int
vector<int>super_lucky;

void generate_permutations(int n, int fours, int sevens) {
  if(n > 1e10) return;
  
  if(fours == sevens)
    super_lucky.push_back(n);
  
  generate_permutations(n * 10 + 4, fours + 1, sevens);
  generate_permutations(n * 10 + 7, fours, sevens + 1);
  
}

signed main()
{
    generate_permutations(4,1,0);
    generate_permutations(7,0,1);
    sort(super_lucky.begin(), super_lucky.end());
    int n; 
    cin >> n;
    cout << *(lower_bound(super_lucky.begin(), super_lucky.end(), n));
}

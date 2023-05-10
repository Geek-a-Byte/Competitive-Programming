// https://stackoverflow.com/questions/32014460/how-can-i-solve-codeforces-121a
#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long int
vector<int>lucky;

void generate_permutations(int n, int fours, int sevens) {
if(n > 1e10) return;

  lucky.push_back(n);

  generate_permutations(n * 10 + 4, fours + 1, sevens);
  generate_permutations(n * 10 + 7, fours, sevens + 1);

}

// Suppose x is the first lucky number which is >=l and <=r. So x will be the next() value for all numbers in range [l,x]. We have x-l+1 such numbers and they will add (x-l+1)*x to sum. After we add this to the sum, x now becomes new l. Continue this process until x>r at which point we add (r-l+1)*x to sum

int Sum(int l, int r){
    int sum=0;

    for(int i=0; i < lucky.size(); i++){

        int x=lucky[i];

        if(x>=l && x<=r) {
            sum+=(x-l+1)*x;
            l=x+1;
        }

        else if(x>=l && x>r) {
            sum+=(r-l+1)*x;
            break;
        }
    }
    return sum;
}

signed main()
{
    generate_permutations(4,1,0);
    generate_permutations(7,0,1);
    sort(lucky.begin(), lucky.end());

    int l,r;
    cin >> l >> r;
    cout<<Sum(l,r);

}

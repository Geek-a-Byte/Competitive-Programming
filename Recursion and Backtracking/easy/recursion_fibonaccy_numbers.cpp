//approach 1
#include <bits/stdc++.h>
using namespace std;
#define int long long int

int fib(int n) {
        // fib -> 1 1 2 3 5
        // pos -> 1 2 3 4 5
        int n1 =0;
        int n2 =1;
        while(n--){
            int n3 = n1+n2; 
            n1 = n2; 
            n2 = n3; 
        }
        return n1;
}

signed main()
{
   int n;
   cin>>n;
   cout<<fib(n); 
}

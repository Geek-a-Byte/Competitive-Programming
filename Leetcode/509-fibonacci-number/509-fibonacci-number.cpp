class Solution {
    int dp[35]={-1};
public:
    int fib(int n) {
        // fib -> 1 1 2 3 5
        // pos -> 1 2 3 4 5
        int n1 =0;
        int n2 =1;
        int cnt = 0;
        while(cnt < n){
            int n3 = n1+n2; 
            n1 = n2; 
            n2 = n3; 
            cnt++;
        }
        return n1;
    }
};
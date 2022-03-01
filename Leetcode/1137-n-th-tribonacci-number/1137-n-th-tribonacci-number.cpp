class Solution {
    long long int dp[40]={-1};
public:
long long int tribonacci(int n) {
        long long int n1 =0;
        long long int n2 =1;
        long long int n3 =1;
        int cnt = 0;
        while(cnt < n){
            long long int n4 = n1+n2+n3; 
            n1 = n2; 
            n2 = n3;
            n3 = n4;
            cnt++;
        }
        return n1;
    }
};
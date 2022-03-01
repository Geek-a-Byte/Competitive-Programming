#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define IO read write
#define N 32000000
#define int unsigned long long
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}
int a[N];
vector<int>p;

void sieve()
{
    for(int i=2;i<=sqrt(N);i++)
    {
        if(a[i]==0){
            for(int j=i+i;j<=N;j+=i)
            {
                if(a[j]==0) a[j]=i;
            }
        }
    }
}

void sieve2()
{
    int i,j;
    for(i=4;i<N;i+=2)
        a[i] = 1;
    for(i=3;i<=sqrt(N);i+=2)
    {
        for(j=i*i;j<N;j+=(2*i))
        {
            a[j] = 1;
        }
    }
    for(i=2;i<=N;i++)
    {
        if(a[i]==0)
        {
            p.push_back(i);
            // cout<<i<<endl;
        }
    }
}

void primeFact(int n)
{
    cout<<"1";
    while(n>1)
    {
        int f=a[n];
        while(n%f==0)
        {
            cout<<" x "<<f;
            n/=f;
        }
    }
    cout<<endl;
}

int NOD(int n)
{
    int nod=1;
    while(n>1)
    {
        int cnt=0;
        int f=a[n];
        while(n%f==0)
        {
            n/=f;
            cnt++;
        }
        nod*=(cnt+1);
    }
    return nod;
}

//10^9 er jonno code
void countDivisor(int n) {
  int divisor = 1;
  int k=0;
  for (int j = p[k]; j * j <= n ; j=p[++k]) {
      int flag=0;
      int cnt = 1;
      while (n % j == 0) {
        flag=1;
        n /= j;
        cnt++;
      }
      if(flag==1) cout<<j<<"^"<<cnt-1<<" ";
      divisor *= cnt;
    }
    if(n!=1)
    {
        cout<<n<<"^1";
        divisor*=2;
    }
    cout<<endl;
}

signed main()
{
    sieve2();
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        countDivisor(n);
    }
}
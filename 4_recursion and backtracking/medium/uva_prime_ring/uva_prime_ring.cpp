#include <bits/stdc++.h>
#define int long long int

using namespace std;

int cnt_num=0;
int n;
vector<int>sequence;
map<int,int>vis;

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}


void print_prime_ring(int ager)
{
    if(cnt_num==n)
    {
        if(isPrime(ager+1))
        {
            for(int i=0;i<sequence.size()-1;i++)
            {
                cout<<sequence[i]<<" ";
            }
            cout<<sequence[sequence.size()-1];
            cout<<"\n";
        }
        return;
    }
    else if(ager==0)
    {
        sequence.push_back(1);
        cnt_num++;
        print_prime_ring(1);
        cnt_num--;
        sequence.pop_back();
    }
    else
    {
        for(int i=2;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(isPrime(i+ager))
                {
                    vis[i]=1;
                    sequence.push_back(i);
                    cnt_num++;
                    print_prime_ring(i);
                    vis[i]=0;
                    cnt_num--;
                    sequence.pop_back();
                }
            }
        }
    }
}
signed main()
{
   int cas=1;
   while(cin>>n){
        if(cas>1) cout<<endl;
        cout<<"Case "<<cas++<<":\n";
        print_prime_ring(0);
        
   }
   return 0;
}

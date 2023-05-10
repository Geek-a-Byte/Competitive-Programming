#include<iostream>
#include<bitset>
using namespace std;
bitset<1001>bs[10010]; // number of bits depends on n
signed main()
{
    int n;
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
    {
        int s;
        scanf("%d",&s);

        for(int i=1;i<=s;i++)
        {
            int x;
            scanf("%d",&x);
            bs[x].set(j);
        }
    }
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int i,j;
        scanf("%d%d",&i,&j);
        if((bs[i]&bs[j]).count())
        {
            printf("Yes\n");
        }
        else printf("No\n");
    }

}

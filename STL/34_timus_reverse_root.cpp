#include<bits/stdc++.h>
using namespace std;

double a[256*1048];

int main()
{
    double d;
    int i=0;
    while(scanf("%lf", &d)!=EOF)
    {
        double square_root=sqrt(d);
        a[i++]=square_root;
    }
    i--;
    for(;i>=0;i--)
    {
        printf("%.4lf\n",a[i]);
    }
}
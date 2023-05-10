#include<bits/stdc++.h>
using namespace std;
 
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define int long long
#define sq(x) ((x)*(x))
#define pii pair<int,int>
 
class Point{
    public:
    int x,y;
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};
vector<Point>v;
int area()
{
    int sum=0;
    int x=v[0].x;
    int y=v[0].y;
    for(auto i=1;i<v.size();i++)
    {
        //((y1+y2)*(x2-x1))/2;
        int a_sum_b=v[i].y+y;
        int h=x-v[i].x;
        sum+=(a_sum_b*h);
        x=v[i].x;
        y=v[i].y;
    }
    int a_sum_b=v[0].y+y;
    int h=x-v[0].x;
    sum+=(a_sum_b*h);
    return sum;
}
signed main()
{
    fast;
    int t;
    int n;
    cin>>t;
    n=t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Point A(x,y);
        v.push_back(A);
    }
    cout<<abs(area())<<endl;
}
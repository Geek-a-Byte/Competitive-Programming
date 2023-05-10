#include<bits/stdc++.h>
using namespace std;
 
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define int long long int
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
int crossProduct(Point a, Point b, Point c)
{
    return ((a.x-b.x)*(c.y-b.y))-((a.y-b.y)*(c.x-b.x)); 
}
int locate(Point p, Point q, Point r)
{
    if(crossProduct(p,r,q)==0) return 0;
    else if(crossProduct(p,r,q)<0) return 1; //ccw
    else return 2; //cw
} 

signed main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Point A(x1,y1);
        Point B(x2,y2);
        Point C(x3,y3);
        if(locate(A,C,B)==0) cout<<"TOUCH\n";
        else if(locate(A,C,B)==1) cout<<"LEFT\n";
        else if(locate(A,C,B)==2) cout<<"RIGHT\n";
    }
}
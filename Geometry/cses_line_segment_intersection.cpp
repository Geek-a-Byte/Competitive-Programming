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
int orientation(Point p, Point q, Point r)
{
    if(crossProduct(p,r,q)==0) return 0;
    else if(crossProduct(p,r,q)<0) return 1; //ccw
    else return 2; //cw
} 
// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	return true;

	return false;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	// Find the four orientations needed for general and
	// special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case
	if (o1 != o2 && o3 != o4) return true;

	// Special Cases
	// p1, q1 and p2 are collinear and p2 lies on segment p1q1
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and q2 are collinear and q2 lies on segment p1q1
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are collinear and p1 lies on segment p2q2
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are collinear and q1 lies on segment p2q2
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases
}
signed main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        Point A(x1,y1);
        Point B(x2,y2);
        Point C(x3,y3);
        Point D(x4,y4);
        if(doIntersect(A,B,C,D)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
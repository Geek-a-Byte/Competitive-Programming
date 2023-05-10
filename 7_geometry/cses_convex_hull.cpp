#include<bits/stdc++.h>
using namespace std;
 
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define int long long int
#define sq(x) ((x)*(x))
#define pii pair<int,int>
 
struct point{
    int x,y;
}typedef pt;
int n; //number of given points
 
// true -  "first" arg should be placed before “second” arg
// false - "second" arg should be placed before "first" arg
bool comp(pt& a, pt& b) {
    // sort points by x-axis, and by the y-axis when there's a tie.
    if(a.x<b.x) return true;
    if(a.x==b.x and a.y<b.y) return true;
    return false;
}
int crossProduct(pt& a, pt& b, pt& c)
{
    return ((a.x-b.x)*(c.y-b.y))-((a.y-b.y)*(c.x-b.x)); 
}
bool isClockWiseMovement(pt& a, pt& b, pt& c)
{
    return crossProduct(a,b,c)>0;
}
 
vector<pt> getPointsOfLowerHull(vector<pt>& p){
    vector<pt>s;
    for(int i=0;i<n;i++)
    {
        while(s.size()>1 and isClockWiseMovement(s[s.size()-2],s.back(),p[i])){
            s.pop_back();
        }
        s.push_back(p[i]);
    }
    return s;
}
vector<pt> getPointsOfUpperHull(vector<pt>& p){
    vector<pt>s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.size()>1 and isClockWiseMovement(s[s.size()-2],s.back(),p[i])){
            s.pop_back();
        }
        s.push_back(p[i]);
    }
    return s;
}
vector<pt> getUniquePoints(vector<pt>& l, vector<pt>& u)
{  
   set<pii>visited;
   vector<pt>ans;
   for(auto &i:l)
   {
       auto [x,y]=i;
       pii pr={x,y};
       if(visited.find(pr)!=visited.end()) continue;
       ans.push_back(i);
       visited.insert(pr);
   }
   for(auto &i:u)
   {
       auto [x,y]=i;
       pii pr={x,y};
       if(visited.find(pr)!=visited.end()) continue;
       ans.push_back(i);
       visited.insert(pr);
   }
   return ans;
}
vector<pt> getConvexHull(vector<pt>& p){
    if(p.size()==1) return p;
    sort(p.begin(), p.end(),comp); //sorting the rest of the points in increasing order of slope
    auto lowerHullPoints = getPointsOfLowerHull(p);
    auto upperHullPoints = getPointsOfUpperHull(p);
    return getUniquePoints(lowerHullPoints,upperHullPoints);
}
signed main()
{
    fast;
    while(cin>>n){
        if(n==0) break;
        vector<pt>p(n);
        for(auto &i:p)
        {
            cin>>i.x>>i.y;
        }
        vector<pt>ans=getConvexHull(p);
        cout<<ans.size()<<endl;
        for(auto &i:ans)
        {
           cout<<i.x<<" "<<i.y<<endl;
        }
    }
}
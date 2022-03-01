#include <iostream>
using namespace std;
int k;
void findPermutations(string str, int l, int r){
    // cout<<str<<l<<endl;
    if(k==0)
    {
      return;
    }
   if (l == r)
    {
      k--;
      cout<<str<<endl;
      return;
    }
   else{
      for (int i = l; i<=r; i++){
         swap(str[l], str[i]);
         findPermutations(str,l+1,r);
      }
   }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    for(int i=0; i < t; i++){
   string str="";
   int n;
   cin>>n>>k;
   for(int i=0;i<n;i++)
   {
      str+= (char)i+65;
   }
   cout<<"Case "<<i+1<<":\n";
   findPermutations(str, 0, n-1);
}
   return 0;
}
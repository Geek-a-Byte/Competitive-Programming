#include<bits/stdc++.h>
using namespace std;

void toh(int disks,char r1,char r3,char r2)
{
    if(disks==0)
    {
        return;
    }
    toh(disks-1,r1,r2,r3);
    cout<<"Disk "<<disks<<" moved from "<<r1<<" to "<<r3<<endl;
    toh(disks-1,r2,r3,r1);
}
int main()
{
    int n;
    cin>>n;
    toh(n,'A','C','B');
}

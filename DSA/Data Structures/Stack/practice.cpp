#include <iostream>
#include<stdio.h>
#include <stack>
using namespace std;
int main( )
{
    stack <int> s;  // declaration of stack

    int n;
    cin>>n;
    
    
    for(int i = 0;i < n; i++)
    {
     int opt;
    
    scanf("%d",&opt);
    if(opt==1)
    {
        int x;
        scanf("%d",&x);
        s.push(x);
    }
    else if(opt==2)
    {
        s.pop();
    }
    else if(opt==3)
    {
        int max=s.top();
        for(int j=0;j<s.size()-1;j++)
        {
            s.pop();
            if(s.top()>max && !s.empty())
            {
                max=s.top();
            }
        }
        cout<<max<<endl;
    }
    }  

    


    return 0;

}
/*44
44
1
1
3
29
51
51
51*/
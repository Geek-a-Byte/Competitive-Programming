#include<iostream>
#include<cstring>
using namespace std;

void selection_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
          swap(a[i],a[min]);
        
    }
}

int main()
{
    string s;
    cin>>s;
    int a[100];
    int j=0;
    for(int i=0;s[i]!='\0';i++)
    {

        if(s[i]!='+')
        {
           a[j]=s[i]-'0';
           j++;
        }
    }

    selection_sort(a,j);
    
  
    int k=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='+')
        {
           cout<<a[k];
           k++;
        }
        else
        {
            cout<<'+';
        }
    }
        


}
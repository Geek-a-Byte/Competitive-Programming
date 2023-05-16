#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, string s1, string s2, vector<vector<int>>& dp)
{
    if(i==0 or j==0)
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if(s1[i-1]==s2[j-1])
	{
		return dp[i][j]=1+f(i-1, j-1, s1, s2, dp);
	}
	return dp[i][j]=max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
}


int lcs(string s, string t)
{
	int n=s.length();
	int m=t.length();
	vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int i=n;
	int j=m;
	string ss="";
	while(i>0 and j>0)
	{
       if(s[i-1]==t[j-1])
	   {
		   ss+=s[i-1]; 
		   i--;
		   j--;
	   }
	   else if(dp[i-1][j]>dp[i][j-1])
	   {
		   i--;
	   }
	   else
	   {
		   j--;
	   }
	}
	reverse(ss.begin(),ss.end());
	cout<<ss<<endl;
	return dp[n][m];
}
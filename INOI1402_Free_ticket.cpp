#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
const int M=1e8;
int w[N][N];
int dp[N][N];
void floyd(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);

                }
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=2*M;
        }
    }
    int m,l,k;
    for(int i=1;i<=e;i++)
    {
        cin>>m>>l;
        cin>>k;
        dp[m][l]=k;
        dp[l][m]=k;
    }
    floyd(n);
    int ans=-2*M;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i][j]!=(2*M))
            {
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans;
    return 0;
}

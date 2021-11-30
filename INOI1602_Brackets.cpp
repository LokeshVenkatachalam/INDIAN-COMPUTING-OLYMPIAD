#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;

int a[N];
int b[N];
int dp[N][N];
int main()
{
    int inf=1e6+6;
    int n;
    int k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        if(b[i]==(b[i+1]-k))
        {
            dp[i][i+1]=a[i]+a[i+1];
        }
        else
        {
            dp[i][i+1]=0;
        }
    }
    int j;
    for(int ct=2;ct<n;ct++)
    {
        for(int i=1;i<=(n-ct);i++)
        {
            j=i+ct;
            if(b[i]==(b[j]-k))
            {
                  dp[i][j]=dp[i+1][j-1]+a[i]+a[j];
            }
            for(int k=i;k<(j);k++)
            {
                  dp[i][j]=max(dp[i][j],(dp[i][k]+dp[k+1][j]));
            }

        }
    }
    cout<<dp[1][n];
    return 0;
}

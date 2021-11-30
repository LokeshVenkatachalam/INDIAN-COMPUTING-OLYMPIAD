#include<bits/stdc++.h>
using namespace std;
const int N=320;
bool a[N][N];
int dp[N][N][N][2]={};
int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>a[i][j];
        }
    }


    for(int i=0;i<=d;i++)
    {
         dp[n][m][i][1]=1;
         dp[n][m][i][0]=1;
    }



    for(int i=n;i>0;i--)
    {
        for(int j=m;j>0;j--)
        {
            if((i==n)&&(j==m))
            {
                continue;
            }

            if(a[i][j])
            {
                dp[i][j][d][0] = dp[i+1][j][1][1];
                dp[i][j][d][1] = dp[i][j+1][1][0];
                for(int k=0;k<d;k++)
                {
                    dp[i][j][k][1]=(dp[i][j+1][1][0]+dp[i+1][j][k+1][1])%20011;
                    dp[i][j][k][0]=(dp[i][j+1][k+1][0]+dp[i+1][j][1][1])%20011;
                }
            }
        }
    }
    int ans;
    ans=dp[1][1][0][0]%20011;
    cout<<ans;
    return 0;
}

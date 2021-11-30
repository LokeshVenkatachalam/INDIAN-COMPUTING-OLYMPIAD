//calvins game sucees
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N];
int dp1[N];
int dp[N];
int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0]=0;
    dp[1]=a[1];
    dp[2]=a[1]+a[2];
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2])+a[i];
    }
    dp1[x]=a[x];
    dp1[x+1]=a[x]+a[x+1];
    for(int i=(x+2);i<=n;i++)
    {
        dp1[i]=max(dp1[i-1],dp1[i-2])+a[i];
    }
    int ans=-2*10000000;
    for(int i=x;i<=n;i++)
    {
        ans=max(ans,dp[i]+dp1[i]-a[i]-a[x]);
    }

    cout<<ans;
    return 0;
}

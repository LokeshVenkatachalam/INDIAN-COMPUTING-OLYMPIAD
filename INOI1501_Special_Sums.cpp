#include<bits/stdc++.h>
using namespace std;
int const N=1e6+6;
long long int a[N];
long long int b[N];
long long int dp[N];
long long int s[N];
//inoi special sum suceess;

int main()
{   const long long int r=1e18;
    long long int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    b[0]=0;
    s[1]=b[1];
    for(int i=2;i<=n;i++)
    {
        s[i]=s[i-1]+b[i];
    }
    s[0]=0;
    long long int maxi=-r;
    for(int i=1;i<=n;i++)
    {
        maxi=max(maxi,a[i]-s[i]);
        dp[i]=maxi;
    }
    long long int ans=-r;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,a[i]+s[i-1]+dp[i-1]);
        ans=max(ans,a[i]);
    }

    maxi=-r;
    for(int i=1;i<=n;i++)
    {
        maxi=max(maxi,a[i]+s[i-1]);
        dp[i]=maxi;
    }

    for(int i=2;i<=n;i++)
    {
        ans=max(ans,s[n]+a[i]-s[i]+dp[i-1]);

    }
    cout<<ans;
    return 0;
}

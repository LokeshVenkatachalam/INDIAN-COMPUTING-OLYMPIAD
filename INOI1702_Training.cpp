#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N=(5*(1e3))+5;
ll ex[N];
ll st[N];
ll dp[N][N];
ll suf[N];
ll sqube(ll i)
{
	ll ans=0;
	while(i>0)
	{
		ans+=i%10;
		i=i/10;
	}
	return(ans*ans*ans);
}
int main()
{
	ll n;
	cin>>n>>st[0];
	for(ll i=1;i<=n;i++)
	{
		cin>>ex[i];
		st[i]=st[i-1]+sqube(st[i-1]);
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<i;j++)
		{
			dp[i][j]=max(dp[i-1][j]+st[j]*ex[i],dp[i-1][j-1]);
		}
		dp[i][0]=dp[i-1][0]+st[0]*ex[i];
	}
	ll ans=0;
	for(ll i=n;i>=0;i--)
	{
		for(ll j=i;j>=0;j--)
		{
			ans=max(ans,dp[i][j]+suf[i]*st[j]);
		}
		if(i>0)
		{
			suf[i-1]=suf[i]+ex[i];
		}
	}
	cout<<ans<<'\n';
			
}

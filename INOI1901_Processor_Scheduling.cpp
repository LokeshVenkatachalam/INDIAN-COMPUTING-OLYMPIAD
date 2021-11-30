#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll N=5*(1e3+2);
ll a[N];
ll b[N];
ll c[N];
pair<ll,ll> d[N];
ll dp[N][N];
ll suf[N];
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		for(ll i=1;i<=n;i++)
			cin>>a[i];
		suf[n+1]=0;
		for(ll i=n;i>0;i--)
			suf[i]=suf[i+1]+a[i];
		for(ll i=1;i<=m;i++)
			cin>>b[i];
		for(ll i=1;i<=m;i++)
			cin>>c[i];
		for(ll i=1;i<=m;i++)
			d[i]=make_pair(c[i],b[i]);
		sort(c+1,c+m+1);
		sort(d+1,d+m+1);
		for(ll i=1;i<=m;i++)
			b[i]=d[i].second;
		for(ll i=1;i<=n;i++)
			dp[0][i]=dp[0][i-1]+a[i];
		for(ll i=1;i<=m;i++)
		{
			if((dp[i-1][0]<c[i])&&(dp[i-1][0]!=-1))
				dp[i][0]=max(b[i]+dp[i-1][0],c[i]);
			else
				dp[i][0]=-1;
		}
		for(ll i=1;i<=m;i++)
		{
			for(ll j=1;j<=n;j++)
			{   
				ll ans=1000000000000000000;
				ll ct=0;
				if(dp[i-1][j]!=-1)
				{
					if(dp[i-1][j]<c[i])
						ans=min(ans,max(dp[i-1][j]+b[i],c[i]));
					else
						ct++;
				}
				else
					ct++;
				if(dp[i][j-1]!=-1)
					ans=min(ans,dp[i][j-1]+a[j]);
				else
					ct++;
				if(ct==2)
					dp[i][j]=-1;
				else
					dp[i][j]=ans;
			}
			for(ll j=1;j<=m;j++)
			{
			    if(dp[i][j]!=-1)
			    	dp[i][j]=max(dp[i][j],c[i]);
			}
		}
		ll ans1=1000000000000000000;
		ll ct1=-1;
		for(ll i=0;i<=n;i++)
		{
			if(dp[m][i]!=-1)
			{
				ct1=1;
				ans1=min(dp[m][i]+suf[i+1],ans1);
			}	
		}
		if(ct1==-1)
			cout<<-1<<'\n';
		else
			cout<<ans1<<'\n';
		for(ll i=0;i<=m;i++)
		{
			b[i]=0;
			c[i]=0;
			d[i]=make_pair(0,0);
		}
		for(ll i=0;i<=n+1;i++)
		{
			a[i]=0;
			suf[i]=0;
		}
		for(ll i=0;i<=m;i++)
		{
			for(ll j=0;j<=n;j++)
				dp[i][j]=0;
		}
		n=0;
		m=0;
		ct1=0;
		ans1=0;
	}
}

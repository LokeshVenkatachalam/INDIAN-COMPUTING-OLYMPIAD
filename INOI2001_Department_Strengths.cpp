#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll  N= 1e6+10;

vector<ll> ch[N];
ll vis[N];
ll vis1[N];

ll ct=0;
ll min1=1e9+10;
ll max1=0;

vector<ll> max2;
vector<ll> min2;
ll level[N]; 

//To find no of elements;

void dfs(ll a)
{
	vis[a]=1;
	ct++;
	min1=min(min1,a);
	max1=max(max1,a);
	for(ll i=0;i<ch[a].size();i++)
	{
		if(vis[ch[a][i]]==0)
		{
			dfs(ch[a][i]);
		}
	}
}

//TO find level of odd sized trees and store it as + levels

void dfs1(ll b)
{
	vis1[b]=1;
	for(ll i=0;i<ch[b].size();i++)
	{
		if(vis1[ch[b][i]]==0)
		{
			level[ch[b][i]]=level[b]+1;
			dfs1(ch[b][i]);
		}
	}

}

//TO find level of even sized trees and store it as - levels

void dfs2(ll b)
{
	vis1[b]=1;
	for(ll i=0;i<ch[b].size();i++)
	{
		if(vis1[ch[b][i]]==0)
		{
			level[ch[b][i]]=level[b]-1;
			dfs2(ch[b][i]);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;

		for(ll i=1;i<=m;i++)
		{
			ll a,b;
			cin>>a>>b;
			ch[a].push_back(b);
			ch[b].push_back(a);
		}

		for(ll i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				ct=0;
				min1=1e9+10;
				max1=0;
				dfs(i);
				if((ct%2)==1)
				{
					max2.push_back(max1);
				}
				else
				{
					min2.push_back(min1);
				}
			}
		}



		for(ll i=0;i<max2.size();i++)
		{
			level[max2[i]]=1;
			dfs1(max2[i]);
		}



		for(ll i=0;i<min2.size();i++)
		{
			level[min2[i]]=-1;
			dfs2(min2[i]);
		}



		ll ans1=0;
		ll ans2=0;


		for(ll i=1;i<=n;i++)
		{
			if(level[i]>0)
			{
				ans1+=level[i];
			}
			else
			{
				ans2=ans2-level[i];
				
			}
		}

		cout<<ans2<<" "<<ans1<<'\n';
		
		for(ll i=0;i<=n;i++)
		{
			vis[i]=0;
			vis1[i]=0;
			level[i]=0;
			ch[i].clear();
		}
		ct=0;
		max1=0;
		ans1=0;
		ans2=0;
		max2.clear();
		min2.clear();
		min1=1e9+19;
	}
}

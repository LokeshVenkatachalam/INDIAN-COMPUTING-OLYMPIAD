    #include "bits/stdc++.h"
    using namespace std;
    typedef long long ll;
    const ll N=1e6+10;
    vector<ll> ch[N];
    ll vis[N];
    ll a[N];
    ll ans1[N];
    ll dfs(ll src)
    {
    	ll ans=0;
    	vis[src]=1;
    	for(ll i=0;i<ch[src].size();i++)
    	{
    		if(vis[ch[src][i]]==0)
    		{
    			ans+=dfs(ch[src][i]);
    			vis[ch[src][i]]=1;
    		}
    	}
    	ans+=a[src];
    	return ans;
    }
    int main()
    {
    	std::ios::sync_with_stdio(false);
    	ll t;
    	cin>>t;
    	while(t--)
    	{
    		ll n,m,k;
    		cin>>n>>m>>k;
    		for(ll i=0;i<m;i++)
    		{
    			int x,y;
    			cin>>x>>y;
    			ch[x].push_back(y);
    			ch[y].push_back(x);
    		}
    		for(ll i=1;i<=n;i++)
    		{
    			cin>>a[i];
    		}
    	    ll j=0;
    	    for(ll i=1;i<=n;i++)
    	    {   
    		    if(vis[i]==0)
    	    	{
        			ans1[j]=(dfs(i));
        			j++;
        		}
        		else
        		{
     
        		}
        	}
        	ll ans2=0;
        	sort(ans1,ans1+j);
        	if(k>j)
        	{
        		cout<<-1<<'\n';
        	}
        	else
        	{
        		for(int i=0;i<(k/2);i++)
        		{
        		    ans2+=ans1[i];
        		}
        		for(int i=0;i<(k+1)/2;i++)
        		{
        		    ans2+=ans1[j-1-i];
        		}
        		cout<<ans2<<'\n';
        	}
        	for(ll i=0;i<=n;i++)
        	{
        	    ch[i].clear();
        	    vis[i]=0;
        	    ans1[i]=0;
        	    a[i]=0;
        	}
        }
        return 0;
    } 

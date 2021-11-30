#include<bits/stdc++.h>
using namespace std;
set<pair<long long int,long long int> >s;
set<pair<long long int,long long int> >p;
long long int dfs(pair<long long int,long long int>v)
{
    long long int ans=0;
    if(!s.count(v))
    {
        s.insert(v);
        long long int ans=0;
        long long int a=v.first;
        long long int b=v.second;
        long long int c=4;
        if(p.count(make_pair(a,b-1)))
        {
            c--;
            ans+=dfs(make_pair(a,b-1));
        }
        if(p.count(make_pair(a,b+1)))
        {
            c--;
            ans+=dfs(make_pair(a,b+1));
        }
        if(p.count(make_pair(a+1,b)))
        {
            c--;
            ans+=dfs(make_pair(a+1,b));
        }
        if(p.count(make_pair(a-1,b)))
        {
            c--;
            ans+=dfs(make_pair(a-1,b));
        }
        ans+=c;
        return ans;
    }
    else
    {
        ans=0;
        return ans;
    }
}
int main()
{
    long long int r,c,n;
    cin>>r>>c>>n;
    long long int maxi=0;
    for(long long int i=1;i<=n;i++)
    {
        long long int e,f;
        cin>>e>>f;
        p.insert(make_pair(e,f));
    }
    long long int m;
    set<pair<long long int,long long int> >::iterator it;
    for(it=p.begin();it!=p.end();it++)
    {
        m=dfs(*it);
        maxi=max(m,maxi);
    }
    cout<<maxi;
    return 0;
}

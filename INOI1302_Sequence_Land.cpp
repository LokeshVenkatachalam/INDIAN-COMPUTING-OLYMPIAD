#include<bits/stdc++.h>
using namespace std;
const int N=350;
vector<int> a[N];
int w[N][N];
int vis[N];
set<int>s;
void dfs(int u,int n)
{
    vis[u]=1;
    for(int i=1;i<=n;i++)
    {
        if((w[u][i]==1)&&(vis[i]!=1))
            {
                vis[i]=1;
                dfs(i,n);
            }
    }
}
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int g,l,f,ans;
    ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>g;
        for(int j=1;j<=g;j++)
        {
            cin>>l;
            a[i].push_back(l);
        }

    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
          s.insert(a[i][j]);
        }
        for(int j=(i+1);j<=n;j++)
        {
            for(int t=0;t<a[j].size();t++)
            {
                if(s.count(a[j][t])==1)
                {
                    f++;
                }
            }
            if(f>=k)
            {
                w[i][j]=1;
                w[j][i]=1;
            }
            f=0;
        }
        s.clear();

    }
    dfs(1,n);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;

}

#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int vis[N];
vector<int> ch[N];
void dfs(int u)
{
    for(int i=0;i<(ch[u].size());i++)
    {   int v=ch[u][i];
        if(vis[v]==0)
        {
            vis[v]=1;
            dfs(v);
        }
    }
}
int main()
{
    return 0;
}

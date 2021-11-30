//INOI TEREE SUCEESSSSS
//SUCEESS
#include<bits/stdc++.h>
using namespace std;
const int X=1e5+100;
int a[X];
int b[X];
int c[X];
vector<int> GH[X];
void dfs(int u)
{
    c[u]=a[u];
    for(int i=0;i<GH[u].size();i++)
    {
        int v=GH[u][i];
        dfs(v);
        c[u]=min(c[u],c[v]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int root=0;
    for(int i=0;i<=n;i++)
    {
        if(b[i]==-1)
            root=i;
        else
            GH[b[i]].push_back(i);
    }
    dfs(root);
    int output=-2*1000000000;
    for(int i=1;i<=n;i++)
    {
        output=max(output,(a[i]-c[i]));
    }
    cout<<output;
    return 0;
}

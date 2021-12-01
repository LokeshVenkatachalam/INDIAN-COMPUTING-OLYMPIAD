#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
queue<int> q;
int vis[N];
vector<int> ch[N];
void bfs (int u)
{ q.push(u);
  vis[u]=1;
  while(!q.empty())
  {
      int j=q.front();
      q.pop();
      for(int i=0;i<ch[j].size();i++)
      {
          int v=ch[u][i];
          if(vis[v]==0)
          {
              vis[v]==1;
              q.push(v);
          }
          else{}
      }
  }

}
int main()
{
    return 0;
}

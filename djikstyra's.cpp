#include<bits/stdc++.h>
using namespace std;
const int N=(4*(1e4))/2;
set<pair<int,int> >s;
vector<int> c[N];
int cost[N][N];
int dist[N];

void djista(int src)
{
    memset(dist,63,sizeof(dist));
    s.insert(make_pair(0,src));
    while(s.size()>0)
    {
        int d=s.begin()->first;
        int h=s.begin()->second;
        s.erase(s.begin());
        for(int i=0;i<c[h].size();i++)
        {
            int v=c[h][i];
            if(dist[v]>(d+cost[h][i]))
            {
                if(s.count(make_pair(dist[v],v)))
                {
                    s.erase(make_pair(dist[v],v));
                }
                dist[v]=d+cost[h][i];
                s.insert(make_pair(dist[v],v));

            }
        }
    }
}
int main()
{
    return 0;
}
void dji(int src)
{
    memset(dist,63,sizeof(dist));
s.insert(make_pair(0,src));
while(s.size()>0)
{
  int d=s.begin()->first;
  int h=s.begin()->second;
  s.erase(s.begin());
 for(int i=0;i<c[h].size();i++)
{
   v=c[h][i];
   if(dist[v]>d+cost[h][i])
{
 if( s.cout(make_pair(dist[v],v)))
{
 s.erase(make_pair(dist[v],v));
}
dist[v]=d+cost[h][i];
s.insert(make_pair(dist[v],v);
}
}
}
}
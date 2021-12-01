# GRAPHS


## Definitions

### Node

A node is vertex which represnt some location/point

Usually used as point in 2d graph,some physical places ,etc

### edges

a line/path connecting two nodes , can be directed or undirected

usually tells there is [path between node A and Node B, A-B](undirected) or [path from node A to B, A->B](directed)

edges can be weighted


### Graph
A graph(G) is represented by 
```
    A set of nodes
    A set of edges(directed or undirected)

```

### Tree

A tree is for a  undirected graph with no cycles,where all nodes are connected 

There exist only one path between two given nodes

Properties: If there are 'N' nodes,there will exactly 'N-1' edges

## Algorithms 

We discuss three algorithms here 

Depth First Search (DFS)     --> travelling the graph depth wise node

Breadth First Search (BFS)   --> travelling the graph breath(level ) wise from the root node

Floyd warshall               --> Shortest path between all nodes

Djisktra's shortest          --> Shortest path from a given node to reach other nodes

## How are graphs represented in C++

There a two ways primarly 

### 1) Adjacency Matrix

1.) We have a 2d array of size N*N

2.) We store weights/path exist between node 'i' and node 'j' in adj[i][j]
```
incase of weighted graph ,weight is stored,if no connection then -1 is stored

incase normal graph 1->edge exist , (0 or -1)->edge doesnt exist
```
### 1) Adjacency list

1.) We have a array of vectors ,like 

```c++
std::vector<int> adj[N]
```

2.) We insert j in adj[i] if there is edge from i to j
```c++
adj[i].push_back(j);//if i->j exists
```

3.)Incase of weighted graph ,weight is stored as pair or in another vector

## DFS

1.) We have root node, We have visited array vis[i], vis[i]=0 --> not visited ,vis[i]=1 -->visited

2.) now we take the root node ,go through all its adjacent nodes

3.)if a node is unvisited ,then we call DFS with than unvisted node as root, and make visited of that node =1 

4.) We do this for all children for given root node

5.)so this goes on recursively and so all connected node to intially given root node is visted

6.)This is called depth for search because as soon as we visit an unvisited node ,we go and visit all nodes in its sub tree and then only go and see nodes in same level

### CODE:
```c++
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int vis[N];        //visited array
vector<int> ch[N]; //adjacency list
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
```
## BFS

1.) Here we visit nodes by their level

2.) We start with the given root node

3.) visit all its adjancent nodes and then add its children(adjancent nodes not visted) to queue in the order of visting, and mark them visited

4.) take(and then POP) the frontmost node in the queue and consider it as root and perform Step 3

5.) here we can store level using level[node_i]=level[node_i_parent]+1

### Code

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
queue<int> q;
int vis[N];       //visited array
vector<int> ch[N];//adjacency list
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
```
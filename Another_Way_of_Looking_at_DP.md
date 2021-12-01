# DYNAMIC PROGRAMMING

## SHORTEST PATH IN DAG

### PROBLEM:
	
	Given a directed acyclic graph,find the shortest path to all other nodes from a source



#### TOPOLOGICAL SORT

	IN A DAG(directed acyclic graph), linealry order all the nodes in such a way if a there is a directed edge from u to v, u is before v in the linear order

### Solution
```
	STEP 1: DO a TOPOLOGICAL SORT

	STEP 2: Intialisize =DIST(source)=0,all other DIST(i)= infinity

	STEP 3:For: all V in linear order(after topo sort)
				FOR: all edges ending in v,all (u,v) 
					DIST(i)=min(DIST(i),DIST(u)+len(u,i));

	Reason: Since we go through all nodes in linearised(topo sort) order,
			The DIST(i) will be fixed after iterating over all edges ending at i
			So if we go to node j index[j]>index[i](in the topo order index), and if there exist directed edge from i to j,then we dont have problem of changing DIST(i),since DIST (i) is found before itself

```

### LONGEST PATH IN DAG

	Just chane min to max,in STEP 3,this is possible because it not acyclic



### DYNAMIC PROGRAMMING IS "JUST" a DAG of sub-problems

See in the below example


## LONGEST INCREASING SUBSEQUENCE

### PROBLEM:

	Given a sequence of A[1],A[2],...,A[N];
	Find a longest Subsquence(by length) whose numbers are in increasing order ,if the subsquence is B,then B[i]>B[i-1], for all i 
	SUBSQUENCE:def 1:it is sequnce B=A[i1],A[i2],.......A[ik], where i1<i2<i3<....ik, where k<=N

	So effective GIVEN A=A[1],A[2],.....,A[N];
	FIND B=A[i1],A[i2],...,,A[ik]; where A[i1]<A[i2]<......<A[ik] and i1<i2<......<ik and 0<=k<=N

### Solution
```
	STEP 1:(i)make a node i for every element A[i]
		   (ii) make edges between between node i,j directed from i to j ,with weight "1", if ( (i<j) and (A[i]<A[j]) )
		   (iii) the topo sort of this graph is the orginal intial order 1,2,3,....n
	STEP 2:Now ,do a longest path on DAG to find solution

	OPTIMISATION: In longest path DAG we can just do DIST(i)=(max among all(Dist(i,j)))+1  where i>j
						Since all len are of dist 1
	Reason,we know we want only sequnce of elements whose index are in increasing order,so topo sort possible
		   We know we want only sequence of elemnts where A[i]>A[j], so direction of edge defined
		   Now we do dynammic programming us A longest path DAG

	Earlier Way I Know
	DP[i]-> maximum length of increasing subsquence ending at i
	DP[i]=1+max(all DP[j], where A[i]>A[j],and i>j)
```
```c++
	//So code
	//	intialialize all a[i]=0 for all 1<=i<=n;,let a[0]=1;lets create a imaginary 0'th element whose value is lesser than all other elements
		FOR(i=1;i<=n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(A[i]>A[j])
				{
					DP[i]=max(DP[i],DP[j]+1);
				}
			}
		}
```
So interesting way of understnading DP using longest/shortes path on DAG

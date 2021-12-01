#  Dynamic programming (DP)

Here we use simple DP concept ,This is like finding pattern(smaller problems with same solution)

We usually call a program is DP if it has 
```
1)sub problem with a optimal solution
2)We need Overlapping sub problems to find the overall solution
```

If the sub-problems are not over lapping then they come under 'divide and Conquer'

It should also not have 'GREEDY CHOCICE PROPERTY', then it comes under 'Greedy'

```
GREEDY CHOCICE PROPERTY

    Find single step(first step) which is towards a optimal solution
    this should be provable
```

## Now let us start a basic DP problem

The main things about DP problems is finding 

1.) Finding subproblem
2.) Finding equation/recursion to find solution using sub-problem
3.) Intialisation of starting solution, ex:DP[0] ,etc

### PREFIX(Very useful for DP):

#### PROBLEM
```
Given 'n' unsorted numbers ,indexed from 1
there will be 't' queury
Query will be two numbers 'i','j'

we need find the subarry sum from X=i to X=j in given the array
```

Subarray:  The contiuous array from x=i to x=j

Subarray sum: In an array/vector: a[i]+a[i+1]+......a[j]

#### Contraints
```
1 <= n,t <=1000000
-1e9 <= a[i] <=1e9
```
#### Solution

The obvious solution is given i,j traverse from i to j calculate the sum

This will take Time Complexity--->O(T*N), Space complexity-->O(N) 

The better solution is 

1).Let us define PRE[i]=sum of all a[x] from  X=0 to X=i;

2).The recursion is very simple here PRE[i]=PRE[i-1]+a[i]

3).Given 'i','j' Subarray sum = PRE[j]-PRE[i-1];
```
The reason is

PRE[j]   = a[1]+a[2]........a[i-1]+a[i]+a[i+1].......+a[j]
PRE[i-1] = a[1]+a[2]........a[i-1]

==>PRE[j]-PRE[i-1] = +a[i]+a[i+1].......+a[j]
```


### Example 1:

#### PROBLEM

https://www.codechef.com/INOIPRAC/problems/INOI1301

Calvin starts at pos X

There are 2 Phase

1)First phase  is forward phase  = he can can do zero or more steps---> STEP: he moves forward 1 or 2 steps

2)Second Phase is backward phase = he can can do zero or more steps---> STEP: he can moves backward by 1 or 2 steps

All position he moves ie: a[i] is added to score

The task is find the maximum score that possible to finally reach 0

#### Solution

Our logic is 

1)let Y be position he moves from X froward ,so X<=Y<=N

2) we calculate the score for all possible Y's , X<=Y<=N and then take the maximum score

3) Score of Particular Y= (Highest Score for reaching Y from X) + (Highest Score for reaching 0 from Y)

4) (Reaching 0 from Y) by backward movement is same as (Reaching Y from 0) by forward movement

5) So let us define two DP dp[i]->highest score for reaching i from 0 , dp1[i]->highest score for reaching i from X

6) so subproblem the score of reaching a particular position

7) Now recursion dp[i]=max(dp[i-1],dp[i-2])+a[i], dp1[i]=max(dp1[i-1],dp1[i-2])+a[i]
```
Reason

There are two ways of reaching 'i' jumping from 'i-1' or 'i-2' ,
The highest score among these two are taken 
And a[i] is added because u reach the current possition
```

8) We are initialsing

```c++
//for dp
dp[0]=0;
dp[1]=a[1];
dp[2]=a[1]+a[2];

//for dp1
dp1[x]=a[x];
dp1[x+1]=a[x]+a[x+1];
```
8) now go score of Y = dp[Y]+dp1[Y]-a[Y]-a[X];
```
Reason:

a[Y] is counted twice in dp[Y] and dp1[Y]
a[X] is counted in dp1[Y], it shouldn't be ,but for intialisation purposes we do
```

9) now run a for loop from Y=X from Y<=N, and take maximum score out all scores of Y

```c++
int ans=-2*10000000;
for(int i=x;i<=n;i++)
{
    ans=max(ans,dp[i]+dp1[i]-a[i]-a[x]);
}
```
#### Code

https://github.com/LokeshVenkatachalam/INDIAN-COMPUTING-OLYMPIAD/blob/main/INOI2013_Calvins%20Game.cpp

```c++
//calvins game sucees
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N];
int dp1[N];
int dp[N];
int main()
{
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0]=0;
    dp[1]=a[1];
    dp[2]=a[1]+a[2];
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2])+a[i];
    }
    dp1[x]=a[x];
    dp1[x+1]=a[x]+a[x+1];
    for(int i=(x+2);i<=n;i++)
    {
        dp1[i]=max(dp1[i-1],dp1[i-2])+a[i];
    }
    int ans=-2*10000000;
    for(int i=x;i<=n;i++)
    {
        ans=max(ans,dp[i]+dp1[i]-a[i]-a[x]);
    }

    cout<<ans;
    return 0;
}
```





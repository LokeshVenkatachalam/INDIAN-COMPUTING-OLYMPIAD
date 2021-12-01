# Number theory

## Overview

Number theory is using properties,patterns of integers to solve problem

We will see how to find GCD of two numbers

We also see how nth fibannoci can be found in log N time

## GCD

GCD is greatest common divisor[also known as highest common factor(HCF) ] of a set of numbers

In pen and paper way ,we factorise and the find GCD[HCF]

Here we use Euclid's GCD algorithm

#### Algorithm

Step 1 : FInd max of given two numbers a,b ,Lets take a>b without loss of generality

Step 2 : we are using the fact gcd(a,b)=gcd(b,a%b)--> if a%b !=0 , gcd(a,b)=b-->if a%b =0;

```
gcd(a,b)=gcd(b,a%b) if a%b !=0
gcd(a,b)=b;         if a%b =0;

Second case is obvious 'b' divides 'a' and a>=b

First case a= k*b +a%b 
so we know that GCD divides 'a'      
             ==>GCD divides k*b+ a%b

we also know that GCD divides 'b'
             ==>GCD divides k*b ----> GCD should also divide a%b

if some 'x' divides 'b' and 'a%b'

then b   = k1*x;
     a%b = k2*x    
==>  a   = k*b + a%b = k*k1*x+ k2*x = (k*k1+k2)*x

So from above we can see any factor that divides 'a' and 'b' divides 'a%b', and we also see that there cannot number dividing just 'b' and 'a%b' and not diving 'a'
So the GCD of (b,a%b)= GCD(a,b)
```

##### Time Complexity

It is O(log[min (a, b)])

##### Working Code

```c++
long long int gcd(long long int a,long long int b)
{
    if(a<b)
    {
        long long int x=a;
        a=b;
        b=x;
    }
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}
```








## Fibannoci series

### Problem

F[0]=0;
F[1]=0;
F[n]=F[n-1]+F[n-2];

We need to finf F[n],given n;

#### Simple solution takes more time

This is where we find F[2],F[3],......F[n]
This takes O(N) for finding F[N];

This can be coded in two

Way 1: finding from F[2],.....F[n], for every given n,everytime, but while calculating we just store the previous two F[i]'s.   
```
            This occupies less space O(1) for every given n;
                ==>Space complexity is O(1) for one given 'n', 
            But takes more time for large number of input 
                ==>Time Complexity: t*O(N)
                ==>Space complexity: t*O(1) 
            t->no of test cases
```
Way 2: finding till F[n], for the first given 'n',and then find subsquent F[i], if higher 'n' is given.
```
                ==>Time Complexity: O(N)
                ==>Space complexity O(N)
                where N is the maximum  of given inputs
                better than way 1 for large inputs in Time Complexity, here space complexity depends
```
Way 1 code:
```c++
#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==0)
            cout<<0<<'\n';
        else if(n==1)
            cout<<1<<'\n';
        else
        {
            int x=0;
            int y=1;
            for(int i=2;i<=n;i++)
            {
                int z=x+y //z= F[i],x=F[i-2],y=F[i-1]
                x = y; //updating x to F[i-1] = F[(i+1)-2]
                y = z; //updating y to F[i]   = F[(i+1)-1]
            }
            cout<<y<<'\n';
        }
    }
    return 0;
}
```

Way 2 code:
```c++
#include"bits/stdc++.h"
using namespace std;
int F[1000000];
int main()
{
    int t;
    cin>>t;
    F[0]=0;
    F[1]=1;
    int current_highest =1;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<current_highest)
        {
            for(int i=current_highest+1;i<=n;i++)
            {
                F[i]=F[i-1]+F[i-2];
            }
            current_highest = n;
        }
        cout<<F[n]<<'\n';       
    }
    return 0;
}
```


#### O(LOGN code for each )

We here use matrix multiplication
```
| F[n]   | = |1 1|  | F[n-1] |
| F[n-1] | = |1 0|  | F[n-2] |
```
So we can see that 
```
| F[n]   | = { |1 1| }^ (n-1) | F[1] |
| F[n-1] | = { |1 0| }        | F[0] |
```
```
We can calulate powers of matrix |1 1|  in O(LOG N), using binary exponiation
                                 |1 0| 
```
##### Binary Expon

This ia a way of finding a^n in log N steps

ALGO:

1).We first find binary representation of 'a'  --->LOG(a)-->SPACE and Time complexities

2).
```
   Then We find a,a^2,a^4 till a^(2^x) is less than a.
   By using a^(2^x) = [a^(2^(x-1))]* [a^(2^(x-1))]
   --->LOG(a)-->SPACE and Time complexities
```
3).
```
   Now we add multiply all those a^(2^x) where xth bit is 1 in binary representation of n(2^x is needed to represent 'n' as sum of non-reptitive 2^i)
   --->LOG(a) -->Time complexities
   --->LOG(1) -->SPACE complexities
```

NOTE:

Space complexity can be O(1) if we need to find just one Fibannoci number
This can be done by caluculation a^(2^x) and a^n simultaneouly instead of two loops
This is done in this problem here


##### CODE:

PROBLEM: https://www.codechef.com/IARCSJUD/problems/TILES01 

This was problem in IARCS Online judge now moved to CODECHEF
O(N) solution also works but O(LOG N is the best)

```c++
#include<bits/stdc++.h>
using namespace std;
vector<long long int>v;
vector<long long int>b;
vector<long long int>a;
int bin(long long int n)
{
    long long int ct=0;
    while(n!=0)
    {
        b.push_back((n%2));
        n=(n/2);
        ct++;

    }
    return ct;

}
int fib(long long int n,long long int m)
{
    long long int a1,a2,a3,a4;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);

    if((n==1)||(n==2))
    {
        return 1;
    }
    else
    {
        long long int k=bin(n);
        for(long long int i=0;i<k;i++)
        {

            if(b[i]==1)
            {
                a1=(((v[0]*a[0])%m)+((v[1]*a[2])%m))%m;
                a2=(((v[0]*a[1])%m)+((v[1]*a[3])%m))%m;
                a3=(((v[2]*a[0])%m)+((v[3]*a[2])%m))%m;
                a4=(((v[2]*a[1])%m)+((v[3]*a[3])%m))%m;
                a.clear();
                a.push_back(a1);
                a.push_back(a2);
                a.push_back(a3);
                a.push_back(a4);
            }
            a1=(((v[0]*v[0])%m)+((v[1]*v[2])%m))%m;
            a2=(((v[0]*v[1])%m)+((v[1]*v[3])%m))%m;
            a3=(((v[0]*v[2])%m)+((v[2]*v[3])%m))%m;
            a4=(((v[1]*v[2])%m)+((v[3]*v[3])%m))%m;

            v.clear();
            v.push_back(a1);
            v.push_back(a2);
            v.push_back(a3);
            v.push_back(a4);

        }
        return a[1];
    }

}
int main()
{
   long long int x;
   cin>>x;
   cout<<fib((x+1),15746);
   return 0;
}
```

## FINAL fibonacci analysis

### BEST FOR 
#### FInding just 1 Fibonacci : 
```
Matrix multiplication 
-->Time Complexity  = O(LOG N)
-->Space Complexity = O(1)
```
#### Test_Cases ~ Highest_value_of_n <= 1e6
```
FInding all Fibonnacci by Simple dynamic programmin(Finding all using for loop)
-->Time complexity  = O(N), N->highest given input
-->Space Complexity = O(N), N->highest given input
```
#### When (Test_Cases << Highest_value_of_n) or (Highest_value_of_n >=1e6)
```
Matrix muliplication
-->Time complexity = T*O(LOG N)
-->Space complexity = O(LOG N)
```

# Basic C++

This is not an exhaustive list 

###### Good links for c++ 

https://en.cppreference.com/w/ (This is given in INOI,some will be missing ,i will update if i find that link)


#### Basic structure

A c++ code needed for CP(hence for CP->COMPETITIVE PROGRAMMING)

```c++ 
#include<header files> //Here we include Header files//

    /*
        Basic Syntax 

        #include<headerfile_name>
                Or
        #include"headerfile_name"


        The most Commonly used header file is:

        #include<bits/stdc++.h>  { REASON: It contains almost all header files,So using this one is enough most cases,unless u are unlucky}
                            Or
        #include<stdio.h>       -> scanf/printf
        #include<iostream.h>    -> cin/cout
        #include<algorithm.h>   -> for sort function,binary search
        #include<math.h>        -> for sqrt,pow function
        #include<vector.h>      -> for vectors
        #include<maps.h>        -> for map
        #include<array.h>       -> for arrays
        #include<set.h>         -> for sets
        #include<deque.h>       -> for deque   
    */
using namespace std;  // Defining the standard namespace is std

//Global variables and Constants

        /*
        It is advised to declare array,vectors,2d-array,2d vectors in (size >10^5) values in this section
        We also Declare global Constansts. Ex:modulo constant, constant to declare array size
        */

//Then functions are written

/*
    Return_value_type function_name(Function_argument_1,Function_argument_2,..)
    {

    }

    Return_value_type -> the type of value function should return ,it can be void(nothing),int,char,pointer,etc

*/
void DFS(node u)  
{

}

int main() // this is needed always 
{
    /*
        Write u code here
        1.)Declare local variable
        2.)Take input
        3.)Call functions to implement a algorithm or implement function here itself
        4.)Output the processed input in the required format
    */
    return 0; //this is default return value,using this terminate program anywhere in this int main()
}
```

#### If else 

If else ladder is used to check conditions 

###### Syntax:
```c++ 
if(condition_1)
{
    //implement the code if condition_1 is satisfied
}
else if(condition_2)
{
    //This will be implemented only if all the above (if /else if) statements are not statisifed and the current condition is satisfied
}
else
{
    //This is implemented if none of the conditions are satisfyed
}
```
###### Notes:
->if only one line code no brackets needed

Ex:
```c++
    if(a>b)
        max=a;
    else if(a<b)
        max=b;
    else
        max=-1;
```

->"else if" and "else"  are NOT Compulsary 

#### FOR

###### Syntax

```c++
for ( init; condition; increment ) 
{
   //statement(s);
}
```
###### Note

-> Useful for accessing data
-> Used to input arrays 
-> Can be used in nested for's for going to multi demionsal array/vector
Ex:
```c++
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        //Here 'i' is constant across all values of j in loop
        for(int k=0;k<p;k++)
        {
            //Here 'i','j' are constant across all values of k in loop
        }
    }
}
```

#### While 

###### Syntax:
```c++
while(condition) 
{
   //statement(s);
}
```
###### Notes

Statements are implemented as long the condition is true

#### Taking Modulo

This is very important part

While taking modulo we should make sure 
1)No negative value as modulo , ie if 'a' is negative we make 'a' positive by adding 'mod' and then take modulo
2)((a%mod)+(b%mod))%mod is preferred over (a+b)%mod since a+b can overflow the int or long long limit
3)if more than two value multiplication are there then modulo for every pair should be taked
Ex:
```c++
int x = ((a%mod)+(b%mod))%mod;
int y = ((((A%mod)*(B%mod))%mod)*(C%mod))%mod;
```

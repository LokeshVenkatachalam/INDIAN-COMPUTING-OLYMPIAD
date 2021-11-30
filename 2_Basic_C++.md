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
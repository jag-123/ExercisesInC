/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

1. This program is intended to print "42" five times. The bar() function
then attemps the assign the values to output an array [0,1,2,3,4].

2. Yes, I get the following warning: function returns address of local variable.
This occurs because variables allocated on stack are destroyed when they go out of scope.
In other words, in the foo() function you cant return "array" because it is
defined as a local variable. 

3. I get the following values:
0x7fffb1d53550
0x7fffb1d53550
0
1
2
3
4
The addresses are the same because the printf statements are pointing
to the same space 

4.  I get the following values when commenting out the printf statements
0
0
-605426048
32732
-605338320
I'm not sure, but I think that the variable is out of scope so the memory
address just points to some random value.

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 //constant memory

int *foo() { //trys to return a local variable which isn't good
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42; //changes values in array to 42
    }
    return array;
}

void bar() { //this function modifies an existing array
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}

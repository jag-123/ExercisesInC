/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void printing(){
	int local = 2;
	printf("Address of print is %p\n", &local);
}
int main ()
{
    int local = 5;

    void *new_malloc = malloc(128);
    void *p = malloc(128);
    void *chunk_1 = malloc(22);
    void *chunk_2 = malloc(22);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of new_malloc is %p\n", new_malloc);
    printf ("Address of p is %p\n", p);
    printing();
    printf ("Address of chunk_1 is %p\n", chunk_1);
    printf ("Address of chunk_2 is %p\n", chunk_2);
    return 0;
}

/*
10. I believe the line that is responsible for  x=5 is movl	$5, -4(%rbp).

11. There are less machine code lines because the unneccessary ones are
removed by the optimization.

12. The optimized version uses "jmp" while the non-optimized version does not.

13. The optimized version does not include y, while the non-optimized version does.
This is probably because optimization does not include any code that is
irrelevant. 

*/
#include <stdio.h>

int main(){
	int x=5;
	int y = x+1;
	printf("%d",x);
}
#include <stdio.h>

int main (){

	int upper, lower, a,b,i;

	a = 2;
	b=6;

	lower = 0;

	upper = 2;
 
	printf("Your function now looks like this: f(x)=%dx+%d\n", a,b);


	printf("Values f(x) for the range <%d,%d>:\n", lower, upper);

	
		
	for (i=lower; i<= upper; ++i) {

		printf("f(%d)=%d\n",i,a*i+b);
 

}

return 0;

}

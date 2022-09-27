#include <stdio.h>

void linear_2_param (int a, int b) {
		
	printf("Your function now looks like this: f(x)=%dx + %d\n",a,b); 

return;

}

void linear_range (int a, int b) { 

	printf("Values f(x) for the range <%d, %d>:\n", a,b);

return;
}

int linear_values (int a, int x, int b){


	int result = a*x+b;
	
return result;

}

int init_x (int lower, int upper, int step,int* x) {

	int i;
	int count;
	count = 0;
	for (i=lower; i<=upper; i+=step) {//or i=i+step
	
	*x=i;
	x++;	
        count++;
}
return count;
}

void calc_values(int a, int b,const int* x,int* y, int n_elem){



	for(int i=0;i<n_elem;++i){

	*y = linear_values (a,*x,b);
	++x;
	printf("%d\n",*y);
	++y;
	}

}

void print_values(const int* x,const int* y, int n_elem){

	for(int i=0; i<n_elem; ++i){

	printf("f(%d) = %d\n", *x, *y);
	x++;
	y++;
}
return;

}
#define LOWER 0  //defining symbolic constants LOWER and UPPER and A and B
#define UPPER 99
#define A 2
#define B 6

int main (){
//declaring two arrays x and y of size 100 per each

int x[100];
int y[100]; 
//calling function init_x(lower,upper,step,x) that initializes array x
	int n_elem;

	n_elem = init_x (LOWER,UPPER,1,x);

	linear_2_param (A,B);

	linear_range (LOWER,UPPER);
	
	calc_values(A,B,x,y,n_elem);
        print_values(x,y,n_elem);

return 0;
}

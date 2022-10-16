#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
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

int init_x (int lower, int upper, int step,int** x) {

	
	int i;
	int count;
	
	count = 0; 
#if 0
/* 1st version  */
	*x= malloc(10*sizeof(int));

	for (i=lower; i<=upper; i+=step) {//or i=i+step
	
//	(*x)[count]=i;
	*((*x)+i)=i;
	printf("%d\n",(*x)[count]);


	
        count++;
}

#endif

int *tmp = malloc(10 * sizeof(int));
//important assign x before we increment tmp
*x= tmp;
	for (i=lower; i<=upper; i+=step) {//or i=i+step
	
	*tmp=i;
        tmp++;
        count++;

	if (count>=10){

	tmp = realloc (*x, ((count+1)*sizeof(int)));
        tmp=NULL;
if (tmp == NULL){
	printf("Not enough memory - exiting...");

	return -ENOMEM;
	
}
	*x = tmp;
	tmp +=count;
}
	

}
return count;
}

void calc_values(int a, int b,const int* x,int* y, int n_elem){



	for(int i=0;i<n_elem;++i){

	*y = linear_values (a,*x,b);
	++x;

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

#if 0
int input (int* lower, int* upper, int* step){

	int c;

	printf("Give the lower end of the range: \n");
	c = scanf("%d",lower);
	
	if (c != 1) 

{	printf("Wrong input data...\n");

	return 1;
}i

		
	printf("Give the upper end of the range: \n");

	scanf("%d", upper);

	printf("Give the value of the step: \n");

	scanf("%d", step);


return 0;
}
#endif
int input(int *lower, int *upper, int *step) {//this time we read input data from the test.txt file)


FILE *fp = NULL;

fp = fopen("test.txt","r");

if (fp ==NULL) {           //we're checking if the file exists and can be read

	printf("error: no file");
	exit(1);

}


int c = fscanf (fp, "%d", lower);//assigning first integer value from the test.txt file to 'lower' variable
	if (c != 1) 

{	printf("Wrong input data...\n");

	return 1;
}

int d = fscanf(fp, "%d", upper);

	if (d != 1) 

{	printf("Wrong input data...\n");

	return 1;
}

int e = fscanf(fp, "%d", step);

	if (e != 1) 

{	printf("Wrong input data...\n");

	return 1;

fclose(fp);

return 0;
}
#define A 2
#define B 6

int main (){


int *x;
int lower;
int upper;
int step;
int input_res;

	int n_elem;
	
	
input_res = input(&lower,&upper,&step);

if (input_res == 1){

return 0;

}

if (lower>upper || step>(upper - lower)){

printf("Wrong values - exiting...\n");
return 0;

}
#if 0   
printf("lower:%d\n",lower);
printf("upper:%d\n",upper);
printf("step:%d\n", step);
#endif
	n_elem = init_x (lower,upper,step,&x);

	if (n_elem ==-ENOMEM){
	printf("exiting...");	
	return 1;

}
int *y = (int*)malloc(10*sizeof(int));
if (y==NULL)             //if y is null pointer AKA there's not enough space for y on the heap, then free(x) and exit as we need space for both array x and y
{
free(x);
printf("Not sufficient memory.exiting\n");
return -ENOMEM;
}

	linear_2_param (A,B);

	linear_range (lower,upper);
	
	calc_values(A,B,x,y,n_elem);
        print_values(x,y,n_elem);
free(x);
free(y);
return 0;
}

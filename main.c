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
int *tmp = malloc(10 * sizeof(int));
//important assign x before we increment tmp
*x= tmp;
	for (i=lower; i<=upper; i+=step) {//or i=i+step
	
	*tmp=i;
        tmp++;
        count++;

	if (count>=10){

	tmp = realloc (*x, ((count+1)*sizeof(int)));
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

int input(int *lower, int *upper, int *step, FILE *fp) {



if (fp ==NULL) {      //if file doesn't exist or user has not entered any file name then we take data from standard input
fp = stdin;
}


//fscanf(stdin, "%d",lower); == scanf("%d", lower);
if (fp == stdin)
	printf("Give the lower end of the range: \n");

int c = fscanf (fp, "%d", lower);

	if (c != 1) 

{	printf("Wrong input data...\n");

	return 1;
}

if (fp == stdin)
	printf("Give the upper end of the range: \n");
int d = fscanf(fp, "%d", upper);

	if (d != 1) 

{	printf("Wrong input data...\n");

	return 1;
}

if (fp == stdin)
	printf("Give the value of the step: \n");
int e = fscanf(fp, "%d", step);

	if (e != 1) 

{	printf("Wrong input data...\n");

	return 1;
}


return 0;
}
#define A 2
#define B 6

int main (int argc, char* argv[]){ //we introduce argc (agrument count) and argv (argument vector)


int *x;
int lower;
int upper;
int step;
int input_res;

	int n_elem;
	
if (argc==2){	//if argc = 2 means that user has input the name of the file which is assigned as argv[1]
FILE * fp= fopen(argv[1], "r");
if (fp ==NULL){ //this happens when file doesn't exist
printf("invalid file name or path. \n reading from input...\n");

}
input_res = input(&lower,&upper,&step, fp);
if (fp) //is equivalent to: fp != NULL. If file pointer fp exists (is not NULL then we close it)
fclose(fp);
}
if (argc ==1){
input_res = input(&lower,&upper,&step,NULL );
}


if (lower>upper || step>(upper - lower)){

printf("Wrong values - exiting...\n");
return 0;

}
n_elem = init_x (lower,upper,step,&x);

	if (n_elem ==-ENOMEM){
	printf("exiting...");	
	return 1;

}
int *y = (int*)malloc(10*sizeof(int));
if (y==NULL)             
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

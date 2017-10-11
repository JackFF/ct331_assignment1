#include <stdio.h>

int main(int arg, char* argc[]){
  
	int a;
	int* b;
	long c;
	double* d;
	char** e;

	printf("The size of int is: %d \n", sizeof(a));
	printf("The size of int* is: %d \n", sizeof(b));
	printf("The size of long is: %d \n", sizeof(c));
	printf("The size of double* is: %d \n", sizeof(d));
	printf("The size of char** is: %d \n", sizeof(e));
  return 0;
}

#include<stdio.h>

void square(double a, double* b){
	*b = a*a;
}

void getSumDiff(int a, int b, int* pSum, int *pDiff){
	*pSum = a+b;
	*pDiff = a-b;
	if(*pDiff) *pDiff = -*pDiff;
}

int main(void){
	double dvar, ans;
	scanf("%lf", &dvar);
	square(dvar, &ans);
	printf("User input : %f\nSquared number: %f", dvar, ans);
}

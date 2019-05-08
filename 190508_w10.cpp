#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void guess(){
	srand(time(NULL));
	int to=rand()%20+1;
	int N;
	for(int cnt=1; cnt<=6; cnt++){
		printf("guess the number(range : [1,20])\n");
		scanf("%d", &N);
		if(N==to){
			printf("Yoo Win! The number is %d\n", to);
			printf("Turn : %d\n", cnt);
			return;
		}
		else if(N>to) printf("Too high\n");
		else printf("Too low\n");
	}
	printf("Yoo lose! The number is %d\n", to);
}

void dan(){
	printf("Input dan.\n");
	int N;
	scanf("%d", &N);
	printf("********%ddan********\n", N);
	for(int i=1; i<=9; i++){
		printf("%d*%d=%d\n", N, i, N*i);
	}
	printf("***********************\n");
}

void printstar(int blank, int star){
	while(blank--) printf(" ");
	while(star--) printf("*");
	printf("\n");
}

void printstar1(){
	int N;
	printf("how many lines?\n");
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		printstar(N-i, 2*i-1);
	}
}

void printstar2(){
	int N;
	printf("how many lines?\n");
	scanf("%d", &N);
	for(int i=N; i>1; i--){
		printstar(N-i, 2*i-1);
	}
	for(int i=1; i<=N; i++){
		printstar(N-i, 2*i-1);
	}
}

int main(void){
	int N;
	printf("1 : guess number\n2 : dan\n3 : star1\n4 : star2\n0 : exit\n");
	scanf("%d", &N);
	while(N){
		if(N==1){
			guess();
		}
		else if(N==2){
			dan();
		}
		else if(N==3){
			printstar1();
		}
		else if(N==4){
			printstar2();
		}
		else{
			break;
		}
		printf("1 : guess number\n2 : dan\n3 : star1\n4 : star2\n0 : exit\n");
		scanf("%d", &N);
	}
}

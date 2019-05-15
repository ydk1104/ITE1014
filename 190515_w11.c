#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void pyramid(){
	printf("1. Pyramid\nInput length\n");
	int N;
	scanf("%d", &N);
	N--;
	int i=0;
	while(i<N){
		int j=0;
		while(j<N*2){
			if(j==N-i || j==N+i) printf("*");
			else printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
	int k=0;
	while(k<=2*N){
		printf("*");
		k++;
	}
}

int comp(int var1, int var2){
	if(var1<var2) return -1;
	return var1>var2;
}

void fundef(){
	printf("2. Function definition practice\n");
	srand(time(0));
	int r = rand()%101;
	int Number=r-1;
	char ans[3][15] = {"Larger than ", "Yes. Right", "Smaller than "};
	while(Number!=r){
		printf("Number=?\n");
		scanf("%d", &Number);
		printf("%s",ans[comp(Number, r)+1]);
		if(comp(r,Number)) printf("%d", Number);
		printf(".\n");
	}
}

void printLine(int N){
	int i=0;
	while(++i<=N) printf("%d ",i);
	printf("\n");
}

void funprac(void){
	printf("3. Function practice\ninput number\n");
	int N;
	scanf("%d", &N);
	int i=1;
	while(i<=N) printLine(i++);
	while(i>1) printLine(--i);
}

void displayIntro(){
	printf("You are in a land full of dragons. In front of you,\n");
	printf("You see two caves. In one cave, the dragon is friendly\n");
	printf("and will share his treasure with you. The other dragon\n");
	printf("is greedy and hungry, and will eat you on sight.\n");
}

int chooseCave(){
	int cave = 0;
	while(cave!=1 && cave!=2){
		printf("Which cave will you go into? (1 or 2)\n");
		scanf("%d", &cave);
	}
	return cave;
}

void checkCave(chosenCave){
	printf("You approach the cave...\n");
	sleep(2);
	printf("It is dark and spooky...\n");
	sleep(2);
	printf("A large dragon jumps out in front of you! He opens his jaws and...\n");
	sleep(2);
	srand(time(0));
	int friendlyCave = rand()%2+1;
	if(chosenCave == friendlyCave) printf("Gives you his treasure!\n");
	else printf("Gobbles you down in one bite!\n");
}

void dragon(void){
	displayIntro();
	checkCave(chooseCave());
	printf("Do you want to play again? (yes or no)\n");
	char s[5];
	getchar();
	gets(s);
	if(*s=='y') return dragon();
}

long long f[99] = {0, };

long long fibo(int N){
	if(N==0 || N==1) return N;
	if(f[N]) return f[N];
	return f[N] = fibo(N-1) + fibo(N-2);
}

void fibonacci(){
	printf("5 : fibonacci\ninput number\n");
	int N;
	scanf("%d", &N);
	printf("%lld", fibo(N));
}

void drawline(int star, int blank){
	int i=0;
	while(i++<star) printf("*");
	i=0;
	while(i++<blank) printf(" ");
	i=0;
	if(blank<0) star--;
	while(i++<star) printf("*");
	printf("\n");
}

void printstar(){
	printf("6 : printingstar\nHeight : ");
	int N;
	scanf("%d", &N);
	int star=N, blank=-3;
	while(star>=1){
		drawline(star--, blank+=2);
	}
	star++;
	while(star<N){
		drawline(++star, blank-=2);
	}
}

void printmenu(int *N){
	printf("\n");
	printf("1 : Pyramid\n");
	printf("2 : fun def\n");
	printf("3 : fun practice\n");
	printf("4 : Dragon Realm\n");
	printf("5 : fibonacci\n");
	printf("6 : printingstar\n");
	printf("0 : exit\n");
	scanf("%d", N);
}

int main(void){
	int N;
	printmenu(&N);
	while(N){
		if(N==1) pyramid();
		if(N==2) fundef();
		if(N==3) funprac();
		if(N==4) dragon();
		if(N==5) fibonacci();
		if(N==6) printstar();
		printmenu(&N);
	}
}

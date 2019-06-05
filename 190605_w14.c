#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char menu[5][50] = {"1 : Multi-dimensional array pointer\n",
					"2 : String functions\n",
					"3 : baseball\n",
					"4 : 369\n",
					"0 : exit\n"};

void print_menu(){
	int i=0;
	for(i=0; i<5; i++) printf("%s", menu[i]);
}

void Multi_dimentional_array_pointer(){
	int arr[12];
	int i,j;
	for(i=0; i<12; i++) *(arr+i) = (i+1)*10;
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d ",arr[4*i+j]);
		}
		printf("\n");
	}
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d ",*(arr+4*i+j));
		}
		printf("\n");
	}

/*	int arr_2d[3][4];
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			arr_2d[i][j] = i*40+j*10;
		}
	}
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d ",arr[4*i+j]);
		}
		printf("\n");
	}
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			printf("%d ",*(arr+4*i+j));
		}
		printf("\n");
	} */
}

int mystrlen(char *s){
	int len = 0;
	while(s[len]) len++;
	return len;
}

int mystrcmp(char *a, char *b){
	int i=0;
	while(a[i] || b[i]){
		if(a[i] != b[i]) return a[i] - b[i];
		i++;
	}
	return 0;
}

void mystrcpy(char *a, char *b){
	int i=0;
	while(b[i]){
		a[i] = b[i];
		i++;
	}
	a[i]=0;
}

void mystrcat(char *a, char *b){
	int alen = mystrlen(a), i=0;
	while(b[i]){
		a[alen+i] = b[i];
		i++;
	}
	a[alen+i] = 0;
}

int myatoi(char *a){
	int num=0, i=0;
	while(a[i]){
		num*=10;
		num+=a[i]-'0';
		i++;
	}
	return num;
}

void String_functions(){
	char test1[] = "Hello, world!";
	char test2[] = "Hello, World!";
	printf("test1 = %s\n", test1);
	printf("strlen = %d, mystrlen = %d\n\n", strlen(test1), mystrlen(test1));
	char x[2]; // without it, test2 corrupted by strcpy
	printf("test1 = %s, test2 = %s\n", test1, test2);
	printf("strcmp = %d, mystrcmp = %d\n\n", strcmp(test1, test2), mystrcmp(test1, test2));
	char temp[] = "";
	printf("test1 = %s, temp = %s\n", test1, temp);
	strcpy(temp, test1);
	printf("after strcpy\n");
	printf("test1 = %s, temp = %s\n", test1, temp);

	*temp = 0;
	printf("test1 = %s, temp = %s\n", test1, temp);
	mystrcpy(temp, test1);
	printf("ater mystrcpy\n");
	printf("test1 = %s, temp = %s\n\n", test1, temp);

	char test3[] = "...Goodbye, world!";	
	printf("test1 = %s, test3 = %s\n", test1, test3);
	strcat(test1, test3);
	printf("ater strcat(test1, test3)\n");
	printf("test1 = %s, test3 = %s\n", test1, test3);

	printf("test2 = %s, test3 = %s\n", test2, test3);
	mystrcat(test2, test3);
	printf("ater mystrcat(test2, test3)\n");
	printf("test2 = %s, test3 = %s\n\n", test2, test3);
	
	char num[5] = {"1234"};
	printf("num = %s\n", num);
	printf("atoi(num) = %d, myatoi(num) = %d\n", atoi(num), myatoi(num));
}

int equal(int N){
	int prev[3];
	int cnt=0, i;
	while(N){
		for(i=0; i<cnt; i++){
			if(prev[i] == N%10) return 1;
		}
		prev[cnt++] = N%10;
		N/=10;
	}
	return 0;
}

void sb(int a, int b){
	int i, j;
	int p10[4] = {1, 10, 100, 1000};
	int s=0, ba=0;
	for(i=1; i<4; i++){
		for(j=1; j<4; j++){
			if((a%p10[i])/p10[i-1] == (b%p10[j])/p10[j-1]){
				if(i==j) s++;
				else ba++;
			}
		}
	}
	printf("%d strike, %d ball.\n", s, ba);
}

void baseball(){
	char bar[] = "==================================\n\n\n";
	printf("S T A R T\n");
	printf("%s", bar);
	srand(time(NULL));
	int num = rand()%(988-123)+123;
	while(equal(num)) num = rand()%(988-123)+123;
	printf("Test : ans = %d\n", num);
	char guess[4] = "";
	int guessnum = 0;
	while(num != guessnum){
		v:
		printf("Guess numbers(123 ~ 987):\n");
		scanf("%s", guess);
		guessnum = atoi(guess);
		if(equal(guessnum)){
			printf("Wrong input\n");
			goto v;
		}
		sb(num, guessnum);
	}
	printf("Yes! The secret number is \"%d\"! You have won!\n\n", num);
	printf("Do you want to play again? (yes or no)\n");
	scanf("%s", &guess);
	if(*guess == 'y') return baseball();
}

void clap(int N){
	int check=0;
	int temp = N;
	while(N){
		if(N%10 && (N%10)%3==0) printf("clap "), check++;
		N/=10;
	}
	if(!check) printf("%d", temp);
	printf("\n");
}

void _369(){
	int N;
	printf("Input the last number\n");
	scanf("%d", &N);
	printf("-----------START--------------\n");
	int i;
	for(i=1; i<=N; i++){
		clap(i);
	}
}

void nothing(void){}

int main(void){
	int N;
	void (*func[5])() = {nothing, Multi_dimentional_array_pointer, String_functions, baseball, _369};
	do{
		print_menu();
		scanf("%d", &N);
		if(N>4) N=0;
		if(N) printf("%s", menu[N-1]);
		func[N]();
	}while(N);
}

#include<stdio.h>

void interview(void){
	char name[20];
	char gender[20];
	char birth[9];
	char destination[20];
	char period[9];
	printf("<<< Interview for Travel Plan >>>\n");
	printf("Input your name: ");
	scanf("%s", &name);
	printf("Gender: ");
	scanf("%s", &gender);
	printf("Day of birth<ex. 19910212>: ");
	scanf("%s", &birth);
	printf("Destination: ");
	scanf("%s", &destination);
	printf("Period of trip<ex. 5>: ");
	scanf("%s", &period);
	printf("\n\n");
	printf("===============================\n");
	printf("NAME:           %s\n", name);
	printf("GENDER:         %s\n", gender);
	printf("DAY OF BIRTH:   %s\n", birth);
	printf("DESTINATION:    %s\n", destination);
	printf("PERIOD OF TRIP: %s\n", period);
	printf("===============================\n");
}

void calculator(){
	int num[3], i;
	printf("A + B - C = ?\n");
	for(i='A'; i<='C'; i++){
		printf("Input %c: ", i);
		scanf("%d", &num[i-'A']);
	}
	printf("%d + %d - %d = %d", num[0], num[1], num[2], num[0]+num[1]-num[2]);
}

void square(){
	printf("-------------------------\n");
	printf("Please input the number : ");
	int N;
	scanf("%d", &N);
	int check = 1;
	while(check*check<N){
		check++;
	}
	if (check*check==N) printf("\n%d is the square number of %d", N, check);
	else printf("\n%d is not square number", N);
	printf("\n\nTry again? [yes<1>, no<2>]\n");
	scanf("%d", &check);
	if(check==1) square();
	else printf("Good Bye!");
}

int main(){
	int N;
	printf("1 : I/O practice\n2 : calculator\n3 : Square number checker\n0 : exit\n");
	for(scanf("%d", &N); N; scanf("%d", &N)){
		if(N==1) interview();
		if(N==2) calculator();
		if(N==3) square();
	}
}

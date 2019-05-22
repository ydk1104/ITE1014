#include<stdio.h>
#include<math.h>

char bar[] = "============================\n"; 

void scan_number(FILE* ptr_file, int check, double *num){
	printf("operand >> ");
	scanf("%lf", num);
	if(check) fprintf(ptr_file, "operand >> %.2f\n", *num);
}

int scan_type(FILE* ptr_file, int check){
	printf("operator: +, -, *, /, %%, ^, 0(to exit))\n");
	printf("operator >> ");
	char types[] = {'+', '-', '*', '/', '%', '^', '0'};
	char type = 0;
	int i;
	while(1){
		type = getchar();
		for(i=0; i<7; i++){
			if(type==types[i]) goto v;
		}
	}
	v:
	if(check){
		fprintf(ptr_file, "operator: +, -, *, /, %%, ^, 0(to exit))\n"
		"operator >> %c\n", types[i]);
	}
	return i;
}

double add(double a, double b){
	return a+b;
}

double sub(double a, double b){
	return a-b;
}

double mul(double a, double b){
	return a*b;
}

double div(double a, double b){
	return a/b;
}

double end(double a, double b){
	return a;
}

void calculator(int check){
	FILE *ptr_file;
	if(check) ptr_file = fopen("calculator.txt", "w");
	printf("calculator\n");
	printf("%s",bar);
	printf("operator: +, -, *, /, %%, ^\n");
	printf("%s",bar);
	if(check){
		fprintf(ptr_file, "calculator\n"
		"%s"
		"operator: +, -, *, /, %%, ^\n"
		"%s", bar, bar);
	}
	double (*func[7])(double,double) = {add, sub, mul, div, fmod, pow, end};
	double a, b;
	int type;
	scan_number(ptr_file, check, &a);
	do{
		type = scan_type(ptr_file, check);
		scan_number(ptr_file, check, &b);
		a = func[type](a,b);
		printf("result >> %.2f\n", a);
		if(check) fprintf(ptr_file, "result >> %.2f\n", a);
	}while(type!=6);
	if(check) fclose(ptr_file);
}

int letter(char x){
	if(x>='a' && x<='z') return 1;
	if(x>='A' && x<='Z') return 1;
	return 0;
}

void word_count(int x){
	printf("word count\n");
	FILE *ptr_file = fopen("article.txt", "r");
	char ch, prev=' ';
	int word=1;
	int charcnt=0, lettercnt=0;
	int alphabet[26] = {0, };
	while((ch=fgetc(ptr_file)) != EOF){
		if(ch == ' ' || ch == '\n'){
			if(prev == ' ' || prev == '\n') word--;
			word++;
		}
		else{
			if(letter(ch)){
				if(ch >= 'a') alphabet[ch-'a'] ++;
				else alphabet[ch-'A']++;
				lettercnt++;
			}
//			charcnt++;
		}
		charcnt++;
		prev = ch;
	}
	int max=-1, min=charcnt+1;
	char maxchar, minchar;
	int i;
	for(i=0; i<26; i++){
		if(alphabet[i] > max){
			max = alphabet[i];
			maxchar = i+'A';
		}
		if(alphabet[i] < min){
			min = alphabet[i];
			minchar = i+'A';
		}
	}
	printf("word : %d\n", word-1);
	printf("characters : %d\n", charcnt);
	printf("letters : %d\n", lettercnt);
	printf("most frequently: %c\n", maxchar);
	printf("most infrequently : %c\n", minchar);
	fclose(ptr_file);
}

void nothing(int x){}

int main(void){
	int N=0;
	void (*_func[4])(int N);
	void (**func)(int N) = _func+1;
	func[-1] = nothing;
	func[0] = calculator;
	func[1] = calculator;
	func[2] = word_count;
	do{
		printf("1 : Calculator\n");
		printf("2 : Calculator with file\n");
		printf("3 : word count\n");
		printf("0 : exit\n");
		scanf("%d", &N);
		func[N-1](N-1);
	}while(N);
}

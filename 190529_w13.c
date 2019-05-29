#include<stdio.h>

char menu[5][30] = {"1 : Size of array\n", 
				"2 : Array & address\n",
				"3 : Pointers\n",
				"4 : Multi-dimensional array\n",
				"0 : exit\n"};

void print_menu(void){
	int i=0;
	for(;i<5; i++) printf("%s",menu[i]);
}

int mean(int arr[], const int n){
	printf("in mean function\n");
	printf("test : size of arr : %d\n", sizeof(arr));
	printf("because we don't know how many elements in array, the size of array(const int n) is required.\n");
	int i=0;
	int sum=0;
	for(; i<n; i++) sum += arr[i];
	return sum/n;
}

void Size_of_array(void){
	printf("%s", *menu);
	int i=0;
	
	int arr_int[7] = {1, 2, 3, 4, 5, 6, 7};
	printf("int array : ");
	for(i=0; i<7; i++) printf("%d ", arr_int[i]);
	printf("\nsize of int array : %d\n", sizeof(arr_int));
	
	float arr_float[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	printf("float array : ");
	for(i=0; i<7; i++) printf("%.1f ", arr_float[i]);
	printf("\nsize of float array : %d\n", sizeof(arr_float));

	double arr_double[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	printf("double array : ");
	for(i=0; i<7; i++) printf("%.1f ", arr_float[i]);
	printf("\nsize of double array : %d\n", sizeof(arr_double));
	
	printf("\n");
	printf("mean of int array : %d\n", mean(arr_int, 7));	
	printf("\n");
}

void Array_and_adress(void){
	printf("%s", menu[1]);
	double arr[5] = {1., 2., 3., 4., 5.};
	int i=0;
	for(i=0; i<3; i++) printf("&arr[%d] : %p, arr+%d : %p\n", i, &arr[i], i, arr+i);
	for(i=0; i<3; i++) printf("arr[%d] : %f, *(arr+%d) : %f\n", i, arr[i], i, *(arr+i));
}

void Pointers_4(void){
	printf("\nPointers_4\n");
	const int max_size = 5;
	printf("Input %d numbers\n", max_size);
	int arr[5];
	int i=0;
	for(; i<max_size; i++) scanf("%d", arr+i);
	int *begin = arr, *end = arr+max_size, *p;
	int max=*arr, min=*arr;
	for(p=begin; p!=end; p++){
		max = max > *p ? max : *p;
		min = min < *p ? min : *p;
	}
	printf("max : %d\nmin : %d\n", max, min);
}

void Pointers_3(void){
	printf("\nPointers_3\n");
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *begin = arr;
	int *end = arr+9;
	int *rbegin = arr+8;
	int *rend = arr-1;
	int *p;
	int sum = 0;
	for(p=begin; p!=end; p++){
		sum += *p;
	}
	printf("%d\n", sum);
	printf("Reverse\n");
	for(p=rbegin; p!=rend; p--){
		printf("%d ", *p);
	}
	printf("\n");
	return Pointers_4();
}

void Pointers_2(void){
	printf("\nPointers_2");
	int m = 7;
	int *ptr = &m;
	printf("\n");
	printf("ptr = %p, *ptr = %d\n", ptr, *ptr);
	*ptr = 10;
	printf("*ptr = 10\n");
	printf("ptr = %p, *ptr = %d\n&m = %p, m = %d\n", ptr, *ptr, &m, m);
	return Pointers_3();
}

void Pointers(void){
	printf("%s", menu[2]);
	double arr[5] = {1., 2., 3., 4., 5.};
	double *ptr = NULL;
	ptr = arr;
	int i=0;
	for(i=0; i<3; i+=2) printf("ptr+%d : %p, arr+%d : %p, &arr[%d] : %p\n",i, ptr+i, i, arr+i, i, &arr[i]);
	for(i=0; i<3; i+=2) printf("*(ptr+%d) : %f, *(arr+%d) : %f, arr[%d] : %f\n",i, *(ptr+i), i, *(arr+i), i, arr[i]);
	return Pointers_2();
}

void Multi_dimensional_array(void){
	printf("%s", menu[3]);
	int arr_1d[12], arr_2d[3][4];
	int i, j;
	for(i=0; i<12; i++) arr_1d[i] = (i+1)*10;
	printf("arr_1d :\n");
	for(i=0; i<12; i++) printf("%d ",arr_1d[i]);
	printf("\narr_2d :\n");
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			arr_2d[i][j] = arr_1d[i*4+j];
			printf("%d ",arr_2d[i][j]);
		}
		printf("\n");
	}
	printf("reverse arr_1d : \n");
	for(i=0; i<12; i++){
		arr_1d[i] = arr_2d[2-i/4][3-i%4];
		printf("%d ",arr_1d[i]);
	}
	printf("\n");
}

void do_nothing(void){}

int main(void){
	int N;
	void (*func[5])(void) = {do_nothing, Size_of_array, Array_and_adress, Pointers, Multi_dimensional_array};
	do{
		print_menu();
		scanf("%d", &N);
		func[N]();
	}while(N);
}

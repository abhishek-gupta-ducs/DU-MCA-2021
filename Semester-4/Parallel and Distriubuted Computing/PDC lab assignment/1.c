#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void print(int arr[], int n){
	//This function is used to print the array.
	int i=0;
	printf("\n---------------------------------------------------\n");
	printf("Index\tArray Value\n");
	#pragma omp parallel for
	for(i=0; i<n; i++)
		printf("%d\t%d\n", i, arr[i]);
}

void sumArray(int arr[], int n){
	//This function is used to find the sum of n-array elements.
	int sum = 0, i;
	printf("\n---------------------------------------------------\n");
	#pragma omp parallel for reduction(+:sum)
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
	printf("The sum of elements of the array is: %d\n", sum);
}

void productArray(int arr[], int n){
	//This function is used to find product of n array elements.
	int prod = 1, i;
	printf("\n---------------------------------------------------\n");
	#pragma omp parallel for reduction(*:prod)
	for(i= 0; i<n; i++)
	{
		prod *= arr[i];
	}
	printf("The product of elements of the array is: %d\n", prod);
    printf("\n---------------------------------------------------\n");
	
}
void main(){
	int i, n;
	//Populating the array
	printf("Enter size of array: ");
	scanf("%d", &n);
	int arr[n];
	for(i = 0; i<n; i++)
	{
        printf("Enter value at index %d : ",i);
		scanf("%d", &arr[i]);
	}
	print(arr, n);
	sumArray(arr, n);
	productArray(arr, n);
}


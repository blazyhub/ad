#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
void swap(int* a, int* b) 
{ 
int t = *a; 
*a = *b; 
*b = t; 
} 
int partition(int arr[], int low, int high) 
{ 
int pivot = arr[high]; 
int i = (low - 1); 
for (int j = low; j <= high - 1; j++) 
{ 
if (arr[j] < pivot) 
{ 
i++; 
swap(&arr[i], &arr[j]); 
} 
} 
swap(&arr[i + 1], &arr[high]); 
return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
if (low < high) 
{ 
int pi = partition(arr, low, high); 
quickSort(arr, low, pi - 1); 
quickSort(arr, pi + 1, high); 
} 
} 
void generateRandomNumbers(int arr[], int n) 
{ 
for (int i = 0; i < n; i++) 
{ 
arr[i] = rand() % 100000; 
} 
} 
int main() 
{ 
int n; 
printf("Enter number of elements: "); 
scanf("%d", &n); 
if (n <= 5000) 
{ 
printf("Please enter a value greater than 5000\n"); 
return 1; 
} 
int *arr = (int *)malloc(n * sizeof(int)); 
if (arr == NULL) 
{ 
printf("Memory allocation failed\n"); 
return 1; 
} 
generateRandomNumbers(arr, n); 
clock_t start = clock(); 
quickSort(arr, 0, n - 1); 
clock_t end = clock(); 
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; 
printf("Time taken to sort %d elements: %f seconds\n", n, time_taken); 
free(arr); 
return 0; 
} 
GNU PLOT
#include <stdio.h> 
#define MAX_VALUES 5 
int main() { 
int n_values[MAX_VALUES] = {10000,20000,50000,80000,90000}; 
double time_taken[MAX_VALUES] = {0.001, 0.0034, 0.005, 0.0082, 
0.009}; 
FILE *gnuplot = popen("gnuplot -persist", "w"); 
if (gnuplot == NULL) { 
perror("gnuplot"); 
return 1; 
} 
fprintf(gnuplot, "set title 'Time taken vs N values'\n"); 
fprintf(gnuplot, "set xlabel 'N values'\n"); 
fprintf(gnuplot, "set ylabel 'Time taken (seconds)'\n"); 
fprintf(gnuplot, "plot '-' with linespoints title 'Data'\n"); 
for (int i = 0; i < MAX_VALUES; ++i) { 
33 
fprintf(gnuplot, "%d %lf\n", n_values[i], time_taken[i]); 
} 
fprintf(gnuplot, "e\n"); 
fflush(gnuplot); 
pclose(gnuplot); 
return 0; 
} 

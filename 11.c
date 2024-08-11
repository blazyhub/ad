#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
void merge(int arr[], int left, int mid, int right) 
{ 
int i, j, k; 
int n1 = mid - left + 1; 
int n2 = right - mid; 
int *L = (int *)malloc(n1 * sizeof(int)); 
int *R = (int *)malloc(n2 * sizeof(int)); 
for (i = 0; i < n1; i++) 
L[i] = arr[left + i]; 
for (j = 0; j < n2; j++) 
R[j] = arr[mid + 1 + j]; 
i = 0; 
j = 0; 
k = left; 
while (i < n1 && j < n2) 
{ 
if (L[i] <= R[j]) 
{ 
arr[k] = L[i]; 
i++; 
} 
else 
{ 
arr[k] = R[j]; 
j++; 
} 
k++; 
} 
while (i < n1) 
{ 
arr[k] = L[i]; 
i++; 
k++; 
} 
while (j < n2) 
{ 
arr[k] = R[j]; 
j++; 
k++; 
} 
free(L); 
free(R); 
} 
void mergeSort(int arr[], int left, int right) 
{ 
if (left < right) 
{ 
int mid = left + (right - left) / 2; 
mergeSort(arr, left, mid); 
mergeSort(arr, mid + 1, right); 
merge(arr, left, mid, right); 
} 
} 
void generateRandomArray(int arr[], int n) 
{ 
for (int i = 0; i < n; i++) 
arr[i] = rand() % 100000; 
} 
int main() 
{ 
int n; 
printf("Enter the number of elements: "); 
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
generateRandomArray(arr, n); 
clock_t start = clock(); 
for (int i = 0; i < 1000; i++) 
{ 
mergeSort(arr, 0, n - 1); 
} 
clock_t end = clock(); 
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 
1000.0; 
printf("Time taken to sort %d elements: %f seconds\n", n, time_taken); 
free(arr); 
return 0; 
} 
GNU PLOT
#include <stdio.h> 
#define MAX_VALUES 5 
int main() { 
int n_values[MAX_VALUES] = {6000, 7000, 8000, 9000, 10000, 11000, 
12000, 13000, 15000}; 
double time_taken[MAX_VALUES] = {0.000709, 0.000752, 0.000916, 
0.001493, 0.001589, 0.002562, 0.001944, 0.002961, 0.003563}; 
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
fprintf(gnuplot, "%d %lf\n", n_values[i], time_taken[i]); 
} 
fprintf(gnuplot, "e\n"); 
fflush(gnuplot); 
pclose(gnuplot); 
return 0; 
} 

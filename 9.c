#include<stdio.h>
#include<time.h>
void selsort(int a[], int n)
{
 int i, j, small, pos, temp;
 for(j = 0; j < n - 1; j++)
 {
 small = a[j];
 pos = j;
 for(i = j + 1; i < n; i++)
 {
 if(a[i] < small)
 {
 small = a[i];
 pos = i;
 }
 }
 temp = a[j];
 a[j] = small;
 a[pos] = temp;
 }
}
int main()
{
 int a[10], i, n;
 struct timespec start, end;
 double dura;
 printf("\nEnter the n value:");
 scanf("%d", &n);
 printf("\nEnter the array:");
 for(i = 0; i < n; i++)
 scanf("%d", &a[i]);
 clock_gettime(CLOCK_MONOTONIC, &start);
 selsort(a, n);
 clock_gettime(CLOCK_MONOTONIC, &end);
 dura = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
 printf("\nTime taken is: %lf seconds", dura);
 printf("\nSorted array is:");
 for(i = 0; i < n; i++)
 printf("%d ", a[i]);
 return 0;
}
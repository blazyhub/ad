#include <stdio.h>
#define MAX_SIZE 10
int set[MAX_SIZE], subset[MAX_SIZE];
int n, i,targetSum, flag = 0;
void display(int count) {
printf("{");
for ( i = 0; i < count; i++) {
printf("%d", subset[i]);
if (i < count - 1) {
printf(", ");
}
}
printf("}\n");
}
void findSubset(int sum, int index, int count) {
if (sum == targetSum) {
flag = 1;
display(count);
return;
}
if (sum > targetSum || index >= n) {
return;
}
subset[count] = set[index];
findSubset(sum + set[index], index + 1, count + 1);
findSubset(sum, index + 1, count);
}
int main() {
printf("Enter the number of elements in the set: ");
scanf("%d", &n);
printf("Enter the elements of the set: ");
for (i = 0; i < n; i++) {
scanf("%d", &set[i]);
}
printf("Enter the target sum: ");
scanf("%d", &targetSum);
printf("Subsets with sum %d:\n", targetSum);
findSubset(0, 0, 0);
if (!flag) {
printf("There is no solution\n");
}
return 0;
}

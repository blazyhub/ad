#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h> 
int totalSolutions = 0; 
void printSolution(int board[], int N) { 
for (int i = 0; i < N; i++) { 
for (int j = 0; j < N; j++) { 
if (board[i] == j) 
printf(" Q "); 
else 
printf(" - "); 
} 
printf("\n"); 
} 
} 
bool isSafe(int board[], int row, int col) { 
for (int i = 0; i < row; i++) { 
if (board[i] == col || abs(board[i] - col) == abs(i - row)) { 
return false; 
} 
} 
return true; 
} 
void solveNQUtil(int board[], int row, int N) { 
if (row >= N) { 
printSolution(board, N); 
printf("\n"); 
totalSolutions++; 
return; 
} 
for (int col = 0; col < N; col++) { 
if (isSafe(board, row, col)) { 
board[row] = col; 
solveNQUtil(board, row + 1, N); 
board[row] = -1; 
} 
} 
} 
void solveNQ(int N) { 
int board[N]; 
for (int i = 0; i < N; i++) { 
board[i] = -1; 
} 
solveNQUtil(board, 0, N); 
} 
int main() { 
int N; 
printf("Enter the number of queens: "); 
scanf("%d", &N); 
solveNQ(N); 
printf("Total solutions: %d\n", totalSolutions); 
return 0; 
}
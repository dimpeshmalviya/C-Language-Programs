#include <stdio.h>		
#define MAX 10		

void readMatrix(int m, int n, int a[m][n], const char *name) {
printf("Enter %dx%d elements for %s:\n", m, n, name);
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
scanf("%d",&a[i][j]);
}

void printMatrix(int m, int n, int a[m][n]) {
for(int i=0;i<m;i++) {
for(int j=0;j<n;j++)
printf("%d ", a[i][j]);
printf("\n");
}
}

void addMatrix(int m, int n, int a[m][n], int b[m][n], int res[m][n]) {
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
res[i][j] = a[i][j] + b[i][j];
}

void mulMatrix(int m1, int n1, int a[m1][n1], int m2, int n2, int b[m2][n2], int res[m1][n2]) {
for (int i=0;i<m1;i++) {
for (int j=0;j<n2;j++) {
res[i][j] = 0;
for (int k=0;k<n1;k++)
res[i][j] += a[i][k] * b[k][j];
}
}
}

int main() {
int m, n, p, q;
printf("Enter rows & cols of first matrix: ");
scanf("%d %d", &m, &n);
printf("Enter rows & cols of second matrix: ");
scanf("%d %d", &p, &q);
if (n != p) {
printf("Cannot multiply matrices.\n");
return 1;
}

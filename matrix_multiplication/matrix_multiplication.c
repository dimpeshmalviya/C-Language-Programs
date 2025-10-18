#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1 = 2, c1 = 3, r2 = 3, c2 = 2, i, j, k;
    int **A, **B, **C;

    A = (int**)malloc(r1 * sizeof(int*));
    B = (int**)malloc(r2 * sizeof(int*));
    C = (int**)malloc(r1 * sizeof(int*));
    for (i = 0; i < r1; i++) A[i] = (int*)malloc(c1 * sizeof(int));
    for (i = 0; i < r2; i++) B[i] = (int*)malloc(c2 * sizeof(int));
    for (i = 0; i < r1; i++) C[i] = (int*)malloc(c2 * sizeof(int));

    int a[2][3] = {{1,2,3},{4,5,6}};
    int b[3][2] = {{7,8},{9,10},{11,12}};
    for(i=0;i<r1;i++) for(j=0;j<c1;j++) A[i][j]=a[i][j];
    for(i=0;i<r2;i++) for(j=0;j<c2;j++) B[i][j]=b[i][j];

    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            C[i][j]=0;
            for(k=0;k<c1;k++) C[i][j]+=A[i][k]*B[k][j];
        }
    }

    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++) printf("%d ", C[i][j]);
        printf("\n");
    }

    for(i=0;i<r1;i++) free(A[i]);
    for(i=0;i<r2;i++) free(B[i]);
    for(i=0;i<r1;i++) free(C[i]);
    free(A); free(B); free(C);

    return 0;
}

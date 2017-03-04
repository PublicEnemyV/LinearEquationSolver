#include <cstdio>
#include <cstdlib>
#include "LinearEquation.h"
#define DEBUG 0

int main()
{
    LinearEquation leq;
    //dimension of matrix
    int n;
    printf("Input the dimension of the matrix:");
    scanf("%d", &n);

    //input A
    //double A[n][n]; ///!!!potentially dangerous!!!!!
    double *A = (double*)malloc(sizeof(double)*n*n);
    printf("Input the %d*%d A matrix:\n", n, n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%lf", A + i * n + j);
        }
    }
    //double A[10][10]={4,2,-3,-1,2,1,0,0,0,0,8,6,-5,-3,6,5,0,1,0,0,4,2,-2,-1,3,2,-1,0,3,1,0,-2,1,5,-1,3,-1,1,9,4,-4,2,6,-1,6,7,-3,3,2,3,8,6,-8,5,7,17,2,6,-3,5,0,2,-1,3,-4,2,5,3,0,1,16,10,-11,-9,17,34,2,-1,2,2,4,6,2,-7,13,9,2,0,12,4,0,0,-1,8,-3,-24,-8,6,3,-1};

    //Debug output A
#if DEBUG
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            printf("%f ",*(A + i * n + j));
        }
        printf("\n");
    }
#endif // DEBUG

    //input vector b
    printf("Input the %d b vector:\n", n);
    double *b = (double*)malloc(sizeof(double) * n);
    for(int i = 0; i < n; ++i) {
        scanf("%lf", b + i);
    }
    //double b[10]={5,12,3,2,3,46,13,38,19,-21};

    double *x = (double*)malloc(sizeof(double) * n);
    if(leq.Solve(A, b, n, x, "GaussianElimination") != 0)
        printf("Error: The unique solution does not exist! Yay!\n");
    else {
        // Output result
        printf("The solution vector is:\n");
        for(int k = 0; k < n; ++k) {
            printf("x%d=%f\n", k, *(x + k));
        }
    }
    free(A);
    free(b);
    free(x);
    return 0;
}

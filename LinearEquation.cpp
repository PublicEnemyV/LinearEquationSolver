#include "LinearEquation.h"
#include <string>
#include <cstdlib>

using namespace std;

int LinearEquation::Solve(double *A, double *b, int n, double *x, string method) {
    if(method == "GaussianElimination" || method == "SequentialGaussianElimination" || method == "PCAGaussianElimination") {
        return GaussianElimination(A, b, n, x, method);
    }
}
int LinearEquation::GaussianElimination(double *A, double *b, int n, double *x, string method) {
    if(method == "SequentialGaussianElimination")
        return SequentialGaussianElimination(A, b, n, x);
    else
        return PCAGaussianElimination(A, b, n, x);
}
int LinearEquation::SequentialGaussianElimination(double *A, double *b, int n, double *x) {
        //transform to upper triangular matrix
    double trym, maxm, used;
    int rowm;
    for(int k = 0; k < n; ++k) {
#if DEBUG
        printf(">>>>>>>>>>>>>>>%d>>>>>>>>>>>>>>>\n", k);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                printf("%f ",*(A + i * n + j));
            }
            printf("%f ", b + i);
            printf("\n");
        }
        printf("<<<<<<<<<<<<<<<%d<<<<<<<<<<<<<<<\n", k);
#endif // DEBUG

        trym = *(A + k * n + k);
        if(trym != 0)
            maxm = trym;
        else
            return ReducedRankOrMethodNotWorking;
        //primary transformation
        if(rowm > k) {
            for(int j = k; j < n; ++j) {
                double temp;
                temp = *(A + k * n + j);
                *(A + k * n + j) = *(A + rowm * n + j);
                *(A + rowm * n + j) = temp;
            }
            double temp;
            temp = *(b + k);
            *(b + k) = *(b + rowm);
            *(b + rowm) = temp;
        }
        double *l = (double*)malloc(sizeof(double) * n);
        for(int i = k + 1; i < n; ++i) {
            *(l + i) = *(A + i * n + k) / *(A + k * n + k);
            for(int j = k; j < n; ++j) { //k+1
                *(A + i * n + j) = *(A + i * n + j) - *(l + i) **(A + k * n + j);
            }
            *(b + i) = *(b + i) - *(l + i) **(b + k);
        }
        free(l);
    }

    // back substitution
    for(int k = n - 1; k >= 0; --k) {
        double sum = 0;
        int j = n - 1;
        while(j > k) {
            sum += *(x + j) **(A + k * n + j);
            --j;
        }
        *(x + k) = (*(b + k) - sum) / *(A + k * n + k);
    }

    return OK;
}
int LinearEquation::PCAGaussianElimination(double *A, double *b, int n, double *x) {
    //transform to upper triangular matrix
    double trym, maxm, used;
    int rowm;
    for(int k = 0; k < n; ++k) {
#if DEBUG
        printf(">>>>>>>>>>>>>>>%d>>>>>>>>>>>>>>>\n", k);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                printf("%f ",*(A + i * n + j));
            }
            printf("%f ", b + i);
            printf("\n");
        }
        printf("<<<<<<<<<<<<<<<%d<<<<<<<<<<<<<<<\n", k);
#endif // DEBUG

        //select column PCA
        trym = *(A + k * n + k);
        rowm = k;
        for(int i = k + 1; i < n; ++i) {
            used = *(A + i * n + k);
            if (fabs(used) > fabs(trym)) {
                trym = used;
                rowm = i;
            }
        }
        if(trym != 0)
            maxm = trym;
        else
            return ReducedRank;
        //primary transformation
        if(rowm > k) {
            for(int j = k; j < n; ++j) {
                double temp;
                temp = *(A + k * n + j);
                *(A + k * n + j) = *(A + rowm * n + j);
                *(A + rowm * n + j) = temp;
            }
            double temp;
            temp = *(b + k);
            *(b + k) = *(b + rowm);
            *(b + rowm) = temp;
        }
        double *l = (double*)malloc(sizeof(double) * n);
        for(int i = k + 1; i < n; ++i) {
            *(l + i) = *(A + i * n + k) / *(A + k * n + k);
            for(int j = k; j < n; ++j) { //k+1
                *(A + i * n + j) = *(A + i * n + j) - *(l + i) **(A + k * n + j);
            }
            *(b + i) = *(b + i) - *(l + i) **(b + k);
        }
        free(l);
    }

    // back substitution
    for(int k = n - 1; k >= 0; --k) {
        double sum = 0;
        int j = n - 1;
        while(j > k) {
            sum += *(x + j) **(A + k * n + j);
            --j;
        }
        *(x + k) = (*(b + k) - sum) / *(A + k * n + k);
    }

    return OK;
}

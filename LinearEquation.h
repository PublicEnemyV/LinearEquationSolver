#ifndef GAUSSIANELIMINATION_H_INCLUDED
#define GAUSSIANELIMINATION_H_INCLUDED

#include <string>
#include <cmath>

enum {
    OK,
    ReducedRank,
    ReducedRankOrMethodNotWorking
};

class LinearEquation
{
public:
    int Solve(double *A, double *b, int n, double *x, std::string method);
private:
    int GaussianElimination(double *A, double *b, int n, double *x, std::string method);
    int PCAGaussianElimination(double *A, double *b, int n, double *x);
    int SequentialGaussianElimination(double *A, double *b, int n, double *x);
};

#endif // GAUSSIANELIMINATION_H_INCLUDED

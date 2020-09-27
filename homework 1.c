#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdbool.h>

#define SS_INF_ROOTS -1

// ====================================================================
//! Function for checking the correctness of the input
//!
//! @param [in] coef - Pointer of the coefficient
// ====================================================================
void get_double(double*);


// ====================================================================
//! Function, which solves a square equation
//!
//! @param [in] a - the 1-st coefficient
//! @param [in] b - the 2-nd coefficient
//! @param [in] c - the 3-rd coefficient
//! @param [in] x1 - Pointer of the 1-st root
//! @param [in] x2 - Pointer of the 2-nd root
// ====================================================================
int Squaresolver(double, double, double, double*, double*);

int main()
{
    printf("This program can solve square equation, which have the following form: \n ax^2 + bx + c \n \n");

    printf("\nPlease enter the coefficient: a b c \n");

    double a = 0, b = 0, c = 0;

    printf("Enter a: ");
    get_double(&a);

    printf("Enter b: ");
    get_double(&b);

    printf("Enter c: ");
    get_double(&c);

    double x1 = 0, x2 = 0;
    int nRoots = Squaresolver(a, b, c, &x1, &x2);

    switch(nRoots)
    {
        case 0:
            printf("\nResult: No roots \n");
            break;

        case 1:
            printf("\nResult: x = %lg \n", x1);
            break;

        case 2:
            printf("\nResult: x1 = %lg, x2 = %lg \n", x1, x2);
            break;

        case 3:
            printf("\nResult: No valid solutions \n");
            break;

        case SS_INF_ROOTS:
            printf("\nResult: Any number");
            break;

        default:
                printf("\nResult: main(): ERROR: nRoots = %d \n", nRoots);
    }

    printf("\nHave a nice day!");

    return 0;
}

void get_double(double* coef)
{
    double x;
    char answer[256];

    fgets(answer, sizeof(answer), stdin);

    while (sscanf(answer, "%lf", &x) != 1)
    {
        printf("What did you enter? We didn't understand you? Please, try again. \n");
        fgets(answer, sizeof(answer), stdin);
    }

    *coef = x;
}

int Squaresolver(double a, double b, double c, double *x1, double *x2)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (a == 0)
    {
        if (b == 0)
        {
            return (c == 0) ? SS_INF_ROOTS : 0;
        }
        else /*if (b != 0)*/
        {
            *x1 = -1 * (c / b);
            return 1;
        }
    } /*if (a != 0)*/
    else
    {
        double desc = b * b - 4 * a * c;

        if (desc == 0)
        {
            *x1 = -1 * b / (2 * a);
            *x2 = -1 * b / (2 * a);

            return 1;
        }
        else /*if (desc != 0)*/
        {
            if (desc < 0)
                return 3;
            else /*if (desc >= 0)*/
            {
                double square_desc = sqrt(desc);

                *x1 = (-1 * b - square_desc) / (2 * a);
                if (abs(*x1) < 0.00000001) *x1 = 0;

                *x2 = (-1 * b + square_desc) / (2 * a);
                if (abs(*x2) < 0.00000001) *x2 = 0;

            return 2;
            }
        }
    }
}





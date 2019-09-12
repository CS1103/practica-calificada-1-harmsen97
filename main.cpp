#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdio.h>
#include "Polynomial.h"
#include <iostream>



#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    int coefficient, exponent, i, n;
    FILE *fp1, *fp2;
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    if (!fp1 || !fp2) {
        printf("Unable to open file\n");
        fcloseall();
        exit(0);
    }


    while (fscanf(fp1, "%d%d", &coefficient, &exponent) != EOF) {
        polynomial_insert(&hPtr1, coefficient, exponent);
    }


    while (fscanf(fp2, "%d%d", &coefficient, &exponent) != EOF) {
        polynomial_insert(&hPtr2, coefficient, exponent);
    }
    printf("Polynomial Expression 1: ");
    polynomial_walkList(hPtr1);
    printf("Polynomial Expression 2: ");
    polynomial_walkList(hPtr2);

    polynomial_multiply(&hPtr3, hPtr1, hPtr2);

    printf("Output:");
    polynomial_walkList(hPtr3);

    hPtr1 = polynomial_deleteList(hPtr1);
    hPtr2 = polynomial_deleteList(hPtr2);
    hPtr3 = polynomial_deleteList(hPtr3);

    return 0;
}
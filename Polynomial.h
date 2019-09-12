//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <vector>
using namespace std;

#include<stdio.h>
#include<stdlib.h>

struct node {
    int coefficient, exponent;
    struct node *next;
};

struct node *hPtr1, *hPtr2, *hPtr3;


struct node * buildNode(int coefficient, int exponent) {
    struct node *ptr = (struct node *) malloc(sizeof (struct node));


    ptr->coefficient = coefficient;
    ptr->exponent = exponent;
    ptr->next = NULL;


    return ptr;
}


void polynomial_insert(struct node ** myNode, int coefficient, int exponent) {
    struct node *lPtr, *pPtr, *qPtr = *myNode;

    lPtr = buildNode(coefficient, exponent);



    if (*myNode == NULL || (*myNode)->exponent < exponent) {
        *myNode = lPtr;
        (*myNode)->next = qPtr;

    }


    while (qPtr) {
        pPtr = qPtr;
        qPtr = qPtr->next;
        if (!qPtr) {
            pPtr->next = lPtr;
            break;
        } else if ((exponent < pPtr->exponent) && (exponent > qPtr->exponent)) {

            lPtr->next = qPtr;
            pPtr->next = lPtr;
            break;
        }
    }

}


void polynomial_add(struct node **n1, int coefficient, int exponent) {
    struct node *x = NULL, *temp = *n1;
    if (*n1 == NULL || (*n1)->exponent < exponent) {
        /
        *n1 = x = buildNode(coefficient, exponent);
        (*n1)->next = temp;
    } else {
        while (temp) {
            if (temp->exponent == exponent) {

                temp->coefficient = temp->coefficient + coefficient;

            }
            if (temp->exponent > exponent && (!temp->next ||
                                              temp->next->exponent < exponent)) {
                /* inserting in the middle or end */
                x = buildNode(coefficient, exponent);
                x->next = temp->next;
                temp->next = x;

            }
            temp = temp->next;
        }
        x->next = NULL;
        temp->next = x;
    }
}

void polynomial_multiply(struct node **n1, struct node *n2, struct node *n3) {
    struct node * temp;
    int coefficient, exponent;

    temp = n3;


    if (!n2 && !n3)
        return;

    if (!n2) {
        *n1 = n3;
    } else if (!n3) {


        *n1 = n2;
    } else {
        while (n2) {
            while (n3) {

                coefficient = n2->coefficient * n3->coefficient;
                exponent = n2->exponent + n3->exponent;
                n3 = n3->next;

                polynomial_add(n1, coefficient, exponent);
            }
            n3 = temp;
            n2 = n2->next;
        }
    }

}


struct node * polynomial_deleteList(struct node *ptr) {
    struct node *temp;
    while (ptr){
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    return NULL;
}

void polynomial_walkList(struct node *ptr) {
    int i = 0;
    while (ptr) {
        printf("%dX^%d %c ", ptr->coefficient,
               ptr->exponent, ptr->next?'+':'\0');
        ptr = ptr->next;
        i++;
    }
    printf("\n");

}




#endif //POLINOMIO_POLINOMIO_H

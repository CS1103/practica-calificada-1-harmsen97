//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H
#include <vector>
#include <iostream>
using namespace std;

class Polynomial {
    private:

        int coeff,power;
        Polynomial* next;


    public:
    Polynomial* add(Polynomial* start, int coeff, int power)
    {
        Polynomial* newnode = new Polynomial;
        newnode->coeff = coeff;
        newnode->power = power;
        newnode->next = NULL;

        if (start == NULL)
            return newnode;

        Polynomial* ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;

        return start;
    }

    void removeDuplicates(Polynomial* start)
    {
        Polynomial *ptr1, *ptr2, *dup;
        ptr1 = start;

        while (ptr1 != NULL && ptr1->next != NULL) {
            ptr2 = ptr1;

            while (ptr2->next != NULL) {

                if (ptr1->power == ptr2->next->power) {

                    ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;

                    delete (dup);
                }
                else
                    ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
    
    Polynomial* MultiplicacionConUnPolinomio(Polynomial* poly1, Polynomial* poly2,
                   Polynomial* poly3)
    {
        Polynomial *ptr1, *ptr2;
        ptr1 = poly1;
        ptr2 = poly2;
        while (ptr1 != NULL) {
            while (ptr2 != NULL) {
                int coeff, power;
                
                coeff = ptr1->coeff * ptr2->coeff;
                power = ptr1->power + ptr2->power;
                poly3 = add(poly3, coeff, power);
                ptr2 = ptr2->next;
            }
            
            ptr2 = poly2;
            ptr1 = ptr1->next;
        }

        removeDuplicates(poly3);

        return poly3;
    }

    Polynomial* MultiplicacionConUnaConstante(Polynomial* poly1,int constante,
                                             Polynomial* poly3)
    {

        Polynomial *ptr1;
        ptr1 = poly1;
        while (ptr1 != NULL) {
                int coeff, power;
                coeff = ptr1->coeff *constante;
                power = ptr1->power;
                poly3 = add(poly3, coeff, power);
                ptr1 = ptr1->next;
        }

        removeDuplicates(poly3);

        return poly3;
    }

    int gradoDelPolinomio{
            return power:
    };


    Polynomial* SumaDePolinomios(Polynomial *poly1, Polynomial *poly2, Polynomial *poly)
    {
        while(poly1->next && poly2->next)
        {
            // If power of 1st polynomial is greater then 2nd, then store 1st as it is
            // and move its pointer
            if(poly1->power > poly2->power)
            {
                poly->power = poly1->power;
                poly->coeff = poly1->coeff;
                poly1 = poly1->next;
            }

                // If power of 2nd polynomial is greater then 1st, then store 2nd as it is
                // and move its pointer
            else if(poly1->power < poly2->power)
            {
                poly->power = poly2->power;
                poly->coeff = poly2->coeff;
                poly2 = poly2->next;
            }

                // If power of both polynomial numbers is same then add their coefficients
            else
            {
                poly->power = poly1->power;
                poly->coeff = poly1->coeff+poly2->coeff;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }

            // Dynamically create new node
            poly->next = add(poly,0,0);
            poly = poly->next;
            poly->next = NULL;
        }
        while(poly1->next || poly2->next)
        {
            if(poly1->next)
            {
                poly->power = poly1->power;
                poly->coeff = poly1->coeff;
                poly1 = poly1->next;
            }
            if(poly2->next)
            {
                poly->power = poly2->power;
                poly->coeff = poly2->coeff;
                poly2 = poly2->next;
            }
            poly->next = add(poly,0,0);
            poly = poly->next;
            poly->next = NULL;
        }

        return poly;
    }


    Polynomial* SumaDePolinomioConUnaConstante(Polynomial *poly1, int constante, Polynomial *poly)
    {
        while(poly1->next)
        {
            if(poly1->power > 0)
            {
                poly->power = poly1->power;
                poly->coeff = poly1->coeff;
                poly1 = poly1->next;
            }

            else if(poly1->power < 0)
            {
                poly->power = 0;
                poly->coeff = constante;
            }

            else
            {
                poly->power = poly1->power;
                poly->coeff = poly1->coeff+constante;
                poly1 = poly1->next;
            }

            // Dynamically create new node
            poly->next = add(poly,0,0);
            poly = poly->next;
            poly->next = NULL;
        }
        while(poly1->next)
        {
            if(poly1->next)
            {
                poly->power = poly1->power;
                poly->coeff = poly1->coeff;
                poly1 = poly1->next;
            }
            poly->next = add(poly,0,0);
            poly = poly->next;
            poly->next = NULL;
        }

        return poly;
    }

    Polynomial* PotenciaDeUnPolinomio(Polynomial* poly1,int potencia,
                                             Polynomial* poly3)
    {
        int i=0;
        while(i<potencia) {
            Polynomial *ptr1, *ptr2;
            ptr1 = poly1;
            ptr2 = poly1;
            while (ptr1 != NULL) {
                while (ptr2 != NULL) {
                    int coeff, power;

                    coeff = ptr1->coeff * ptr2->coeff;
                    power = ptr1->power + ptr2->power;
                    poly3 = add(poly3, coeff, power);
                    ptr2 = ptr2->next;
                }

                ptr2 = poly1;
                ptr1 = ptr1->next;
            }

            removeDuplicates(poly3);


            i++;
        }return poly3;

    }

    void mostrar(Polynomial* ptr)
    {
        while (ptr->next != NULL) {
            cout << ptr->coeff << "x^" << ptr->power << " + ";

            ptr = ptr->next;
        }
        cout << ptr->coeff << "\n";
    }

};

#endif //POLINOMIO_POLINOMIO_H



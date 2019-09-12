#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Polynomial.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{

    Polynomial *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

    //Creacion del polinomio: 3x^2 + 5x^1 + 6
    poly1 = poly1->add(poly1, 3, 2);
    poly1 = poly1->add(poly1, 5, 1);
    poly1 = poly1->add(poly1, 6, 0);

    // Creacion del segundo polinomio: 6x^1 + 8
    poly2 = poly2->add(poly2, 6, 1);
    poly2 = poly2->add(poly2, 8, 0);


    cout << "Primer polinomio:"<<endl;
    poly1->mostrar(poly1);

    cout << "Segundo Polinomio:"<<endl;
    poly2->mostrar(poly2);

    //Multiplicacion de los dos polinomios
    poly3 = poly3->MultiplicacionConUnPolinomio(poly1, poly2, poly3);

    cout << "Multiplicacion de los dos polinomios:";
    poly3->mostrar(poly3);

    //Multiplicacion con una constante
    poly3=poly3->MultiplicacionConUnaConstante(poly1,10,poly3);
    cout<<"Multiplicaion con una constante"<<endl;
    poly3->mostrar(poly3);





    return 0;
} */
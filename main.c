// main.c
#include <stdio.h>
#include "poly.h"

int main()
{
    Node *p1 = NULL, *p2 = NULL;

    // Example: p1 = 3x^2 + 2x + 5
    insertTerm(&p1, 3, 2);
    insertTerm(&p1, 2, 1);
    insertTerm(&p1, 5, 0);

    // Example: p2 = 4x^3 + x + 1
    insertTerm(&p2, 4, 3);
    insertTerm(&p2, 1, 1);
    insertTerm(&p2, 1, 0);

    printf("P1: ");
    displayPoly(p1);

    printf("P2: ");
    displayPoly(p2);

    Node *sum = addPoly(p1, p2);
    printf("Sum: ");
    displayPoly(sum);

    Node *prod = multiplyPoly(p1, p2);
    printf("Product: ");
    displayPoly(prod);

    freePoly(p1);
    freePoly(p2);
    freePoly(sum);
    freePoly(prod);

    return 0;
}

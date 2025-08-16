// poly.c
#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

// Create a new term
Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term sorted by exponent (descending order)
void insertTerm(Node **poly, int coeff, int exp)
{
    if (coeff == 0)
        return;

    Node *newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp)
    {
        newNode->next = *poly;
        *poly = newNode;
    }
    else
    {
        Node *temp = *poly;
        while (temp->next && temp->next->exp >= exp)
        {
            if (temp->next->exp == exp)
            {
                temp->next->coeff += coeff;
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Display polynomial
void displayPoly(Node *poly)
{
    if (!poly)
    {
        printf("0\n");
        return;
    }
    while (poly)
    {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly)
            printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
Node *addPoly(Node *p1, Node *p2)
{
    Node *result = NULL;
    while (p1 || p2)
    {
        if (p1 && (!p2 || p1->exp > p2->exp))
        {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p2 && (!p1 || p2->exp > p1->exp))
        {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return result;
}

// Multiply two polynomials
Node *multiplyPoly(Node *p1, Node *p2)
{
    Node *result = NULL;
    for (Node *a = p1; a; a = a->next)
    {
        for (Node *b = p2; b; b = b->next)
        {
            insertTerm(&result, a->coeff * b->coeff, a->exp + b->exp);
        }
    }
    return result;
}

void freePoly(Node *poly)
{
    while (poly)
    {
        Node *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

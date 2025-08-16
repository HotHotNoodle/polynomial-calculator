// poly.h
#ifndef POLY_H
#define POLY_H

typedef struct Node
{
    int coeff; // coefficient
    int exp;   // exponent
    struct Node *next;
} Node;

// Core functions
Node *createNode(int coeff, int exp);
void insertTerm(Node **poly, int coeff, int exp);
void displayPoly(Node *poly);
Node *addPoly(Node *p1, Node *p2);
Node *multiplyPoly(Node *p1, Node *p2);
void freePoly(Node *poly);

#endif

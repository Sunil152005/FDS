#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    float coef;
    int exp;
    node *next;
};

void insert_p(Node *&poly, float coef, int exp)
{
    Node *newn = new Node;
    newn->coef = coef;
    newn->exp = exp;
    newn->next = NULL;

    if (poly == NULL)
    {
        poly = newn;
    }
    else
    {
        Node *temp = poly;
        while (temp->next != NULL)
            {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void display(Node *poly)
{
    Node *temp = poly;
    while (temp != NULL)
    {
        cout << temp->coef << "x^" << temp->exp;
        if (temp->next != NULL)
        {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}


Node* addPoly(Node *poly1, Node *poly2)
{
    Node *polySum = NULL;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            insert_p(polySum, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            insert_p(polySum, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            float sumCoef = poly1->coef + poly2->coef;
            if (sumCoef != 0)
            {
                insert_p(polySum, sumCoef, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }


    while (poly1 != NULL)
    {
        insert_p(polySum, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }


    while (poly2 != NULL)
    {
        insert_p(polySum, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    return polySum;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *polySum = NULL;
    int n1, n2, exp, i;
    float coef;

    cout << "Enter the number of terms in poly1: ";
    cin >> n1;

    for (i = 0; i < n1; i++)
    {
        cout<< "Enter the coefficient: ";
        cin >> coef;
        cout << "Enter the exponent: ";
        cin >> exp;

        insert_p(poly1, coef, exp);
    }

    cout << "poly1: " << std::endl;
    display(poly1);

    cout << "Enter the number of terms in poly2: ";
    cin >> n2;

    for (i = 0; i < n2; i++)
    {
       cout << "Enter the coefficient: ";
        cin >> coef;
        cout << "Enter the exponent: ";
        cin >> exp;

        insert_p(poly2, coef, exp);
    }

    cout << "poly2: " << endl;
    display(poly2);


    polySum = addPoly(poly1, poly2);

    cout << "Sum of poly1 and poly2: " << endl;
    display(polySum);

    return 0;
}

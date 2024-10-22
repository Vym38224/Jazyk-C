// Definujte strukturu pro reprezentaci zlomku. Pro dva zadané zlomky vypište jejich součet, rozdíl a součin.

#include <stdio.h>

typedef struct
{
    int numerator;
    int denominator;
    int sum;
    int difference;
    int product;
} Fraction;

int main()
{
    Fraction a, b, sum, difference, product;

    printf("Enter numerator of first fraction: ");
    scanf("%d", &a.numerator);
    printf("Enter denominator of first fraction: ");
    scanf("%d", &a.denominator);
    printf("Enter numerator of second fraction: ");
    scanf("%d", &b.numerator);
    printf("Enter denominator of second fraction: ");
    scanf("%d", &b.denominator);

    // Calculate sum
    sum.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    sum.denominator = a.denominator * b.denominator;

    // Calculate difference
    difference.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    difference.denominator = a.denominator * b.denominator;

    // Calculate product
    product.numerator = a.numerator * b.numerator;
    product.denominator = a.denominator * b.denominator;

    printf("Sum: %d/%d\n", sum.numerator, sum.denominator);
    printf("Difference: %d/%d\n", difference.numerator, difference.denominator);
    printf("Product: %d/%d\n", product.numerator, product.denominator);

    return 0;
}
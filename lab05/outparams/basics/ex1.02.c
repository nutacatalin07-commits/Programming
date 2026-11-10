#include <stdio.h>

int main(){
    int a = 1, b = 2;
    int *p = &a;
    *p = 100;
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    p = &b;
    *p = 200;
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    printf("Size of int is: %zu bytes\n", sizeof(int));
    printf("Size of pointer is: %zu bytes\n", sizeof(p));
    printf("Size of double is: %zu bytes\n", sizeof(double));
    printf("Size of pointer to double is: %zu bytes\n", sizeof(double*));
    return 0;
    //la pasul 3,schimba intai adresa la care pointeaza p,apoi schimba valoarea la care pointeaza p,adica b,adica pe ambele
    //la pasul 2 se schimba doar valoarea de la adresa lui p,care e a si a devine 100
    //si int si double sunt pointeri

}
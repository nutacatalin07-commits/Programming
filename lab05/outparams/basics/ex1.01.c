#include <stdio.h>

int main(){
    int x = 5;
    int *p = &x;
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value pointed to by p: %d\n", *p);
    printf("Address pointed to by p: %p\n", (void*)p);
    printf("Address of p: %p\n", (void*)&p);
    *p = 10;
    printf("New value of x: %d\n", x);
    return 0;
    //sunt egale valoare lui x si valoare la care pointeaza p pentru ca p pointeaza spre adresa lui x unde il gaseste pe 5;
    //sunt egale adresa lui x si adresa la care pointeza p pentru ca p pointeaza spre adresa lui x;
    //x se schimba in 10 pentru ca p pointeaza spre adresa lui x si ii schimbam valoarea la care pointeaza p;
    //da s au schimbat adresele
}
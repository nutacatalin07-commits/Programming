#include <stdio.h>

void swap_val(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_ptr(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort3(int *a, int *b, int *c){
   if(*a > *b){
        swap_ptr(a, b);
   }
    if(*a > *c){
          swap_ptr(a, c);
   }
   if(*b > *c){
        swap_ptr(b, c);
   }
} 

int main(){
    int x = 5, y = 10;
    int a ,b , c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Before swap_val: x = %d, y = %d\n", x, y);
    swap_val(x, y);
    printf("After swap_val: x = %d, y = %d\n", x, y);
    printf("Before swap_ptr: x = %d, y = %d\n", x, y);
    swap_ptr(&x, &y);
    printf("After swap_ptr: x = %d, y = %d\n", x, y);
    //swap_ptr merge pentru ca se foloseste adresa variabilelor, deci se modifica valorile lor, in timp 
    //ce swap_val nu functioneaza pentru ca se lucreaza cu copii ale valorilor, nu cu valorile originale
    sort3(&a, &b, &c);
    printf("Sorted: a = %d, b = %d, c = %d\n", a, b, c);
}


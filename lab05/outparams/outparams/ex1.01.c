#include <stdio.h>

int divide(int a, int b , int *quot, int *rem){
    if(b == 0){
        return 0;
    }
    else{
        *quot = a / b;
        *rem = a % b;
        return 1;
    }
}

int main(){
    int a , b , quot , rem;
    printf("Enter two numbers: ");
    scanf("%d %d", &a , &b);
    if(divide(a , b , &quot, &rem) == 1){
        printf("%d = %d * %d + %d\n", a , b , quot , rem);
    }
    else{
        printf("Division by 0.\n");
    }
}
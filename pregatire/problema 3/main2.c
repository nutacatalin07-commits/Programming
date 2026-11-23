#include <stdio.h>

#include <string.h>

void is_positive(int n){
    if(n >= 0){
        printf("The user has entered a positive number\n");
    }
    else{
        printf("You have entered an invalid input.Please enter another number\n");
    }
}

int sum_of_divisors(int n){
    int s = 0;
    int i;
    for(i = 1; i <= n - 1; i++){
        if(n % i == 0){
            s = s + i;
        }
    }
    return s;
}

int main(){

    int a;
    printf("Please enter a number:");
    scanf("%d", &a);
    is_positive(a);
    if(a == sum_of_divisors(a)){
        printf("a is a perfect number\n");
    }
    if(a > sum_of_divisors(a)){
        printf("a is abundant\n");
    }
    if(a < sum_of_divisors(a)){
        printf("a is deficient\n");
    }
    printf("Please enter another number:");
    int b;
    scanf("%d", &b);
    if(sum_of_divisors(a) == sum_of_divisors(b)){
        printf("The numbers are amicable\n");
    }
    else{
        printf("The numbers are not amicable\n");
    }

    return 0;
}
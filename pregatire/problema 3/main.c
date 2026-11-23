#include <stdio.h>

int greatest_of_3(int a, int b, int c){
    int greatest;
    if(a >= b && a >= c){
        greatest = a;
    }
    else if(b >= a && b >= c){
        greatest = b;
    }
    else if(c >= a && c >= b){
        greatest = c;
    }
    return greatest;
}

int main(){
    int a, b, c;
    printf("Enter three values:");
    scanf("%d %d %d", &a, &b, &c);
    printf("The biggest of them is %d\n", greatest_of_3(a, b, c));
}
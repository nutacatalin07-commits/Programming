#include <stdio.h>
void leap_year(int n){
    if(n % 400 == 0){
        printf("The year chosed is leap\n");
    }
    else if(n % 4 == 0 && n % 100 != 0){
        printf("The year chosed is leap\n");
    }
    else{
        printf("The year is not leap\n");
    }
}

int main(){
    int a;
    printf("Choose a year:");
    scanf("%d", &a);
    leap_year(a);
    return 0;
}
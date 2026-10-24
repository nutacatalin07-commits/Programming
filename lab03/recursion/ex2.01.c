#include <stdio.h>
unsigned int digit_sum(unsigned int n){
   if(n==0){
    return 0;
   }
   return n%10+digit_sum(n/10);
}
unsigned int checksum(unsigned int serial){
    return digit_sum(serial/10)%10;
}
int is_valid_serial(unsigned int serial){
    if(serial%10==checksum(serial)) return 1;
    else return 0;
}
int main(){
    int n;
    if(scanf("%d", &n)==1 && n>=0){
        if(is_valid_serial(n)==1){
            printf("Serial %04d : OK", n);
        }
        else{
            printf("Serial %04d : Corrupted", n);
        }
    }
    else{
        printf("Error: serial must be a non-negative number");
        return 1;
    }
}
#include <stdio.h>
void print_binary(unsigned int value, int bits){
    if(bits==0){
        return;
    }
    print_binary(value>>1,bits-1);
    printf("%u",value & 1);
}
int main(){
    int a,b,c,d;
    if(scanf("%d.%d.%d.%d", &a,&b,&c,&d)!=4){
        printf("Error:invalid address\n");
        return 1;
    }
    if (a<0 || a>255 || b<0 || b>255 || c<0 || c>255 || d<0 || d>255) {
        printf("Error: octet out of range\n");
        return 1;
    }
    print_binary(a,8);
    printf(".");
    print_binary(b,8);
    printf(".");
    print_binary(c,8);
    printf(".");
    print_binary(d,8);
    printf("\n");

    return 0;
}
//nu inteleg f bn cum functioneaza value>>1 si value & 1,scrierile astea doua

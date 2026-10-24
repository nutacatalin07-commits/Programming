#include <stdio.h>
void swap(int *a,int *b){
    int r;
    r=*a;
    *a=*b;
    *b=r;
    printf("Inside swap: a=%d b=%d \n",*a,*b);
}
int clamp(int value, int lo, int hi)
{
    if (value>hi)
        return hi;
    if (value<lo)
        return lo;
    return value;
}
int main(){
    int x,y;
    scanf("%d %d" ,&x, &y);
    printf("Before: x=%d y=%d \n",x,y);
    swap(&x,&y);
    printf("After swap(x,y) : x=%d y=%d \n",x,y);
    printf("Clamped reading: %d\nS",clamp(150,0,100));
}

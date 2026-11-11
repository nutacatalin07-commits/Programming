#include <stdio.h>

#define N 5

int sum_array(int a[N] , int n){
    int s = 0, *p;
    for(p = a; p < a + n; p++){
        s = s + *p;
    }
    return s;
}

int main(){
    int n, v[N];
    printf("Enter the number of elements (max %d): ", N);
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    printf("Sum: %d\n", sum_array(v, n));
    return 0;
}
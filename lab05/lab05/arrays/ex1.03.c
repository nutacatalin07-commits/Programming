#include <stdio.h>

#define N_MAX 100

void swap_array(int v[N_MAX], int n){
    int  *left = v;
    int *right = v + n - 1;
    while(left < right){
        int temp = *left;
        *left = * right;
        *right = temp;
        left++;
        right--;
    }
}

int main(){
    int n , v[N_MAX];
    printf("Enter the number of elements (max %d): ", N_MAX);
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    swap_array(v, n);
    printf("Reversed array:");
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
        printf(" ");
    }
    return 0;
}
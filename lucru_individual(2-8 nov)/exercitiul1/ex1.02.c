#include <stdio.h>

#define MAX_SIZE 100

int read_array(int v[]) {
    int n;

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        printf("Error: invalid size\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    return n;
}

int delete_element(int n, int v[], int element){
    int i, j;
    for(i = 0; i < n; i++){
        if(v[i] == element){
            for(j = i; j < n - 1; j++){
                v[j] = v[j + 1];
            }
            n--;
            i--;
        }
    }
    return n;
}

int main(){
    int v[MAX_SIZE], n, element;

    n = read_array(v);
    if (n < 0) {
        return 1;
    }

    printf("Enter the element to delete: ");
    scanf("%d", &element);

    delete_element(n, v, element);

    printf("Array after deletion: ");
    for (int i = 0; i < delete_element(n, v, element); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
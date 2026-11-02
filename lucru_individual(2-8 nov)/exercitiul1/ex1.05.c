#include <stdio.h>

#include <stdlib.h>

int** matrix(int n){
    int **a = malloc(n *sizeof(int *));
    for(int i = 0; i < n;i++){
        a[i] = malloc(n * sizeof(int));
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(i > j){
                a[i][j] = 1;
            }
            else if(i < j){
                a[i][j] = 2;
            }
            else if(i == j){
                a[i][j] = 3;
            }
            else if((i + j) == n - 1){
                a[i][j] = 4;
            }

        }
    }
    return a;
}

int main(){
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int **matrix_result = matrix(n);

    printf("Generated Matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix_result[i][j]);
        }
        printf("\n");
    }
    
    for(int i = 0; i < n; i++){
        free(matrix_result[i]);
    }
    free(matrix_result);

    return 0;
}
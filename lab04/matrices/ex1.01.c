#include <stdio.h>

#define NMAX 20

int read_matrix(int *n, int *m, int a[NMAX][NMAX]) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX || scanf("%d", m) != 1 || *m < 1 || *m > NMAX) {
        printf("Error: invalid size\n");
        return 0;
    }
    
    for (int i = 0; i < *n; i++) {          
        for (int j = 0; j < *m; j++) {       
            scanf("%d", &a[i][j]);
            if(a[i][j] != 0 && a[i][j] != 1){
                return 0;
            }
        }
    }
    
    return 1;
}

void print_image(int n, int m, int a[NMAX][NMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                printf(" %4c", '#');        
            } else {
                printf(" %4c", '.');
            }
        }
        printf("\n");                   
    }
}

void transpose(int n, int m, int a[NMAX][NMAX], int t[NMAX][NMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[j][i] = a[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (t[i][j] == 1) {
                printf(" %4c", '#');        
            } else {
                printf(" %4c", '.');
            }
        }
        printf("\n");                  
    }
}

void reverse_rows(int n, int m, int a[NMAX][NMAX]){
    int i, j,temp;
    for(i = 0; i < m; i++){
        for(j = 0; j < n/2; j++){
            temp=a[i][j];
            a[i][j]=a[i][n-j-1];
            a[i][n-j-1]=temp;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                printf(" %4c", '#');        
            } else {
                printf(" %4c", '.');
            }
        }
        printf("\n");                  
    }
}

int main() {
    int n, m, a[NMAX][NMAX], t[NMAX][NMAX];
    
    if (read_matrix(&n, &m, a) == 0) {
        printf("Error: pixels must be 0 or 1");
        return 0;
    }
    
    print_image(n, m, a);
    printf("\n");
    transpose(n, m, a, t);
    printf("\n");
    reverse_rows(n, m, t);
    
    return 0;
}
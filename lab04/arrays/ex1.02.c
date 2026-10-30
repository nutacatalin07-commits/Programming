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
int sum_array(int n, int v[]){
    int s=0,i;
    for(int i = 0; i < n; i++){
        s=s+v[i];
    }
    return s;
}

int min_array(int n, int v[]){
    int i,min;
    min=v[0];
    for(int i = 0; i < n; i++){
        if(v[i] < min){
            min = v[i];
        }
    }
    return min;
}

int posmax_array(int n, int v[]){
    int i, max, poz = -1;
    max = v[0];
    for(i = n - 1 ; i >=0 ; i--){
        if(v[i] >= max){
            max = v[i];
            poz = i;
        }
    }
    return poz;
}
 
int max_array(int n, int v[]){
    int i, max;
    max = v[0];
    for(i = n - 1; i >= 0; i--){
        if(v[i] >= max){
            max = v[i];
        }
    }
    return max;
}

double avg_array(int n, int v[]){
    double s =0 , avg;
    double n1 = n;
    for(int i = 0; i < n; i++){
        s += v[i];
    }
    return s/n1;
}

int main(){
    int v[MAX_SIZE], n;

    n = read_array(v);
    if (n < 0) {
        return 1;
    }

    printf("Sum: %d", sum_array(n, v) );

    printf("\n");

    printf("Min: %d", min_array(n, v) );

    printf("\n");

    printf("Max: %d reading(#%d)" , max_array(n, v), posmax_array(n,v) );

    printf("\n");

    printf("Average: %f", avg_array(n, v) );
    
    printf("\n");
}
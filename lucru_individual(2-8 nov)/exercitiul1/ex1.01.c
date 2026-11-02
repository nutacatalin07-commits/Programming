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

int max_array(int n, int v[]){
    int max = v[0];
    for(int i = 0; i < n; i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

int min_array(int n, int v[]){
    int min = v[0];
    for(int i = 0; i < n; i++){
        if(v[i] < min){
            min = v[i];
        }
    }
    return min;
}

double average_array(int n, int v[]){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    return sum / n;
}

int main() {
    int v[MAX_SIZE], n;

    n = read_array(v);
    if (n < 0) {
        return 1;
    }

    printf("Max: %d\n", max_array(n, v));
    printf("Min: %d\n", min_array(n, v));
    printf("Average: %.2f\n", average_array(n, v));

    return 0;
}




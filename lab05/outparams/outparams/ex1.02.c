#include <stdio.h>

#define N_MAX 100

void min_max(int *v, int n, int *min, int *max) {
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(v[i] > v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    *min = v[0];
    *max = v[n - 1];
}

int main(){
    int v[N_MAX], n, Min, Max;
    
    printf("Enter size (1-%d): ", N_MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > N_MAX) {
        printf("Error: invalid size\n");
        return 1;
    }
    
    min_max(v, n, &Min, &Max);
    printf("Min: %d\nMax: %d\n", Min, Max);
    
    return 0;
}
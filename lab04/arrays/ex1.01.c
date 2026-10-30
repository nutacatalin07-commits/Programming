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

void print_array(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[MAX_SIZE], n;

    n = read_array(v);
    if (n < 0) {
        return 1;
    }

    print_array(n, v);
    return 0;
}
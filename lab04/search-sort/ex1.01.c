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

int find_array(int n, int v[], int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int v[MAX_SIZE], n;
    
    n = read_array(v);
    if (n == -1) {
        return 0;
    }

    int port;
    int blocked_count = 0;

    while (scanf("%d", &port) == 1) {
        int index = find_array(n, v, port);

        if (index == -1) {
            printf("%d: allowed\n", port);
        } else {
            printf("%d: blocked (rule #%d)\n", port, index);
            blocked_count++;
        }
    }

    printf("Blocked: %d\n", blocked_count);

    return 0;
}
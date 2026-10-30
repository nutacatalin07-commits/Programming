#include <stdio.h>

void print_bar(int len) {
    for (int i = 0; i < len; i++) {
        printf("#");
    }
}

void print_histogram(int count[]) {
    for (int c = 1; c <= 5; c++) {
        printf("%dxx | %3d | ", c, count[c]);
        print_bar(count[c]);
        printf("\n");
    }
}

int posmax_array(int n, int v[]) {
    int best_pos = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[best_pos]) {
            best_pos = i;
        }
    }
    return best_pos;
}

int main() {
    int code;
    int count[6] = {0};
    int invalid = 0;

    while (scanf("%d", &code) == 1) {
        if (code >= 100 && code <= 599) {
            count[code / 100]++;
        } else {
            invalid++;
        }
    }

    print_histogram(count);
    printf("Invalid: %d\n", invalid);

    int best_idx = posmax_array(5, count + 1);
    if (count[best_idx + 1] == 0) {
        printf("Most frequent: none\n");
    } else {
        printf("Most frequent: %dxx\n", best_idx + 1);
    }

    return 0;
}
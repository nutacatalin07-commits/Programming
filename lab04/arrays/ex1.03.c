#include <stdio.h>

void print_bar(int len) {
    for (int i = 0; i < len; i++) {
        printf("#");
    }
}

void print_histogram(int count[]) {
    for (int i = 1; i <= 5; i++) {
        printf("%dxx | %3d | ", i, count[c]);
        print_bar(count[i]);
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

    int valid_counts[5];
    int total_valid_codes = 0;
    for (int i = 0; i < 5; i++) {
        valid_counts[i] = count[i + 1];
        total_valid_codes += count[i + 1];
    }

    if (total_valid_codes == 0) {
        printf("Most frequent: none\n");
    } else {
        int best_idx = posmax_array(5, valid_counts);
        printf("Most frequent: %dxx\n", best_idx + 1);
    }

    return 0;
}
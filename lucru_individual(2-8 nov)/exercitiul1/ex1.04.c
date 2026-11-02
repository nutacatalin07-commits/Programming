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

int binary_search(int n, int v[], int element) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (v[mid] == element) {
            return mid;
        } else if (v[mid] < element) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int v[MAX_SIZE], n, element;

    n = read_array(v);
    if (n < 0) {
        return 1;
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    int index = binary_search(n, v, element);
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
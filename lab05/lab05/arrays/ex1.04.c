#include <stdio.h>

#define NMAX 100

int *find(int *v, int n, int x)
{
	/* TODO */
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            return &v[i];
        }
    }
	return NULL;
}

int main(void)
{
	int v[NMAX];
	int n, i, x;
	int *p;

	printf("n: ");
	scanf("%d", &n);
	if (n < 1 || n > NMAX){
		return 1;
    }

    printf("v: ");

	for (i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	printf("x: ");
	scanf("%d", &x);

	p = find(v, n, x);
	if (p == NULL) {
		printf("not found\n");
		return 0;
	}

	/* TODO: print the index of the first occurrence (p - v) */
    if(p != NULL){
        printf("The first occurence is at index:: %d\n", (p - v));
    }

	/* TODO extra: all occurrences, calling find from p + 1 */
    printf("found at index: %d\n", (p -v));
    int *p2 = p + 1;
    for(p2 = p + 1; p2 < v + n; p2++){
        p2 = find(p2, n - (p2 - v), x);
        if(p2 != NULL){
            printf("found at index: %d\n", (p2 - v));
        }
    }


	return 0;
    }
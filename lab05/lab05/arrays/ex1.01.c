#include <stdio.h>

#define N 5

int main(void)
{
	int v[N] = {10, 20, 30, 40, 50};
	double w[N] = {1.5, 2.5, 3.5, 4.5, 5.5};

	/* TODO 1: for each i print v[i], *(v + i), &v[i], v + i */
    for(int i = 0; i < N; i++){
        printf("v[%d] = %d, *(v + %d) = %d, &v[%d] = %p, v + %d = %p\n", i, v[i], i, *(v + i), i, (void*)&v[i], i, (void*)(v + i));
    }

	/* TODO 2: the same for w */
    for(int i = 0; i < N; i++){
        printf("w[%d] = %f, *(w + %d) = %f, &w[%d] = %p, w + %d = %p\n", i , w[i], i, *(w + i), i, (void *)&w[i], i, (void *)(w + i));
    }
	/*
	 * Answers:
	 * - identical columns:
	 * - how much the addresses grow for v and for w, and why:
     * coloanele identice sunt prima cu a doua si a treia cu a patra deoarece prima si a doua sunt valorile 
     * lui v[i] acceate prin v de i si dereferentierea pointerului v + i,iar a  treia si a patra sunt adresele lui v[i]
     * accesatr prin adresa lui v[i] si pointerul v + i.Adresele cresc cu 4 la v pt ca este un int si cu 8 la w pt ca este un double.
	 */

	return 0;
}
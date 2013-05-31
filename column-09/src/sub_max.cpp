#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

float arrmax(float *x, int n) {
	if (n == 1) {
		return x[0];
	} else {
		return max(x[n-1], arrmax(x, n-1));
	}
}

float frand() {
	return (float) rand() / (float)RAND_MAX;
}

int main(int argc, char *argv[]) {
	int i;
	int len = 100000000;
	float *arr = (float *)malloc(sizeof(float) * len);
	clock_t start, end;

	srand(time(NULL));

	for (i = 0; i < len; i++) {
		arr[i] = frand();
	}

	start = clock();
	arrmax(arr, 30);
	end = clock();

	printf("it takes %f sec\n", (double)(end - start)/ CLOCKS_PER_SEC);

	return 0;
}

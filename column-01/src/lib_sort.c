#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 10000000

int int_sort(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[]) {
	int i, len;
	int *arr;
	clock_t t1, t2;

	arr = (int *)malloc(sizeof(int) * N);
	memset(arr, 0, sizeof(int) * N);

	FILE *fp;
	char buf[32];

	if ((fp = fopen("sample.dat", "r")) == NULL) {
		exit(EXIT_FAILURE);
	}

	i = 0;
	while(fgets(buf, 32, fp) != NULL) {
		arr[i] = atoi(buf);
		i++;
	}
	len = i;

	t1 = clock();
	qsort(arr, len, sizeof(arr[0]), int_sort);
	t2 = clock();

	printf("sort exec time=%f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

	fclose(fp);

	if ((fp = fopen("sorted.dat", "w")) == NULL) {
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++) {
		fprintf(fp, "%d\n", arr[i]);
	}

	free(arr);
	fclose(fp);

	return 0;
}

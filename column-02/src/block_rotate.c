#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void block_rotate(int **array, int n, int i) {
	int temp[i];
	int x;
	for (x = 0; x < i; x++) {
		temp[x] = (*array)[x];
	}
	for (x = i; x < n; x++) {
		(*array)[x-i] = (*array)[x];
	}
	for (x = n -i; x < n; x++) {
		(*array)[x] = temp[x-n+i];
	}
}

int main(int argc, char *argv[]) {
	FILE *fp;
	char row[32];
	int *array;
	int i = 0;
	int index = 0;
	int len = 0;
	fp = stdin;

	fgets(row, sizeof(row), fp);
	len = atoi(row);

	fgets(row, sizeof(row), fp);
	index = atoi(row);

	array = (int *)malloc(sizeof(int) * len);
	memset(array, 0, len);
	if (array == NULL) {
		exit(1);
	}

	while (fgets(row, sizeof(row), fp) != NULL) {
		array[i] = atoi(row);
		i++;
	}
	len = i;

	clock_t t1 = clock();
	block_rotate(&array, len, index);
	clock_t t2 = clock();

	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("elapsed time: %f\n", (double)(t2 -t1)/ CLOCKS_PER_SEC);

	return 0;
}

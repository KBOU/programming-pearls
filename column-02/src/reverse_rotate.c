#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void reverse(int **array, int start, int end) {
	int i, j, tmp;
	for (i = start, j = end; i < j; i++, j--) {
		tmp = (*array)[i];
		(*array)[i] = (*array)[j];
		(*array)[j] = tmp;
	}
}

void reverse_rotate(int **array, int n, int i) {
	if (i == 0) {
		return;
	}
	reverse(array, 0, i - 1);
	reverse(array, i, n - 1);
	reverse(array, 0, n - 1);
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

	clock_t t1 = clock();
	reverse_rotate(&array, len, index);
	clock_t t2 = clock();

	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("elapsed time: %f\n", (double)(t2 -t1)/ CLOCKS_PER_SEC);

	return 0;
}

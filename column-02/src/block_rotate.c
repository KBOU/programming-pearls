#include <stdio.h>
#include <stdlib.h>

void block_rotate(int (*array)[20], int n, int i) {
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
	int array[20] = {0};
	int i = 0;
	int index = 0;
	int len = 0;
	fp = stdin;

	fgets(row, sizeof(row), fp);
	index = atoi(row);
	while (fgets(row, sizeof(row), fp) != NULL) {
		array[i] = atoi(row);
		i++;
	}
	len = i;

	block_rotate(&array, len, index);

	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}

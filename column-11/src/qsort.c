#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int x[], int i, int j) {
	int t;
	t = x[i];
	x[i] = x[j];
	x[j] = t;
}

void qsort_(int x[], int n) {
	int i, j;
	if (n <= 1) {
		return;
	}

	for (i = 1, j =0; i < n; i++) {
		if (x[i] < x[0]) {
			swap(x, ++j, i);
		}
	}
	swap(x, 0, j);
	qsort_(x, j);
	qsort_(x+j+1, n-j-1);
}

int main(int argc, char *argv[]) {
	int test_num, i, j, num;
	char buf[128];
	char *tok;
	int *arr;
	fgets(buf, 128, stdin);
	test_num = atoi(buf);

	for (i = 1; i <= test_num; i++) {
		fgets(buf, 128, stdin);
		tok = strtok(buf, " ");
		num = atoi(tok);
		arr = (int *)malloc(sizeof(int) * num);
		for (j = 0; j < num; j++) {
			tok = strtok(NULL, " ");
			arr[j] = atoi(tok);
		}
		qsort_(arr, num);
		printf("Case #%d: ", i);
		for (j = 0; j < num; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	return 0;
}

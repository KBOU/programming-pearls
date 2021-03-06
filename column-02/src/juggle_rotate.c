#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int check_if_all_visited(int visited[20], int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (visited[i] == 0) {
			return 0;
		}
	}

	return 1;
}

void juggle_rotate(int **array, int n, int i) {
	int y, x, temp, prev;
	int *visited;
	visited = (int *)malloc(sizeof(int) * n);
	memset(visited, 0, n);
	if (visited == NULL) {
		exit(1);
	}

	y = 0;
	while (1) {
		temp = (*array)[y];
		x = (y + i) % n;
		while (x != y) {
			prev = (x + n - i) % n;
			(*array)[prev] =  (*array)[x];
			visited[prev] = 1;
			x += i;
      x %= n;
		}

		prev = (x + n - i) % n;
		(*array)[prev] = temp;
		visited[prev] = 1;
		if (check_if_all_visited(visited, n)) {
			break;
		}
		y++;
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

	clock_t t1 = clock();
	juggle_rotate(&array, len, index);
	clock_t t2 = clock();

	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("elapsed time: %f\n", (double)(t2 -t1)/ CLOCKS_PER_SEC);

	return 0;
}

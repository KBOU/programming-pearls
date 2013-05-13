#include <stdio.h>
#include <stdlib.h>

int check_if_all_visited(int visited[20], int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (visited[i] == 0) {
			return 0;
		}
	}

	return 1;
}

void juggle_rotate(int (*array)[20], int n, int i) {
	int y, x, temp, prev;
	int visited[20] = {0};

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

	juggle_rotate(&array, len, index);

	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}

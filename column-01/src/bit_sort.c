#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000
#define BITS 32

int ARRAY[N / BITS + 1] = {0};

void set(int i) {
	ARRAY[i/BITS] |= 1 << (i % BITS);
}
int get(int i) {
	return ARRAY[i/BITS] >> (i % BITS) & 1;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	int i, t;
	clock_t t1, t2;
	char buf[32];

	if ((fp = fopen("sample.dat", "r")) == NULL) {
		exit(EXIT_FAILURE);
	}

	i = 0;
	t1 = clock();
	while (fgets(buf, 32, fp) != NULL) {
		t = atoi(buf);
		set(t);
		i++;
	}
	t2 = clock();
	printf("sort exec time=%f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

	fclose(fp);

	if ((fp = fopen("sorted.dat", "w")) == NULL) {
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < N; i++) {
		if (get(i) == 1) {
			fprintf(fp, "%d\n", i);
		}
	}

	fclose(fp);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRY /* TRY-CATCH */
#define THROW(name) goto TRY_TAG_ERROR_##name
#define CATCH(name, last) goto TRY_TAG_RESUME_##last; TRY_TAG_ERROR_##name:
#define FINALLY(last) TRY_TAG_RESUME_##last:

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
	int i, len;
	long t;
	char *e;
	char buf[32];

	if ((fp = fopen("sample.dat", "r")) == NULL) {
		exit(EXIT_FAILURE);
	}

	i = 0;
	TRY {
		while (fgets(buf, 32, fp) != NULL) {
			len = strlen(buf);
			if (buf[len-1] == '\n') {
				buf[len-1] = '\0';
			}
			t = strtol(buf, &e, 10);
			if (strcmp(e, "") != 0) {
				printf("[WARN] \"%s\" is not a number\n", buf);
			} else {
				if(t >= N || t < 0) {
					THROW(B);
				} else if (get(t) == 1) {
					THROW(A);
				}
				set(t);
				i++;
			}
		}
		if (i == 0) {
			printf("[WARN] input data is null\n");
		}
	} CATCH(A, F) {
		printf("[ERROR] duplicate number exists\n");
		exit(1);
	} CATCH(B, F) {
		printf("[ERROR] number out of range\n");
		exit(2);
	} FINALLY(F) {
	}

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;

int binarysearch(DataType x[], DataType t, int n) {
	/*
	 * 前提条件： xはsort済みの配列
	 * 出力： tのindexを返す。なければ-1
	 */
	int m, res;

	if (n <= 0) {
		return -1;
	}

	m = (n - 1) / 2;
	if (t < x[m]) {
		/* mより左の範囲で2分探索 */
		return binarysearch(x, t, m);
	} else if (t > x[m]) {
		/* mより右の範囲で2分探索 */
		res = binarysearch(&x[m+1], t, n-m-1);
		if (res == -1) {
			return res;
		}
		return m + 1 + res;
	} else {
		return m;
	}
}

int main(int argc, char *argv[]) {
	int test_num, i;
	char buf[128];
	fgets(buf, 128, stdin);
	test_num = atoi(buf);

	int j, t, len, res;
	char *tok;
	DataType* x;

	for (i = 1; i <= test_num; i++) {
		fgets(buf, 128, stdin);
		t = atoi(buf);
		fgets(buf, 128, stdin);
		tok = strtok(buf, " ");
		len = atoi(tok);
		j = 0;
		x = (DataType *)malloc(sizeof(DataType) * len);
		while (j < len && (tok = strtok(NULL, " ")) != NULL) {
			x[j++] = atoi(tok);
		}
		
		res = binarysearch(x, t, len);
		printf("Case #%d: %d\n", i, res);

		free(x);
	}
	return 0;
}

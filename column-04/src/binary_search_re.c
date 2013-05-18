#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search_re(int *arr, int l, int r, int t) {
	/*
	 * arr
	 *    ソートされた配列
	 * l
	 *    配列の左側のindex
	 * r
	 *    配列の右側のindex
	 * t
	 *    探しだす数値
	 * 戻り値：
	 *   tが見つかった位置。なければ-1を返す
	 */
	int m, p;
	if (l > r) {
		return -1;
	}

	m = (l + r) / 2;

	if (t < arr[m]) {
		p = binary_search_re(arr, l, m-1, t);
	} else if (t > arr[m]) {
		p = binary_search_re(arr, m+1, r, t);
	} else {
		p = m;
	}
	return p;
}

int main(int argc, char *argv[]) {
	int test_num, i;
	char buf[128];
	int t, len, j;
	char *tok;
	int *arr;
	int res;

	fgets(buf, 128, stdin);
	test_num = atoi(buf);

	for (i = 1; i <= test_num; i++) {
		fgets(buf, 128, stdin);
		t = atoi(buf);
		fgets(buf, 128, stdin);

		len = atoi(strtok(buf, " "));
		if ((arr = (int *)malloc(sizeof(int) * len)) == NULL) {
			printf("cannot allocate enough memory\n");
			exit(1);
		}
		j = 0;
		while ((tok = strtok(NULL, " ")) && j < len) {
			arr[j++] = atoi(tok);
		}
		res = binary_search_re(arr, 0, len-1, t);
		if (res == -1) {
			printf("cannot find %d\n", t);
		} else {
			printf("%d is found at index %d\n", t, res);
		}
	}
	return 0;
}

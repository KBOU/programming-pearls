#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search_more(int *x, int l, int u, int t) {
	int m, p, p2;
	while (1) {
		if (l > u) {
			p = -1;
			break;
		}

		m = (l + u) / 2;
		if (x[m] < t) {
			l = m + 1;
		} else if (x[m] > t) {
			u = m - 1;
		} else {
			p = m;
			if (l < p) {
				p2 = binary_search_more(x, l, p, t);
				p = p2;
			}
			break;
		}
	}
	return p;
}

int main(int argc, char *argv[]) {
	/*
	 * inputはファイルから
	 * ファイルのフォーマットは
	 * 1行目: テストケース数
	 * 偶数行: 探しだす要素
	 * 奇数行: スペース区切りの配列
	 */
	int test_num, i, len, t, j, res;
	char buf[128], *tok;
	int *arr;
	fgets(buf, 128, stdin);
	test_num = atoi(buf);

	for (i = 1; i <= test_num; i++) {
		fgets(buf, 128, stdin);
		t = atoi(buf);
		fgets(buf, 128, stdin);
		len = atoi(strtok(buf, " "));
		if ((arr = (int *)malloc(sizeof(int) * len)) == NULL) {
			printf("cannot allocate memory\n");
			exit(1);
		}
		j = 0;
		while ((tok = strtok(NULL, " ")) && j < len) {
			arr[j++] = atoi(tok);
		}
		res = binary_search_more(arr, 0, len-1, t);
		if (res == -1) {
			printf("cannot find %d\n", t);
		} else {
			printf("%d is %dth element in array.\n", t, res+1);
		}
	}
	return 0;
}

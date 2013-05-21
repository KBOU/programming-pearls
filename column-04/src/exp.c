#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myexp(int x, int n) {
	/*
	 * 前提条件: n >= 0
	 * 出力: result = x ^ n
	 */
	int res, tmp, i, j, goal;

	if (n == 0) {
		return 1;
	} else {
		res = 1;
		goal = n;
		while (goal) {
			tmp = 1;
			for (j = 1; j <= goal; j = j*2) {
				if (tmp == 1) {
					tmp *= x;
				} else {
					tmp *= tmp;
				}
			}
			res *= tmp;
			goal -= j/2;
		}
		return res;
	}
}

int main(int argc, char *argv[]) {
	int test_num, i;
	char buf[128];
  char *tok;
	int x, n, res;

	fgets(buf, 128, stdin);
	test_num = atoi(buf);

	for (i = 1; i <= test_num; i++) {
		fgets(buf, 128, stdin);
		x = atoi(strtok(buf, " "));
		n = atoi(strtok(NULL, " "));
		res = myexp(x, n);
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}

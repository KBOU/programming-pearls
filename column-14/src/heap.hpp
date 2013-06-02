#include <stdio.h>

class Heap {
private:
	int *x, maxsize, index;
	void swap(int i, int j) {
		int t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
	int pindex(int i) {
		return i/2;
	}
	int lindex(int i) {
		return 2*i;
	}
	int rindex(int i) {
		return 2*i+1;
	}
	void shiftup(int n) {
		/* 前提: n > 0 && heap(1, n-1)
		 * 出力: heap(1, n)
		 */
		while (n > 1) {
			/* n>1かつx[p] > x[n] */
			int p = pindex(n);
			if (x[p] <= x[n]) {
				break;
			}
			swap(p, n);
			n = p;
		}
	}
	void shiftdown(int n) {
		/*
		 * 前提: 0 < n && heap(2, n)
		 * 出力: heap(1, n)
		 */
		int lc, rc, c;

		int i = 1;
		while (i < n) {
			/* i < n && x[c] < x[i] */
			lc = lindex(i);
			if (lc >= n) {
				break;
			}
			rc = rindex(i);
			if (rc >= n) {
				c = lc;
			} else {
				c = (x[lc] < x[rc]) ? lc : rc;
			}
			if (x[i] <= x[c]) {
				break;
			}
			swap(c, i);
			i = c;
		}
	}
public:
	Heap(int maxsz) {
		maxsize = maxsz;
		x = new int[maxsize+1];
		index = 0;
	}

	void insert(int t) {
		if (index >= maxsize) {
			return;
		}
		x[++index] = t;
		shiftup(index);
		for (int i = 1; i <= index; i++) {
			printf("i=%d x[i]=%d\n", i, x[i]);
		}
		printf("\n\n");
	}
	int pop() {
		if (index < 1) {
			return -1; // 一応エラー。とりあえず正の整数のみ想定
		}
		int t = x[1];
		x[1] = x[index--];
		shiftdown(index);
		return t;
	}
	int size() {
		return index;
	}
};

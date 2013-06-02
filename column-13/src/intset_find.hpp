class IntSetArray {
private:
	int n, *x, maxv;
	void bin_search(int *range, int t, int num) {
		if (num <= 0) {
			return maxv;
		}
		int m = num / 2;
		if (t < range[m]) {
			return bin_search(range, t, num-1);
		} else if (t > range[m]) {
			int r = bin_search(range+m+1, t, num-m-1);
			if (r != maxv) {
				r += (m + 1)
			}
			return r;
		}
	}
public:
	IntSetArray(int maxelems, int maxval) {
		x = new int[1+maxelems];
		n = 0;
		x[0] = maxval;
		maxv = maxval;
	}
	int size() { return n; }
	void insert(int t) {
		int i;
		for (i = 0; x[i] < t; ++i) {
		}
		if (x[i] == t) {
			return;
		}
		for (int j = n; j >= i; j--) {
			x[j+1] = x[j];
		}
		x[i] = t;
		n++;
	}
	int find(int t) {

		return maxval;
	}
	void report(int *v) {
		for (int i = 0; i < n; i++) {
			v[i] = x[i];
		}
	}
};

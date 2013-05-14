#define K 5
int C[5]  = {4, 3, 3, 1, 9};

int a(int n) {
	int i, an;
	an = 0;
	for (i = 0; i < K; i++) {
		if (i < K - 1) {
			an += C[i] * a(n-i-1);
		} else {
			an += C[i];
		}
	}
	return an;
}

int main(int argc, char *argv[]) {
	/*
		配列を使わなかった場合、
		項が一つ増えた時の修正がめんどくさそう
	*/
	return 0;
}


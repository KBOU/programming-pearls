void genfloyd(int m, int n) {
	set<int> S;
	set<int>::iterator i;
	for (int j = n-m; j < n; j++) {
		int t = rand() % (j+1);
		if (S.find(t) == S.end) {
			S.insert(t);
		} else {
			S.insert(j);
		}
	}
	for (i = S.begin; i != S.end; i++) {
		cout << *i << "\n";
	}
}

void genfloyd2(int m, int n) {
	IntSetSTL S;
	int *v = new int[m];

	for (int j = n-m; j < n; j++) {
		int t = rand() % (j+1);
		int s = S.size();
		S.insert(t);
		if (S.size == s) {
			S.insert(j);
		}
	}
	S.report(v);
	for (int i = 0; i < m; i++) {
		cout << v[i] << "\n";
	}
}

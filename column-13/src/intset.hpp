#include <set>
using namespace std;

class IntSetSTL {
private:
	set<int> S;
public:
	IntSetSTL(int maxelems, int maxval) { }
	int size() { return S.size(); }
	void insert(int t) { S.insert(t); }
	void report(int *v) {
		int j = 0;
		set<int>::iterator i;
		for (i = S.begin(); i != S.end(); ++i) {
			v[j++] = *i;
		}
	}
};

class IntSetArray {
private:
	int n, *x;
public:
	IntSetArray(int maxelems, int maxval) {
		x = new int[1+maxelems];
		n = 0;
		x[0] = maxval;
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
	void report(int *v) {
		for (int i = 0; i < n; i++) {
			v[i] = x[i];
		}
	}
};

class IntSetList {
private:
	int n;
	struct node {
		int val;
		node *next;
		node(int v, node *p) { val = v; next = p; }
	};
	node *head, *sentinel;
	node *rinsert(node *p, int t) {
		if (p->val < t) {
			p->next = rinsert(p->next, t);
		} else if(p->val > t) {
			p = new node(t, p);
			n++;
		}
		return p;
	}
public:
	IntSetList(int maxelems, int maxval) {
		sentinel = new node(maxval, 0);
		head = sentinel;
		n = 0;
	}
	int size() { return n; }
	void insert(int t) {
		head = rinsert(head, t);
	}
	void report(int *v) {
		int j = 0;
		for (node *p = head; p != sentinel; p = p->next) {
			v[j++] = p->val;
		}
	}
};

class IntSetBST {
private:
	int n, *v, vn;
	struct node {
		int val;
		node *left, *right;
		node(int v) {
			val = v;
			left = right = 0;
		}
	};
	node *root;
	node *rinsert(node *p, int t) {
		if (p == 0) {
			p = new node(t);
			n++;
		} else if (p->val < t) {
			p->right = rinsert(p->right, t);
		} else if(p->val > t) {
			p->left = rinsert(p->left, t);
		}
		return p;
	}
	void traverse(node *p) {
		if (p == 0) {
			return;
		}

		traverse(p->left);
		v[vn++] = p->val;
		traverse(p->right);
	}
public:
	IntSetBST(int maxelems, int maxval) { root = 0; n = 0;}
	int size() { return n; }
	void insert(int t) { root = rinsert(root, t); }
	void report(int *x) { v = x; vn = 0; traverse(root); }
};


class IntSetBitVec {
private:
	enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };
	int n, hi, *x;
	void set(int i) { x[i >> SHIFT] |= (1 << (i & MASK)); }
	void clr(int i) { x[i >> SHIFT] &= ~(1 << (i & MASK)); }
	int test(int i) { return x[i >> SHIFT] & (1 << (i & MASK)); }
public:
	IntSetBitVec(int maxelems, int maxval) {
		hi = maxval;
		x = new int[1 + hi/BITSPERWORD];
		for (int i = 0; i < hi; i++) {
			clr(i);
		}
		n = 0;
	}
	int size() { return n; }
	void insert(int t) {
		if (test(t)) {
			return;
		}
		set(t);
		n++;
	}
	void report(int *v) {
		int j = 0;
		for (int i = 0; i < hi; i++) {
			if (test(i)) {
				v[j++] = i;
			}
		}
	}
};

class IntSetBins {
private:
	int n, bins, maxval;
	struct node {
		int val;
		node *next;
		node(int v, node *p) { val = v; next = p; }
	};
	node **bin, *sentinel;
	node *rinsert(node *p, int t) {
		if (p->val < t) {
			p->next = rinsert(p->next, t);
		} else if (p->val > t) {
			p = new node(t, p);
			n++;
		}
		return p;
	}
public:
	IntSetBins(int maxelems, int pmaxval) {
		bins = maxelems;
		maxval = pmaxval;
		bin = new node*[bins];
		sentinel = new node(maxval, 0);
		for (int i = 0; i < bins; i++) {
			bin[i] = sentinel;
		}
		n = 0;
	}
	int size() { return n; }
	void insert(int t) {
		int i = t / (1 + maxval/bins);
		bin[i] = rinsert(bin[i], t);
	}
	void report(int *v) {
		int j = 0;
		for (int i = 0; i < bins; i++) {
			for (node *p = bin[i]; p != sentinel; p = p->next) {
				v[j++] = p->val;
			}
		}
	}
};

class IntSetList {
private:
	int n;
	struct node {
		int val;
		node *next;
		node(int v, node *p) { val = v; next = p; }
	};
	node *head, *sentinel;
public:
	IntSetList(int maxelems, int maxval) {
		sentinel = new node(maxval, 0);
		head = sentinel;
		n = 0;
	}
	int size() { return n; }
	void insert(int t) {
		node *p, *prev = 0;
		for (p = head; p != sentinel; p = p->next) {
			if (p->val > t) {
				p = new node(t, p);
				if (prev != 0) {
					prev->next = p;
				}
				n++;
				break;
			}
			prev = p;
		}
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
	void insert(int t) {
		node *p, *prev = 0;
		p = root;
		while (1) {
			if (p == 0) {
				p = new node(t);
				n++;
				if (prev != 0) {
					if (t < prev->val) {
						prev->left = p;
					} else if (t > prev-val) {
						prev->right = p;
					}
				} else {
					root = p;
				}
				break;
			}
			prev = p;
			if (t < p->val) {
				p = p->left;
			} else if (t > p->val) {
				p = p->right;
			} else {
				break;
			}
		}
	}
	void report(int *x) { v = x; vn = 0; traverse(root); }
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
		node *p, *prev = 0;
		for (p = bin[i]; p != sentinel; p = p->next) {
			if (p->val > t) {
				p = new node(t, p);
				n++;
				if (prev != 0) {
					prev->next = p;
				}
			}
			prev = p;
		}
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

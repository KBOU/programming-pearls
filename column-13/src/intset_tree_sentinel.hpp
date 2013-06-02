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
	node *root, *sentinel;
	void traverse(node *p) {
		if (p == 0) {
			return;
		}

		traverse(p->left);
		v[vn++] = p->val;
		traverse(p->right);
	}
public:
	IntSetBST(int maxelems, int maxval) {
		root = sentinel = new node;
		n = 0;
	}
	int size() { return n; }
	void insert(int t) {
		node **p = &root;
		sentinel->val = t;
		/* 番兵に当たるまでもしくはtがみつかるまでループ */
		while ((*p)->val != t) {
			if (t < (*p)->val) {
				p = &((*p)->left);
			} else {
				p = &((*p)->right);
			}
		}

		/* 番兵にあたった、つまりtがツリー上になかった場合 */
		if (*p == sentinel) {
			*p = new node(t);
			/* 左右に番兵の参照を配置 */
			(*p)->left = (*p)->right = sentinel;
			n++;
		}

		root = rinsert(root, t);
	}
	void report(int *x) { v = x; vn = 0; traverse(root); }
};


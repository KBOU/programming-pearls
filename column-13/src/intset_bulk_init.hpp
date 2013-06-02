class IntSetList {
private:
	int n;
	struct node {
		int val;
		node *next;
		node(int v, node *p) { val = v; next = p; }
	};
	node *head, *sentinel, *nodes;
	node *rinsert(node *p, int t) {
		if (p->val < t) {
			p->next = rinsert(p->next, t);
		} else if(p->val > t) {
			node *tmp = p;
			p = nodes++;
			p->val = t;
			p->next = tmp;
			n++;
		}
		return p;
	}
public:
	IntSetList(int maxelems, int maxval) {
		nodes = new node[maxelems];
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


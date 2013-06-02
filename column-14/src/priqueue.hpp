#include "heap.hpp"

class PriorityQueue {
private:
	Heap *heap;
public:
	PriorityQueue(int maxsize) {
		heap = new Heap(maxsize);
	}
	void insert(int t) {
		heap->insert(t);
	}
	int extractmin() {
		return heap->pop();
	}
};


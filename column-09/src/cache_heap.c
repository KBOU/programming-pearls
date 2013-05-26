#define NODESIZE 8
#define NODEGROUP 1000
int nodesleft = 0;
char *freenode;

void *pmalloc(int size) {
	/*
	 * 指定されたサイズのメモリをheapに確保し、
	 * 先頭アドレスを返す関数。
	 *
	 * メモリはキャッシュする。
	 */
	void *p;
	if (size != NODESIZE) {
		/* 指定されたサイズがキャッシュ対象外のサイズなら普通のmalloc */
		return malloc(size);
	}

	if (nodesleft == 0) {
		/*
		 * 確保したキャッシュが空の場合
		 * 1つあたりのメモリサイズ x 1000個分のメモリをヒープに確保
		 */
		freenode = malloc(NODEGROUP * NODESIZE);
		nodesleft = NODEGROUP;
	}
	nodesleft--;
	/* 確保したメモリの先頭アドレス */
	p = (void *)freenode;
	/* メモリ位置を次の位置まで移動 */
	freenode += NODESIZE;
	return p;
}

#include <math.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

float x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

float maxsum3(int l, int u) {
	/*
	 * 前提条件: 0 <= l <= u < length of x
	 * 出力: l <= i <= uを満たす部分配列の中のmax値を返す
	 */
	int m, lmax, rmax, sum, i;

	if (l > u) {
		/* 範囲が存在しない場合0を返す */
		return 0;
	}
	if (l == u) {
		/* 範囲のサイズが1の場合は0か1つめの要素の大きさを返す */
		return max(0, x[1]);
	}

	/* 真ん中の要素を取得 */
	m = (l + u) / 2;

	lmax = sum = 0;
	for (i = m; i >= 1; i--) {
		/* 1 <= i <= m */
		sum += x[i];
		/* mから左側に向かって最大の部分配列を求める */
		lmax = max(lmax, sum);
	}

	rmax = sum = 0;
	for (i = m+1; i <= u; i++) {
		/* m+1 <= i <= u */
		sum += x[i];
		/* m+1から右側に向かって最大の部分配列を求める */
		rmax = max(rmax, sum);
	}

	/* lmax + rmaxは真ん中近辺のmax値 */
	/* maxsum3(1, m)はmを含みmより左側の要素のmax値 */
	/* maxsum3(m+1, u)はm+1を含みm+1より右側の要素のmax値 */
	return max(lmax + rmax, max(maxsum3(l, m), maxsum3(m+1, u)));
}


float maxsum4(int n) {
	/*
	 * 前提条件: n = length of x
	 * 出力: 最大値を返す部分配列の合計値
	 */
	int maxsofar, maxendinghere, i;
	maxsofar = 0;
	maxendinghere = 0;

	for (i = 0; i < n; i++) {
		/* 0 <= i < n */
		/* 
		 * i - 1までの右端の部分配列の最大値にx[i]を足したもの 
		 * もしマイナスなら右端の部分配列の最大値は0
		 */
		maxendinghere = max(maxendinghere + x[i], 0);
		/*
		 * i-1までの最大の部分配列かi番目の要素を考慮に入れた時の
		 * 右端の部分配列のうちの大きい方をiまで走査したときの最大値とする
		 */
		maxsofar = max(maxsofar, maxendinghere);
	}
	return maxsofar;
}

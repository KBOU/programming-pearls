# アルゴリズムデザインのテクニック

* キャッシュを記録し再計算を避ける
* データを前処理して処理しやすくする
* 分割して制服アルゴリズム
* 操作アルゴリズム(1個前の結果を利用する)
* 累計(合計して引いたほうが早いならそうする)
* 実行時間の下限を目指す

## Q1. アルゴリズム3とアルゴリズム4を検証する

`src/getmax.c`

## Q2-3. 飛ばす

## Q4. [-1, 1]の一様分布の部分和の最大値の期待値

0.25 * 配列の個数かとおもいきやぜんぜん違うっぽい。  
わからん・・・

`src/random_walk.py`

## Q5. arr[-1]をcで表現

```
float *cumarr;
cumarr = realarr+1;
```

これでrealarrのインデックスは0からスタート

## Q6. 部分配列の最大値を求めるには全要素を調べる必要があるがなぜか？

1個だけくそでかい数値があってもそれがどこにあるかわからないから、  
全要素見ないとわからないから。ではないだろうか・・・

[0.2, 1.2, 999, 4.0]みたいな感じ

## Q7. 飛ばす

## Q8. 分割して統治のアルゴリズムをO(n)へ

`src/getmax.c`

のmaxsum3をO(n)へ・・・

わからん！

## Q9. 要素のすべてが負の数である場合、0ではなくその中の最大の要素を要素の和が最大になる部分配列とすると、プログラムをどのように変えればよいか？

iterationのときに1要素の最大値を記憶しておき、iteration後のmax値が0であったら、記憶しておいた最大値を最大値とする。


## Q10. 最大値ではなく0に近い部分和を求めるにはどうすればよいか？また0ではなくtに近い部分和の場合は??

0に近い部分和を求めるには、0からindex i番目までの合計値を求めて、  
それをソートして、隣り合う値の差が最も近い2数の差が0に近い部分和となる。

tに近い部分和を求めるには、index 0-i番目までの合計値を各iにて求める。  
次に同様に合計値を求めるがそれぞれ-tする。

その2つの配列をソートして最も近い隣り合う数値を答えとする。

## Q11. 飛ばす。(Q10とほぼ同じなので)

## Q12. x[0..n-1]をすべて0に初期化し、n回以下の処理をしたときにx[0..n-1]を出力する。

以下の処理
```
for i = [l, u]
	x[i] += v
```

ちなみにl, uは0 &le; l &le; u &lt; nとなる整数でvは実数。

普通にやるとO(n^2)だけど、これより速いアルゴリズムがあるらしい。

`src/addv.py`

## Q13. nxnの２次元配列で書く要素の和が最大となるlxk配列を求める

説明読んでもわかりませんでした・・・

## Q14. 配列x[0..n-1]の中で0 &le; i &lt; n-mを満たすx[i] + .. + x[i+m]で最も0に近いものを求める。

```
sum0 = 0
for i = [0, m]
	sum0 += x[i]

near0 = sum0
for i = [1, n-m)
	sum0 += (x[i+m] - x[i-1])
	if abs(near0) < abs(sum0)
		near0 = sum0
```

でいける！のか・・・

`src/nearzero.py`

## Q15. T(n) = 2T(n/2) + cnでT(1) = 0でn=2^mの時のT(n)は？

なんとなくT(n) = U(m)とする。  
とU(m) = 2U(m-1) + c * 2^mで置き換えれる。

```
U(m) - 2U(m-1) = c * 2^m
U(m) - 2U(m-1) + 2 * (U(m-1) -2U(m-2)) = U(m) - 4U(m-2) = c*2^m + 2*c*2^(m-1) = c * 2^(m+1)
...
U(m) = c * 2^m * 2^m-1 = c * 2^(2m-1)
```

とするとT(n) = c * n^2 / 2となる。
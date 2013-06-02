# 探索

## Q1. genfloyd(int m, int n)をIntSetを使って表現する

`src/genfloyd.cpp`

genfloydが元の関数でIntSet版はgenfloyd2

## Q2. IntSetをより堅牢にするには？

maxval以上の整数が来た時の処理をいれる。  
bit配列バージョンは負の数値が来た時の処理をいれる。

## Q3. find関数を書いてみる

2文探索します。

`src/intset_find.hpp`

## Q4. リスト、ビン、二分探索の再帰的な挿入関数をループで処理する

`src/intset_loop.hpp`

### 追記

ポインタのポインタ使えばもうちょっと短く書けるもよう。

## Q5. 都度newではなく予めデータを確保しておく。

`src/intset_bulk_init.hpp`

## Q6. 昇順にIntSetImpにデータを突っ込んだ時の実行速度

リストや配列型のやつは効率がよくて、  
2分探索やビンは悪いらしい。

なんで？リストや配列も最悪ケースの比較はするしなー。

## Q7. BSTで番兵を配置

`src/intset_tree_sentinel.hpp`

難しい・・・


## Q8. ビット演算の効率化

* 初期化はx[i] = 0のループを回すことで32bitごとに処理できる。
* 出力もint単位でチェックし、x[i] = 0だったら次のループに行くようにするといい。

## Q9. ビンのアプローチでコストの高い割り算をなるべく使わないでやる。


```
goal = n/m						# だいたい1個のビンに1つの整数が入ればいい感じ
binshift = 1
for i = [2, goal) <- i*=2
	binshift++
nbins = 1 + (n >> binshift)     # 1個のビンに1つの整数が入るよりは少し少なめのビンの数



insert(t)
	p = &(bin[t >> binshift])
```

なんとなく良さそうなのはわかるけど、なぜこれがベストなのかはわからない。

## Q10-11. とばす

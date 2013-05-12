# 真珠貝を開いて

問題を表層的に捉えるのでなく、
問題の本質をつかみ、
きちんと問題定義してから
問題解決しましょうというお話。

## 課題

* 入力：10^7までの数値を含んだファイル。数値の重複はない
* 出力：入力をソートした一覧
* 条件：ディスク容量あり。メモリ1MBまで。

## 1. ライブラリ付属のソート関数を使って問題を解く

課題をメモリの制約を考慮せずに標準ライブラリのソートを使って解く。

`src/lib_sort.c`

## 2. and, or, shift演算を使ったビット列の実装方法

32-bit integerの各ビットにデータを格納する方法を考える。

たとえば2が存在するということをビット列で表すと、  
`0000 0000 0000 0000 0000 0000 0000 0100`  
のようになる。

これをand, or, shift演算を用いて表現する。

`src/bit_array.c`

## 3. ビットソートを実装し問題1のソートと比較する

課題をビット列を使ったソートを用いて解決し、  
速度を問題１のソートと比較する。

<table>
  <tr> <td> </td> <td>ライブラリソート</td> <td>ビットソート</td> </tr>
  <tr> <td>実行速度</td> <td>2.1秒</td> <td>0.6秒</td> </tr>
</table>

`src/bit_sort.c`

## 4. nより小さいk個の重複のないソートされていない整数をどのように生成するか

まず、0..n-1までの数値が並んでいる配列を作成し（ソートされている配列）、  
任意の位置の数値をスワップすればいい。

今回はpythonでrandom.shuffleという便利なメソッドがあったので、pythonで作成した。

`src/make_sample.py`

## 5. ビットソートは実はメモリを1.25MB使うが、ガチで1MBしか使えない場合どうするか

分割してソートしてく。

例えば、  
`[4, 5, 12, 3, 10, 8, 7, 9, 6, 2, 11, 1]`  
をソートするときに10個ずつしかソートできない場合。

10までの数値をまずはソートする。
`[1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [12, 11]`

次に11, 12をソートする
`[4, 5, 12, 3, 10, 8, 7, 9, 6, 2], [11, 12]`

ソートを合計2回してるので2倍の計算量。
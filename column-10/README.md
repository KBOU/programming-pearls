# メモリの節約


## データの使用メモリを減らす

* 記憶させずに計算させる
* データが疎なときにしっかり構造を考える
* データを圧縮する
* メモリ確保の方法の検討(動的に?静的に?配列(アクセスが早い)?)


## コードの使用メモリを減らす

* 関数の定義
* インタープリタ(コンフィグファイル的なものとかを外出ししたり)
* アセンブリをがんばる


## Q1. メモリ節約のために一部の整数を4ビットで表していたが、それをやめたらメモリ使用量が逆に減った。なぜか？

コードのメモリ使用量がへったから


## Q2. 200x200でデータ要素が最大4000でその要素が200x200のいずれかのポイントに重複なく割り当てられるようなシステムでどのようにデータ構造を表現するか？

各要素にIDとcol, rowをもたせたデータ構造にして、それを4000個の配列にぶちこむ  
その際に、まずcolでソートして、その次にrowでソートした状態ではいれつにいれる。

と、なんかうまいこと行くんじゃないかな。

## Q3. tobasu

## Q4. コンピュータ以外でデータの保存場所を節約してる例をあげてみる

`y = x`

とかの数式ってメモリの節約といえないかな・・・？  
というのもこれって(0, 0), (0.1, 0.1)とか無数にある点を3文字で表しているから。

## Q5. 配列全体を記憶するメモリがなかったので関数で配列を表現してメモリの使用量を減らしたが、近似のため精度が低い場合があった、精度をあげるためには？

近似の精度が著しく低いところは誤差を記憶して、計算後足してやる。

## Q6. 数値a, bをc=10xa + bとすることでデータ圧縮したが、元のデータに戻す際にa = c /10, b = c % 10としたが、論理演算、テーブルを使ってはどうか？

変換テーブルを使う場合は、10x10のテーブルがあればOKだろう(たぶん)  
データ空間のメモリ使用量は増えるがコードはシンプルなのでそっちの使用料は減るだろう(たぶん)  
実行時間も早くなるはず(たぶん)

論理演算を使った場合は、たぶん計算時間ははやくなるんだろう(たぶん)  
ただ、コードが複雑になってコード使用メモリが増えそうな・・・(たぶん)

### 追記

論理演算に関してはいいことづくめらしい(この場合は)


## Q7. プロファイル作成ツールをデザイン

まったくわかりません

## Q8. MMDDYYYYの日付の表現を8バイト未満でお願いします

数値で表せば4バイトで行けるはず。

## Q9-11. とばす
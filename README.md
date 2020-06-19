# typing_game
マルチスレッドを理解するために作るCUIタイピングゲーム

## どんなの？
こんなのです。画像左が実行中のプログラム、右がソースコードになります。

画像１(難易度: 普通のプレイ開始)<br>
<img src="https://github.com/kentokura/typing_game/blob/master/img/seean1.png" width="480">
<br>

画像２(画面1から遷移, 難易度: 簡単のプレイ開始)<br>
<img src="https://github.com/kentokura/typing_game/blob/master/img/seean2.png" width="480">
<br>

画像３(画面2から遷移, ゲームオーバー)<br>
<img src="https://github.com/kentokura/typing_game/blob/master/img/seean3.png" width="480">
<br>

## 使い方

クローンしたファイル内で
```
./typing
```
と打つと始まります。

オプションで難易度を選択できます。
なにもつけなければeasyで始まます。
```
./typing --hard
```
オプション一覧
```
--hard, -h
--normal, -n
--easy, -e
```

## マルチスレッドの勉強がしたい。
POSIX準拠で書いています。
ソースコードは`typing.c`です。独学の助けになれば幸いです。
コンパイルは以下のコマンドでやるといいでしょう。
```
gcc typing.c -o typing -lpthread
```

わかるところなら回答いたします。

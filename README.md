# typing_game
マルチスレッドを理解するために作るCUIタイピングゲーム

## どんなの？
こんなのです。

画像

画像

画像

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

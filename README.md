# minitalk

C言語のシグナルを勉強しました。
簡易的なサーバーとクライアントを作成します。

## Usage 

サーバーを立ち上げます。

`shell 1`
```shell
$ make
$ ./server
 > This server's PID is '19613'
```

クライアントからメッセージを送信します。

`shell 2`
```
$ ./client hello
 > hello
```

サーバー側のShellにメッセージが出力されます。

`shell 1`
```shell
$ make
$ ./server
 > This server's PID is '19613'
hello
```


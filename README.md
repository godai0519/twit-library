twit-library
============
C++で書かれ，Boostにバリバリ依存する，OAuthライブラリ．誰得感があるけども気にしたら負け．  
[BoostConnect](https://github.com/godai0519/BoostConnect)という私自作通信用ライブラリの\includeディレクトリにパスを通しておく必要あり！

OAuthの複雑な認証をクラス化し，まとめることによって，数行でOAuth通信とそのレスポンスを取得することができます．  
またサービスごとに細かな設計の揺れを補正しています．  
Boost.Spirit.QiやKarmaを使用している部分があるため，コンパイル時間が長くなってしまいます．どうにか工夫して長くならない方法を検討していたりします．  
→ライブラリとして使用に

ということで，このライブラリはライブラリとして使用(事前に.aや.libを作成)する方法と，ヘッダーのincludeのみで使用する方法が選べます．  
それぞれの方法については「ライブラリとして使用」・「ヘッダーとして利用」の項を参照してください．  
ただしどちらを選んだ場合でも，同じ機能を利用することができます．しかし，ヘッダーとして利用する場合は毎回のコンパイル時間がめちゃくちゃ長くなります．

必要なもの
----------
+   [BoostConnect](https://github.com/godai0519/BoostConnect):
      通信部です．パスを通して置いてください．(ビルドの必要はありません)
      
+   [Boost C++ Library](http://www.boost.org/):
      大部分はこのライブラリに依存しています．ビルドしてパスを通して置いてください．
      
+   [OpenSSL](http://www.openssl.org/)
      SSL/TLS拡張を行う場合のみ，パスを通しておいてください．  
      `#define USE_SSL_BOOSTCONNECT`によってSSLが有効になります．

ライブラリとして使用
--------------------
生のままtwit-library(with BoostConnect)を使用すると，毎回のようにコンパイル時間が長くなり，大変なのです．  
そこで.a(Windowsでは.lib)としてlibrary化することができるようにしました．  

twit-libraryと同じディレクトリにBoostConnectをおいた後，
Windowsの場合はtwit-library.slnに存在しているtwit-libraryプロジェクトとboostconnectプロジェクトのインクルードパス・ライブラリパスを適宜変更の上，コンパイルさせてください．  
Linuxの場合はmakeを叩くだけで行けます（多分

どちらでビルドしてもlibディレクトリ下にlibboostconnect.*とlibtwit-library.*というライブラリができますので，利用する際にこれをリンクしてください．

ヘッダーとして利用
------------------
ヘッダーのincludeを行う前に`#define TWIT_LIB_LIB_BUILD`を書いてください．  
これだけでOKです．
	  
使い方
-------
使い方は[sample.cpp](https://github.com/godai0519/twit-library/blob/master/sample/sample.cpp)を見ると解りやすいかも知れません．  
それぞれのサンプルのコメントを全て外すと，SSL通信が確立します．

    std::shared_ptr<oauth::keys::key_version1> key(
      new oauth::keys::key_version1("consumer_key","consumer_secret"));
      
    // boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client);
    std::shared_ptr<oauth::protocol::client> connector(new oauth::protocol::client(io_service/*,ctx*/));
      
として，キーを登録したインスタンスと通信用インスタンスの作成．

    oauth::client<oauth::version::v1> client(key, connector);
    
で，それらの設定を持つクライアントを作成できます．  
あとはこのクライアントを

    client.get_request_token // リクエストトークン取得開始
    client.get_access_token  // アクセストークン取得開始
    client.request_***       // APIリクエスト(任意)
    
の順番で呼び出していくと，OAuthとして通信が可能です．

"twit-library"について
--------------------------
当初，OAuthとしてTwitterのみに対応しようと考えていたのでこの名前になりましたが，Twitter以外へのOAuth認証も可能です．  
紛らわしいですね．
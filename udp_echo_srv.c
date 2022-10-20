/* udp_echo_srv.c -- UDP ECHO server */

#include "einet.h"

void server(int s,struct sockaddr *peer,socklen_t plen){
    static char recv_buf[RECV_BUF_SIZE;

    int slen,rlen;

    while(1){
    /*
    * 送受信ループは無限ループで、抜ける条件はない。
    * プロセスの終了は、キー入力からのCTRL-C、または、killコマンドでプロセスを終了する。
    */
        rlen = recvfrom(s, recv_buf,sizeof(recv_buf),0,peer,&plen); 
    /*
    * エコークライアントから送信されたデータを受信する。
    * s:ソケットディスクリプタ。
    * recv_buf:受信データ。
    * peer:送信元(クライアント)のアドレス構造体。
    * plen:アドレス構造体(peer)のサイズのアドレス。
    * 送信元（peer）の情報を使ってエコーバックする。
    * recvfrom 関数の戻り値rlenの値によって動作を変える。
    * rlen>0:受信バッファ(recv_buf)の内容を表示する。
    * rlen<0:エラーを表示する。
    * rlen==0:何もしない。
    */

        print_local_name(s);
        print_peer_name(peer);

        if(rlen < 0)
            error(1, errno, "recvfrom failed");
        else if(rlen > 0){
            *(recv_buf + rlen) = 0;
            printfnl("%s",recv_buf);
        }
        if(sendto(s,recv_buf,rlen,0,peer,plen)< 0)
        /*
        * データを送信する。
        * s: ソケットディスクリプタ。
        * recv_buf: 送信データ(クライアントから受信したデータ)。
        * peer: 送信先(クライアント)のアドレス構造体。
        * plen: アドレス構造体(peer)のサイズ。
        */
            error(1, errno,"sendto failed");
    }
}
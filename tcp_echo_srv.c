/* tcp_echo_srv.c -- TCP ECHO server */

#include "einet.h"

void server(int s, struct sockaddr *peer,socklen_t plen){
    static char recv_buf[RECV_BUF_SIZE;

    int slen, rlen, total = 0;

    while(1){
    /*
    * 送受信ループは無限ループで、抜ける条件はない。
    * プロセスの終了は、キー入力からのCTRL-C、または、killコマンドでプロセスを終了する。
    */
        rlen = recv(s, recv_buf, sizeof(recv_buf),0); 
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
		if(rlen == 0)
			break;
		else if (rlen > 0){
			if (verbose)
				printfnl("recv: %6d", rlen);
			else if (dump)
				dump_recv((const uint8_t*)recv_buf, rlen);
		}
		else
			error(1, errno, "recv failed");
		total += rlen;

		if(!discard){
			if(send(s, recv_buf, rlen, 0) < 0)
				error(1, errno, "send failed");
		}
		//sleep(1);
	}
    if(shutdown(s, SHUT_WR) < 0)
		error(1, errno, "shutdown call failed");
	if(silent == 0)
		printfnl("recv total: %6d", total);
}

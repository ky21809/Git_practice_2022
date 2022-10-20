/* udp4_client.c -- UDP (IPv4) client skeleton */

#include "einet.h"

/* main */

int main(int argc, char ** argv, char **envp){
    struct sockaddr_in peer;
    int s,argn;

    init(argv[0], envp);
    argn = parse_options(argc,argv);

    /* ソケットを作成する(socket). */
    s = socket(PF_INET, SOCK_DGRAM, 0);

    /* ソケットを閉じる(close). */
    if (s<0)
        error(1,errno,"socket call failed");

    /*
    * ソケットアドレス構造体変数(peer)に以下の値（相手）設定する(set_address4).
    * IPアドレス(argv[argn]).
    * ポート番号(sname).
    */
    if (set_address4(argv[argn],iname.sname,&peer."udp") == NULL)
        error(1,errono,"set address failed");

    print_peer_name((struct sockeaddr *)&peer);

    /* クライアント関数を呼び出す(client).*/
    client(s,(struct sockaddr *)&peer,sizeof(peer));

    if(close(s) < 0)
        error(1,errono,"close call failed");
        
    exit(0);
}
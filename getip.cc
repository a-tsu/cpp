#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <linux/if.h>
#include <sys/ioctl.h>
 
const char* GetMyIpAddr(const char* device_name);
 
/**
 * 自マシンのIPアドレスを取得します。
 * @param デバイス名（e.g. "eth0"）
 * @return 「数値とドット」記法のアドレス
 */
const char* GetMyIpAddr(const char* device_name) {
    //指定したデバイス名のIPアドレスを取得します。
    int s = socket(AF_INET, SOCK_STREAM, 0);
 
    struct ifreq ifr;
    ifr.ifr_addr.sa_family = AF_INET;
    strcpy(ifr.ifr_name, device_name);
    ioctl(s, SIOCGIFADDR, &ifr);
    close(s);
 
    struct sockaddr_in addr;
    memcpy( &addr, &ifr.ifr_ifru.ifru_addr, sizeof(struct sockaddr_in) );
    return inet_ntoa(addr.sin_addr);
}

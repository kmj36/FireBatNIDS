#include <iostream>
#include <WinSock2.h>
#include "errproc.h"
#include "rules.h"
#include "Iputils/iputils.h"
#include "PacketHeaders/packetheader.h"

int main()
{
    WSADATA wsWsaData;
    if(errno_t nErr = WSAStartup(WINSOCK_VERSION, &wsWsaData) != 0)
       errproc::errOutExit(nErr);

    SOCKET sRawSocket = socket;

    WSACleanup();
    return 0;
}
#include "tcpheader.h"


int getSourcePort(const unsigned char *tcp_hdr)
{
    return (tcp_hdr[0] << 8) | (tcp_hdr[1]);
}

int getDestinationPort(const unsigned char *tcp_hdr)
{
    return (tcp_hdr[2] << 8) | (tcp_hdr[3]);
}

void setSourcePort(unsigned char *tcp_hdr, int port)
{
    unsigned char byte0 = (port >> 8) & 255;
    unsigned char byte1 = port & 255;
    tcp_hdr[0] = byte0;
    tcp_hdr[1] = byte1;
}

void setDestinationPort(unsigned char *tcp_hdr, int port)
{
    unsigned char byte2 = (port >> 8) & 255;
    unsigned char byte3 = port & 255;
    tcp_hdr[2] = byte2;
    tcp_hdr[3] = byte3;
}

int getAckFlag(const unsigned char *tcp_hdr)
{
    return (tcp_hdr[13] >> 4) & 1;  
}

void setAckFlag(unsigned char *tcp_hdr, int flag)
{
    if (flag == 0){
      tcp_hdr[13] &= ~(1 << 4);
    } else tcp_hdr[13] |= (1 << 4);
}

int getDataOffset(const unsigned char *tcp_hdr)
{
    return (tcp_hdr[12] >> 4) & 15;
}

void setDataOffset(unsigned char *tcp_hdr, int offset)
{
    int purified = (offset & 15) << 4;
    tcp_hdr[12] &= 15;
    tcp_hdr[12] |= purified;
}

enum class TcpUdp
{
    SECONDS = 1,
    MU_SECONDS,              

    PROTOCOL,       // tcp/udp
    SRC,
    DST,
    SPORT,
    DPORT,
    SENTPACKETS,
    SENTBYTES,
    RECVDPACKETS,
    RECVDBYTES,
    nFields,
};
    
enum class Icmp
{
    SECONDS   =   1,
    MU_SECONDS,              

    SRC,
    DST,
    ID,
    SENTPACKETS,
    SENTBYTES,
    RECVDPACKETS,
    RECVDBYTES,
    nFields,
};
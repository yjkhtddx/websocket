
#include <string>
#include <sys/epoll.h>

extern std::string getEpollEvnetName(uint32_t event){
    switch (event)
    {
    case EPOLLIN: return "EPOLLIN 可读";//表示对应的文件描述符可以读（包括对端SOCKET正常关闭）；
    case EPOLLPRI: return "EPOLLPRI 带外数据到来可读";//表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）；
    case EPOLLOUT: return "EPOLLOUT 可写";//表示对应的文件描述符可以写；
    case EPOLLRDNORM: return "EPOLLRDNORM";
    case EPOLLRDBAND: return "EPOLLRDBAND";
    case EPOLLWRNORM: return "EPOLLWRNORM";
    case EPOLLWRBAND: return "EPOLLWRBAND";
    case EPOLLMSG: return "EPOLLMSG";
    case EPOLLERR: return "EPOLLERR 错误";//表示对应的文件描述符发生错误；
    case EPOLLHUP: return "EPOLLHUP 被挂断";//表示对应的文件描述符被挂断；
    case EPOLLRDHUP: return "EPOLLRDHUP";
    case EPOLLEXCLUSIVE: return "EPOLLEXCLUSIVE";
    case EPOLLWAKEUP: return "EPOLLWAKEUP";
    case EPOLLONESHOT: return "EPOLLONESHOT 监听";//只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里
    case EPOLLET: return "EPOLLET 边缘触发";//将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)来说的。
    default: return "UNKNOW";
    }
}


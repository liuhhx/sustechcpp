#include <netinet/in.h>
// 小端转大端
// unsigned long int htonl(unsigned long int hostlong); // host to net long 用于转换ip
// unsigned long int ntonl(unsigned long int netlong); // net to host 

// unsigned short int htonl(unsigned short int hostshort); // host to net short 用于转换端口
// unsigned short int ntohl(unsigned short int netshort); // net to host
#include <iostream>
#include <vector>
using namespace std;
int main() {
    // htons
    unsigned short a = 0x0102;
    unsigned short b = htons(a);
    std:: cout << a<< "to " <<b << std::endl; 
    unsigned short c = 0x0201;
    std::cout << c << std::endl;
    // 转换成功

    // ntohl
    vector<unsigned char> ipaddr{192, 168, 0, 1};
    union {
        long int t;
        unsigned char ad[sizeof(long int)];
    }addr;
    addr.t = 192168000001;
    // uint32_t mid = 19216801;
    // cout << mid << endl;
    int num = *(int*)addr.ad;
    cout << addr.ad[0] << endl;
    auto mid = ntohl(num);
    cout << typeid(mid).name() << endl;
    cout << mid << endl;
    unsigned char * p = (unsigned char*)&mid;
    std::cout<< p[0] << std::endl;


}
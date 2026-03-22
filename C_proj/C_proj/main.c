#include <stdio.h>

int main(){
    int gold = 999;
    int *p;
    p = &gold;
    printf("变量gold的值是：%d\n",gold);
    printf("变量gold的内存地址是：%p\n",&gold);
    printf("指针p记录的内容是：%p\n",p);
    printf("通过指针p钻进去看的值是：%d\n",*p);
    return 0;
}

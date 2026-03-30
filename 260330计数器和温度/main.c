#include "main.h"
//use "main.h" file

int main(){
    int times;
    //times，是int的一个整数的自定义名
    
    int count = 0;
    //count,也是一个整数，但目前给予赋值0
    
    printf("%s\n", APP_TITLE);

    //显示APP_TITLE这个字符串到屏幕，并换行
    
    printf("你想听几遍“你好!");
    // 这是单纯的显示
    
    scanf("%d", &times);
    /*scanf是将%d的键盘敲入，存入到times的地址里。换句话说，此时%d就是times地址里面的内容*/
    
    /* 只要count 小于 times，就一直循环
     由于一开始就 int count = 0，所以times=n，那么循环就会有n+1
     while 在英文里是“当……的时候”的意思。
     它的逻辑极简：只要 () 里的条件是真的，{} 里的代码就一遍又一遍地跑。*/
    while (count < times){
        count = count + 1;
        printf("第 %d 遍，你好！", count);
        
    }
    
    printf("\n 程序完成，程序退出 \n");
    /* 这里是在while命令结束后的情况，隐藏的内容是
     while (count !< times){} */
    
    return 0;
    
    
}


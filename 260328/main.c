//2026.3.28

#include "main.h"
// we defined main.h before,it contain define "main_h",and defined a "WELLCOME_MSG" to "Nice to see U"

int main(){
    //int main(),()is empty,()will include all in {}
    int input_num;
    /* “声明一个整数变量，用来存放输入的数字“，这里的input_num是一个固定的格式吗？ */
    
    printf("%s\n", WELLCOME_MSG);
    /* 这里的%s\n，如果不加引号，xcode会提示"use of undefined 's'
     为什么只是提示没有定义s？
     %和\n系统都可以认识？是这个意思吗？
     s的意思是字符串 */
    
    printf("enter a Number");
    /* 这里是显示在屏幕上引号内的内容 */
    
    //scanf("%d",&input_num);
    /*  这里的scanf，是读取
     %d，这时，scanf就会停下来，等待%d的出现*/
    
    if (scanf("%d",&input_num) == 1){
        /*这里加入了判断，是否输入的字符符合%d的标准，如果符合，就会产生1，非零的情况，就进行奇偶数的判断
         如果不符合，就告诉不符合，*/
        
        if (input_num % 2 == 0){
            printf("%d 这是一个偶数\n",input_num);
            /* 这是对if命令做出判断的内容，%在这里是除法看余数，就是说除以2，余数如果是0 */
            /* 这里有两个if形成了连续的判断，而初步运行后发现程序不能继续运行，在我输入数字后，没有进一步的动作，是不是这两个if形成了问题？
             是否应该在这两个if之间增加点什么？*/
        }
        else {
            printf("%d 这是一个奇数\n",input_num);
            
        }//这个}是匹配else的
    }
        
        else {
            printf("没有接收到数字格式，无法计算");
        }
        
       
        
    
    return 0;
  
           /* 运行到这里，程序就完成了，return 0 */
    
}


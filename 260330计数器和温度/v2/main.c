#include "main.h"
//use "main.h" file

int main(){
    
    char choice = 'y';
    /*初始为y，确保循环开始*/
    
    int count = 0;
    //count,也是一个整数，但目前给予赋值0
    
    float input_v, output_v;
    //定义了两个小数的名字，一个input_v,另一个 output_v,......
    
    int mode;
    //定义了一个整数，mode
    
    printf("你想要转换 摄氏度 与 华氏度 吗？\n,请输入y 或 n\n");
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y'){
        /* 这三行是我加的，在while前先设定一个y或n的输入，将y的三种情况都包进去
         然后再接一个else，是非y的选项*/
        
        
        while (choice == 'y' || choice == 'Y'){
            /* 这里当choice等于y或Y时。为什么大写的Y和小写的y可以一样？之前的char 赋值了choice是小y。*/
            
          
            
            printf("\n ---第 %d 次计算开始----\n", count);
            printf("请选择模式： （1:C-》F， 2:F-〉C）：  ");
            //这里的引号内容是字符串，所以我故意混淆中文的符号进去，看会不会报错
            
            scanf("%d", &mode);
            /*输入这个1或2后，赋值给mode，但这里输入的如果不是1和2，会报错，下面就是分别对这三种情况进行分类，1、2、非1和2时，用if 1，else if2，else 3 */
            
            if (mode == 1){
                printf("请输入摄氏度： ");
                scanf("%f", &input_v);
                /* 此处的%f是一个小数，但是没有规定小数点后多少度
                 同时，xcode提示，%f应该用‘’，但此时用了双引号？*/
                
                output_v = input_v * 1.8 + 32;
                printf("结果：%.2f 摄氏度 = %.2f 华氏度", input_v, output_v);
            }
            
            else if (mode == 2){
                printf("请输入华氏度： ");
                scanf("%f", &input_v);
                output_v = (input_v -32) / 1.8;
                printf("结果：%.2f 华氏度 = %.2f 摄氏度", input_v, output_v);
                
            }
            else {
                printf("错误，请输入正确的选择，1 或 2");
                count--;
                
                /* 这里的count--，是不计入count，换言之，选1或2都有计入，但没有写在if和else if里面，而是*/
            }
            
            printf("\n还需要继续吗？（y / n）: ");
            scanf(" %c", &choice);
            //此处的%c前加了一个空格，以免将多余的空格读入
        }//its while }
        
    }//its first if }
    else {
        printf("不选y，不运行");
        /*这个else是我加的
         这样的话，是否也可以实现gemini的版本同样效果？*/
    }
    count++;
    //count++,应该是count =（count + 1）； 的简写？
    printf("任务结束，你本次一共处理了 %d 个数据\n", count);
    return 0;
    
    
}//its int main() }



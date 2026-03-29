#include "main.h"

int main(){
    float input_val, result;
    /* float 浮动的，也许所谓“浮点计算”的浮点？小数点？
     input_val，输入一个value，一个值。这是命令还是自定义的语句？目前看像是命令
     result，因为前面没有定义result，暂时也当他命令
     那么会有两个命令？
     */
    
    int choice;
    /* int 这是取一个整数值
     choice？命令还是自定语？
     */
    
    printf("%s\n", APP_TITLE);
    /* printf，打印内容到屏幕上
     “%s”，这是一个string，字符串
     APP_TILTLE，在main.h中已经定义了，标题*/
    
    printf("请选择模式： \n1. 华氏度--》摄氏度\n2.摄氏度--〉华氏度\n选择（1或2）： ");
    /* 几个疑问：\n 是换行，显示的应该是
     "请选择模式：
     \n1. 华氏度--》摄氏度
     \n2.摄氏度--〉华氏度
     \n选择（1或2）： "
     
     至于为什么"\n"直接连在前面的文字后，是为了换行后保持一致
     如果为了读代码容易，也可以
     " 请选择模式：  \n1. 华氏度--》摄氏度 \n2.摄氏度--〉华氏度 \n选择（1或2）： "
     这样，每行前插一个空格，最后应该也会对齐*/
    
    scanf("%d", &choice);
    /* scanf，scan键盘的输入，简单理解为输入
     %d，这是一个数字，整数的数字
     &choice，choice的地址，前面13行，int choice了，int命令后，系统会划分一个地址，名字是可以自己取的*/
    
    if (choice == 1){
        /* 关于空格，printf，scanf，括弧都是直接紧挨着，为什么这个if后面要空一格？
         如果 choice == 1，这里choice是键盘输入的，对照的是line21的选择模式*/
        
        printf("请输入华氏度：");
        //这里只是单纯显示，没有输入内容
        
        scanf("%f",&input_val);
        /* scanf，输入一个%f格式的值，%f是什么？input_val 在line4行用float定义了，括弧内逗号后是result，float命令需要讲解*/
        
        result = (input_val - 32) / 1.8;
        //这里是赋值给result，输入的数字先减去32，再除以1.8
        
        printf("结果：%.2f 华氏度 = %.2f 摄氏度 \n",input_val,result);
        /* 这里的result是计算后的，%.2f其实都是%f，只是保留输出2位小数点，分别填入input_val和 result*/
    }
    //这里，if{}结束了，在这个if情况下，是输入了“华氏度”，匹配的是%f
    
    else if (choice == 2){
        /* else 否则，能理解
         if 后面又有个空格
         choice == 2.这里是line21的选择2 */
        
        printf("请输入摄氏度：");
        //这里和line42一样，单纯是显示
        
        scanf("%f", &input_val);
        /* 输入一个%f，代表的是 input_val的地址，和line45一样，需要解释，这输入的是摄氏度，也就是模式2*/
        
        result = (input_val * 1.8) + 32;
        /* 公式： F = C * 1.8 +32,
         这里满突兀的，也就是说，result是一个命令，甚至是针对性的“算式的结果”，所以可以直接上公式？ */
        
        printf("结果： %.2f 摄氏度 = %.2f 华氏度\n", input_val, result );
        /* 这个输出，把result（输入的数字*1.8+32）放到input_val里，因为输入的是摄氏度如80，则result是176
         “%.2f 摄氏度 = %.2f 华氏度”  什么意思？需要解释 */
        
         }
    //到这里，else if 结束了
    
    else {
        printf("选择错误，程序退出。\n");
        //这里是单纯输出，这个else对应的是不选1和2，选了个奇怪的东西，那就弹错误
        //是否可以在这里写入 "return 1;"  是否等效？ ?
    }
    //这里是else的结束
    
    return 0;
    /* 告诉“程序”？“系统”？  运行好了
     其实72行的else，是否也可以直接在75行那样写？*/
    
}
//这里是int main（）的结束符

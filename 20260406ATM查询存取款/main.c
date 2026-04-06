#include "main.h"

int main() {
    //main()和{}间，应该有一个空格？还是没有差别？
    
    //一、以下设置变量
    float balance = START_BALANCE ;
    //1、我又留了一个空格在；前，看看有没有差别？2、这里是设置一个带小数的变量，没有说明小数点后几位
    
    float total_profit = 0.00000;
    //此处我设置利润小数点后5位
    
    int choice = 0;
    //这是给用户的选择，初始为零，用户选择1-4，意外情况是非1-4
    
    float amount;
    //这是设了一个数字的，叫做amout，暂时没有给他赋值
    
    int op_count = 0;
    //这是操作的次数统计，初始为0
    
    //二、读取历史盈余，持久化数据加载
    
    //尝试以“R”模式打开利润文件
    FILE *f_read = fopen(PROFIT_FILE, "r");
    /* FILE 应该是一个固定的命令，说明是文件
     *f_read，需要解释，是否也是固定的？下面有f_read命令，那么这个*是干嘛的？
     fopen是固定的命令，后面带（），（）内的逗号前，是指定的文件，逗号后是说明fopen的模式，有r只读、w写入，a？等等？*/
    
    if (f_read != NULL){
        //如果file read 不等于 空，也就是有文件
        fscanf (f_read, "%f", &total_profit);
        //那么读取&tatol_profit里面的数字，是一个%f的数字。这里的疑问在于，为什么上面的fopen（）内是先文件，再模式，而此处的顺序不一样？
        
        fclose(f_read);
        //读取好后就关掉。如果没有关掉，那么这个文件在开启状态，会阻碍写入吗？
        
        
    }/* 这是if（f_read ！= NULL）的大括号，此if结束
      这个if规定了先读取文件，如果没有文件，那么fscan也会自己创建一个吗？
      接下来就是用户看到的内容了*/
    
    //3、打印欢迎界面
    
    printf("*************************************\n");
    printf("%s\n", BANK_NAME);
    //此处%s是一个字符串，将之前定义的BANK_NAME替换进入，如果将来要换银行名字，只要到main.h里去改这个BANK_NAME
    
    printf("SYSTEM IS READY,BANK's PROFIT is %.5f dollar \n", total_profit);
    //这的%f的取值，是来自于total_profit，数字来自前面的fscanf从&total_profit里读取
    
    printf("*************************************\n*************************************\n");
    //我这里放了两个\n，应该呈现出两行的******效果
    
    //4、业务主循环
    
    while (choice != 4){//只要不选择4，就继续运行
        printf("\n请输入数字选择业务： 1查询 2存款 3取款 4退出\n");
        printf("请输入数字");
        scanf("%d",&choice);
        //这里是读取%d格式的键盘输入数据，这个数据是choice的地址中的内容
        //到一步，用户输入了选择
        
        if (choice == 1){
            printf("查询模式：您当前的账户余额为 %.2f dollar\n",balance);
            //这里的思考，我应该将balance也变得可持续，应该在main。h里再设置一个current_money，并将这个数据也fscanf 到一个current_money.txt中去
            
            op_count ++;
            //这里操作成功了一个，在操作数量里加一
    
        }//this is if=1 's }
        
        else if (choice == 2){
            printf("存款模式：请输入存款金额：");
            scanf("%f", &amount);
            //存款会出现的情况要在下面全覆盖，>0 0 <0
            
            if (amount > 0){
                balance += amount;
                //same as "balance = balance + mount;"
                printf("存款成功，您目前的余额为%.2f dollar\n",balance);
                //这里有一个问题，给客户显示的是2位小数的金额，但银行利润是按照5位小数。当银行有利润但不满0.01时，系统会怎么计算呢？将客户的金额直接扣掉0.1吗？
                
                op_count ++;
                
            }//这是if>0，零两种情况0或负数都是无效的，所以下面用一个else就可以了
            else {
                printf("金额无效，请输入正数 \n");
                
            }
        }//else if choice == 2 's }
        
        else if(choice == 3){
            printf("欢迎取款，请输入取款金额 \n");
            scanf("%f",&amount);
            
            
            float fee = amount * TAX_RATE;
            float total_deduct = amount + fee;
            /*计算总共要扣除多少钱，那么产生几个结果，钱够，钱不够
             思考：写一个程序，其实是分解这个目的，达到目的会产生分枝，用命令将分枝说明白，并分别给予对应的行动
             比如用户只能选择1-4，除了1-4都是非法
             那么就是 if==1，if==2，if==3，if==4，else，这5种可能*/
            
            //计算总共要扣除多少钱，那么产生几个结果，钱够total_deduct <= amount，钱不够就是>
            if (total_deduct > balance){
                printf("你钱不够，穷鬼");
            }
            else{
                balance -= total_deduct;
                total_profit += fee;
                printf("取款成功！手续费：%.4f 元，实际扣除 %.2f 元　\n", fee, total_deduct);
                //这里就体现之前我考虑的矛盾了，手续费虽然只有小数点4位，但只要大于4位，就扣除了小数点2位，
                
                printf("您的余额为 %.2f 元\n",balance);
                
                op_count ++;
                
                
            }
            
        }//else if choice ==3 's}
        
        else if (choice == 4){
            printf("%s\n","正在为您退出");
            //此处有疑问，printf直接“正在为您退出”就可以了，为什么要先“%s”？
            
        
        }
        
        else {
            printf("错误，请重新输入 \n");
            
        }
        
    }//this is while's }
    
    /* 以上，1234都是if1，else if2，else if3，else if4，else
     没看出来选4会退出啊？程序并没有结束啊？？*/
    
    //5、保存最新盈利
    
    FILE *f_write = fopen(PROFIT_FILE,"w");
    if (f_write != NULL){
        fprintf(f_write, "%.4f", total_profit);
        fclose(f_write);
        //此处的命令同样出现了*，以及f_write，需要解释
        //这里的total_profit是按%.4f来增加，那么会产生一个问题：客户的钱是按%.2f扣除，我们的利润是按%.4f增加，会消失掉一部分钱。这些钱应该也要作为profit来进入，否则就真消失了
        
        
    }
    
    //6、结束
    printf("\n----------------------------\n");
    printf("任务完成，您本次共进行了 %d 次有效操作\n",op_count);
    printf("感谢使用\n");
    
    return 0;
    
    
    
    
    
    
}//这是int main（）的大括号

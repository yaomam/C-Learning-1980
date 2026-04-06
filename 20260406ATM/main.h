#ifndef main_h
#define main_h

#include <stdio.h>
//对于#的使用，是否都是一次性的？#if-not-define #define #include <some.h>，一次读取就行了，下次运行再读一次,另外，#后不用；

//---baisc Info---
#define BANK_NAME "通用银行（GBNK）"
//此处，我将GBNK的括弧用了中文字符，由于在""内，应该不会报错？

#define PROFIT_FILE "profit.txt"
//这里定义了profit文件，profit.txt，虽然文件还没创建，但可以在main.c里面将文件对应

#define TAX_RATE 0.001

#define START_BALANCE 1000.00
/*此处定义初始金额，1000.00，但gemini写的是1000.0，有差别吗？在后续的f定义中应该要定义小数点后5位，否则无法计算取出小数点后2位时的对应利润*/

#endif




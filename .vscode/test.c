#include <stdio.h>

int main() {
    char name[50];
    printf("环境修复成功！请输入你的名字: ");
    
    // 获取用户输入
    scanf("%s", name);
    
    printf("你好, %s! 欢迎来到 C 语言的世界。\n", name);
    return 0;
}
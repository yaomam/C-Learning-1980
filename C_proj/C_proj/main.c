#include <stdio.h>

int main(){

    //1,打开数据文件（r+ 代表读写模式）
    FILE *fp = fopen("data.txt", "r+");
    if (fp == NULL){
        printf("cant find doc! \n");
        return 1;
    }
    
    //2.指针定位：我们要跳过“score：”这7个字符，或许是6个？
    //fseek 就像在内存里移动指针一样，在文件里移动“光标”
    fseek(fp, 7, SEEK_SET);
    
    //3.改写，在那个位置写入“y”
    fputc('y',fp);
    
    //3.1，在写下一段话之前，告诉指针去文件的末尾
    fseek(fp,0,SEEK_END);
    
    //3.5 add
    fprintf(fp,"\n 'hi here,I am hacker!'");
    
    //4.关闭文件
    fclose(fp);
    
    printf("modify has done!\n");
    return 0;
}

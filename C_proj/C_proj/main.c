#include <stdio.h>

int main(){
    FILE *fp = fopen("data.txt","a");
    printf("at first fp cur at: %ld\n",ftell(fp));
    for (int i =1; i<=188; i++){
        fprintf(fp, "%d\n",i);
    }
    if (fp == NULL){
        printf("权限失败，请检查 \n");
        return 1;
        
    }

    //fputs("aaa\nbbb\nccc\n",fp);
    
    fclose(fp);
    
    fp = fopen("data.txt","r");
    if (fp == NULL){
        perror("error");
        return 1;
    }
        char buffer[1024];
        if (fgets(buffer, 1024, fp) != NULL){
            printf("第一行是： %s",buffer);
            printf("now fp cur at: %ld\n",ftell(fp));
        }
            if (fgets(buffer,1024,fp) != NULL){
                printf("2end line is: %s", buffer);
            }
    printf("and now the fp cur at: %ld\n",ftell(fp));
    fseek(fp,0,SEEK_END);
    long size = ftell(fp);
    printf("total size is : %ld byts\n",size);
    if (size < 1000L){
        long size = ftell(fp);
        printf("HEIHEIHEI %ld \n",size);}
        if (size == 1000L){
            long size = ftell(fp);
            printf("HAHAHA %ld \n",size);
        }
    
    if (size > 1000L){
        long size = ftell(fp);
        printf("HOHOHO %ld \n",size);
        
    }
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
    
    fp = fopen("data.txt", "r");
    if (fp == NULL) return 1;
    
    rewind(fp);
    long sum =0;
    int current_num =0;
    int even_count = 0;
    int count = 0;
    while (fscanf(fp, "%d", &current_num) != EOF){
        if (current_num %2 == 0){
            sum += current_num;
            even_count++;
        }
        if (++count % 100 == 0){
            printf("已经扫描 %d 个数字。。。\n",count);
        }
    }
    printf("统计完毕！\n");
    printf("共发现偶数：%d 个\n",even_count);
    printf("所有偶数相加的总和是： %ld\n", sum);
    
        fclose(fp);
    return 0;
}

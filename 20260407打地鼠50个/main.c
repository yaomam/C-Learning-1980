#include "main.h"

//发牌
void setup_map(int *map){
    //void是一个不要求return 0或1的命令，先布置环境，再进行 int main（）{}--return 0
    
    for (int i = 0; i< GRID_SIZE; i++) {
        if (i< MOLE_COUNT){
            map[i] = 1;
        }
        else{
            map[i] = 0;
            //[i],[]的意思？数组？什么意思？为什么用在这里？
            //map是一个命令吗？如果是写入，为什么不用fscanf？
        }
    }//for }
    
    //洗牌
    for (int i = GRID_SIZE - 1; i > 0; i--){
        int j = rand() % (i + 1);
        //定义j，这行需要详细解释@Gemini，为什么这样就能产生索引位置？以及作用？
        
        int temp = map[i];
        map[i] = map[j];
        map[j] = temp;
        //这里我能理解，先把i放在临时位置，再用j替换i，再将temp也就是i来替换j
        
    }//for }
}//这是void的}


//开始探查
//问题，前面已经开始程序，为什么不把int main()放到最前面？
int main(){
    int grid[GRID_SIZE];
    //这是声明100个格子的数组，需要详细解释概念
    
    int found = 0;
    int miss = 0;
    
    //第一步，准备地图
    
    srand(time(NULL));
    //这是常例写法，用当前时间来播种，确保每次运行的地鼠位置都不一样
    
    setup_map(grid);
    //模块A里，void了一个setup_map（int *map），并结合main.h，填写了小于MOLE_COUNT的1，由于从0开始，0-49就是50个，所以写了50个1
    //但void和这个代码仍然不明白，gemini说是调用了A来铺设地图
    
    //第二步，建立多级指针
    int *arrow = grid;
    int **mouse = &arrow;
    printf("10X10地鼠探测器启动\n");
    
    //第三步，开始线性探测
    for (int i = 0; i < GRID_SIZE; i++){
        if (**mouse == 1){
            found++;
            printf("步数 %02d | 地址 %p | 抓到地鼠 %d 只\n", i + 1, *mouse, found);
            
        }else{
            miss++;
            printf("步数 %02d | 地址 %p | 空地 %d 个\n",i + 1,*mouse,miss);
        }
        
        if (found == MOLE_COUNT || miss == (GRID_SIZE - MOLE_COUNT)){
            printf("探测终止");
            printf("原因：已经确认到50个同一结果，空地-- %d ： 地鼠-- %d \n",miss,found);
            printf("最终步数统计: %d 步（节省了 %d 步）\n",i + 1, GRID_SIZE - (i + 1));
            break;
        }
        
        *mouse = *mouse + 1;
        //这句的意义何在？前面已经进行了计算，并且得到50的数字了才退出，这时候将*mouse移动，有什么作用呢？
    }
        FILE *f_map =fopen(MAP_FILE, "w");
        if (f_map != NULL){
            for (int i = 0;
                 i < GRID_SIZE;
                 i++){
                fprintf(f_map, "%d", grid[i]);
                //把打乱后的地图存进文本文件
                
                if ((i + 1) % 10 == 0) fprintf(f_map, "\n");
                //这是gemini说的：每10个换一行，存成10X10的样子
                //我还没理解
            }
                fclose(f_map);
                printf("\n地图快照已存入： %s\n",MAP_FILE);
            
        
    }
    return 0;
}//int main() }

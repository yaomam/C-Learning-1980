#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <curl/curl.h>
#include <sys/stat.h>
#include <ctype.h>

#define STALK_COUNT 50
#define RAW_POOL_SIZE 150 
#define DELAY_SEC 10

typedef struct {
    int id;
    double val;
    char tag; // 'H'-Heaven, 'E'-Earth, 'P'-People
} Stalk;

struct MemoryStruct { char *memory; size_t size; };

// --- 基础工具 ---
void sanitize_string(char *str) {
    char *p = str, *q = str;
    while (*p) { if (isalnum((unsigned char)*p)) *q++ = *p; p++; }
    *q = '\0';
}

void wait_key() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

long long get_nanos() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000000L + ts.tv_nsec;
}

// 模拟跳动的 16 进制滚动效果（增加了实时索引显示）
void entropy_scrolling_display(int idx, char tag, double val) {
    printf("  [%03d] 源:%s | 熵值:0.%.0f... | 信号:0x%08X\n", 
           idx, (tag=='H')?"天":(tag=='E')?"地":"人", val*1e9, (unsigned int)(val*0xFFFFFFFF));
    usleep(20000); 
}

double get_hardware_entropy() {
    unsigned int val;
    FILE *f = fopen("/dev/urandom", "r");
    if (f) { fread(&val, sizeof(val), 1, f); fclose(f); }
    else { val = (unsigned int)get_nanos(); }
    return (double)val / 4294967295.0;
}

static size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t res = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)stream;
    char *new_ptr = realloc(mem->memory, mem->size + res + 1);
    if (!new_ptr) return 0;
    mem->memory = new_ptr;
    memcpy(&(mem->memory[mem->size]), ptr, res);
    mem->size += res;
    mem->memory[mem->size] = 0;
    return res;
}

// --- 核心业务：100(天/地) + 50(人) = 150 ---

void gather_cosmic_energy(Stalk *pool) {
    CURL *curl;
    struct MemoryStruct chunk = {NULL, 0};
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    printf("\n【第一阶段：感应天地 - 建立 100 维原始场】\n");
    
    // 抓取 50 天 (Heaven)
    curl_easy_setopt(curl, CURLOPT_URL, "https://services.swpc.noaa.gov/products/solar-wind/plasma-5-minute.json");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
    curl_easy_perform(curl);
    
    for(int i=0; i<50; i++) {
        pool[i].id = i; pool[i].tag = 'H';
        pool[i].val = (chunk.size > 0) ? ((double)chunk.memory[i % chunk.size] / 255.0) : get_hardware_entropy();
        entropy_scrolling_display(i, 'H', pool[i].val);
    }

    // 补完 50 地 (Earth)
    for(int i=50; i<100; i++) {
        pool[i].id = i; pool[i].tag = 'E';
        pool[i].val = get_hardware_entropy(); // 此处可后续替换为地震局API
        entropy_scrolling_display(i, 'E', pool[i].val);
    }
    
    if(chunk.memory) free(chunk.memory);
    curl_easy_cleanup(curl);
    printf(">> [系统] 天地 100 维基准场构建完成。\n");
}

void gather_human_energy(Stalk *pool) {
    printf("\n【第二阶段：注入灵觉 - 补完 150 维全息场】\n");
    printf("请通过五次连续敲击，激活计算机硬件底层熵流...\n");
    for(int i=0; i<5; i++) {
        printf("  脉冲注入点 %d >>> ", i+1); wait_key();
        for(int j=0; j<10; j++) {
            int idx = 100 + (i*10) + j;
            pool[idx].id = idx; pool[idx].tag = 'P';
            pool[idx].val = get_hardware_entropy();
            entropy_scrolling_display(idx, 'P', pool[idx].val);
        }
        printf(" [锁定]\n");
    }
}

void final_collapse(Stalk *raw, Stalk *selected, FILE *log) {
    printf("\n【第三阶段：观察者介入 - 150 选 50 坍缩】\n");
    printf("一百五十枚筹策已就位。请屏息凝神，按下决断之键...\n");
    
    wait_key(); 
    long long seed = get_nanos();
    printf("\n>> [坍缩] 随机种子哈希: 0x%llX\n", seed);
    
    srand((unsigned int)seed);
    int used[150] = {0};
    for(int i=0; i<50; i++) {
        int r;
        do { r = rand() % 150; } while(used[r]);
        used[r] = 1;
        selected[i] = raw[r];
        // 将坍缩后的种子及其来源标记详细存入日志
        fprintf(log, "[COLLAPSE_STALK_%02d] INDEX:%03d TAG:%c VAL:%f\n", i, selected[i].id, selected[i].tag, selected[i].val);
    }
}

// 傅氏占卜：仅第一变挂一
int divination_logic(int count, int c_idx) {
    int left = (rand() % (count - 10)) + 5;
    int right = count - left;
    int hung = (c_idx == 1) ? 1 : 0;
    if (hung) right--;

    int l_rem = left % 4; if(l_rem == 0) l_rem = 4;
    int r_rem = right % 4; if(r_rem == 0) r_rem = 4;
    int total = l_rem + r_rem + hung;

    if (c_idx == 1 && total != 5 && total != 9) total = (total > 6) ? 9 : 5;
    if (c_idx != 1 && total != 4 && total != 8) total = (total > 6) ? 8 : 4;
    return total;
}

int main() {
    char name[128], addr[128], ques[512], filename[512];
    FILE *log_fp = NULL;
    
    printf("================================================\n");
    printf("   大 衍 数 字 孪 生 引 擎 V5.3 (三才全显化版)\n");
    printf("================================================\n\n");

    printf("请虔诚输入您的名讳: ");
    fgets(name, sizeof(name), stdin); name[strcspn(name, "\n")] = 0;
    printf("请告知您当下的所处方位: ");
    fgets(addr, sizeof(addr), stdin); addr[strcspn(addr, "\n")] = 0;
    printf("请坦承输入您心中的困惑: ");
    fgets(ques, sizeof(ques), stdin); ques[strcspn(ques, "\n")] = 0;

    time_t t = time(NULL); struct tm tm = *localtime(&t);
    char cn[128], ca[128]; strcpy(cn, name); sanitize_string(cn);
    strcpy(ca, addr); sanitize_string(ca);
    mkdir("YILOG", 0777);
    sprintf(filename, "YILOG/%04d%02d%02d%s%s.log", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, cn, ca);
    log_fp = fopen(filename, "w");

    Stalk raw_pool[RAW_POOL_SIZE], stalks[STALK_COUNT];
    
    // 执行精准采集
    gather_cosmic_energy(raw_pool);
    gather_human_energy(raw_pool);
    
    // 写入 150 全量原始数据到日志，供后期审计
    fprintf(log_fp, "USER:%s | ADDR:%s\nQUESTION:%s\n--- RAW 150 ENTROPY POOL ---\n", name, addr, ques);
    for(int i=0; i<150; i++) {
        fprintf(log_fp, "[%03d][%c] %f\n", i, raw_pool[i].tag, raw_pool[i].val);
    }
    fprintf(log_fp, "\n--- COLLAPSE SELECTION ---\n");

    final_collapse(raw_pool, stalks, log_fp);

    int hex_vals[6]; double h_p[6], e_p[6], p_p[6];

    for(int i=0; i<6; i++) {
        printf("\n【第 %d 爻 推演中】\n", i+1);
        int cur_n = 49;
        for(int c=1; c<=3; c++) {
            printf("  (%s) 止念静默 %d 秒...", (c==1)?"第一变：挂一":(c==2)?"第二变：不挂":"第三变：不挂", DELAY_SEC);
            for(int s=DELAY_SEC; s>0; s--) { printf(" %d..", s); fflush(stdout); sleep(1); }
            printf(" 敲击！"); wait_key();
            cur_n -= divination_logic(cur_n, c);
            printf(" -> 剩余: %d\n", cur_n);
        }

        int th=0, te=0, tp=0;
        for(int k=0; k<cur_n; k++) {
            if(stalks[k].tag == 'H') th++; else if(stalks[k].tag == 'E') te++; else tp++;
        }
        h_p[i] = (double)th/cur_n * 100; e_p[i] = (double)te/cur_n * 100; p_p[i] = (double)tp/cur_n * 100;
        hex_vals[i] = cur_n / 4;
        fprintf(log_fp, "爻%d: %d | H:%.1f%% E:%.1f%% P:%.1f%%\n", i+1, hex_vals[i], h_p[i], e_p[i], p_p[i]);
    }

    printf("\n================================================\n");
    printf("推演圆满。灵觉记录已封存于: %s\n\n", filename);
    for(int i=5; i>=0; i--) {
        const char* sym = (hex_vals[i]==6)?"-- -- [老阴 X]":(hex_vals[i]==7)?"——    [少阳]":(hex_vals[i]==8)?"-- -- [少阴]":"——    [老阳 O]";
        printf("第%d爻  %s  能量构成:天%.0f%% 地%.0f%% 人%.0f%%\n", i+1, sym, h_p[i], e_p[i], p_p[i]);
    }
    printf("\n================================================\n");

    fclose(log_fp);
    return 0;
}
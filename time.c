#include <stdio.h>
int main() {
int birth_year = 1980;
printf("\n   请输入你的年纪   \n"）
int current_age;
scanf("%d", &current_age);
int calculated_year = 2026 - current_age;
printf("\n--- 时光机扫描结果 ---\n");
printf("I Think Your Age is: %d\n",calculated_year);
if (calculated_year == birth_year){
    printf("yes,you r a 1980's solider! \n");
}else {
    printf("note:r u sure? \n");
}
    return 0;
}

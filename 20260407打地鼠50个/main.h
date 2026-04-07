#ifndef main_h
#define main_h

#include <stdio.h>

#include <stdlib.h>
//std-standad，lib- library？
//这是一个标准库，是为了能调用 rand-random；srand-setRandom；和malloc-？

#include <time.h>
//time.h会提供一个池子，从1970年1月1日零点起，到现在的全部秒数。由于“现在”是个时刻变大的数字，也就使这个池子每一次出现都不同。所以将time.h作为数字的池子，从中提取随机数

#define GRID_SIZE 100
//定义了GRID_SIZE是100，GRID_SIZE是格子的意思？这个起名请解释@gemini

#define MOLE_COUNT 50
//定义了mole的数量，是50个

#define MAP_FILE "map.txt"
//为什么这个file用“”，而前面的50和100都不用标“”

#endif
//为什么是end if，而不是end define？
//为什么是end if，而不是end define？

#include <time.h>
#include "timelcs.h"

void timelcs(void (*callback), char stringA[], char stringB[]){
    /* ---时间记录函数-----------------------------------------
     * 接受一个计算最长公共序列函数指针以及两个字符串作为参数, 
     * 计算两个字符串的最长公共子序列，记录并输出运行时间
     * ------------------------------------------------------*/
    // 定义函数运行开始时间和函数运行结束时间
    time_t start_time, end_time;  
    // 定义运行总时长变量
    double time_duration;  
    
    time(&start_time);
    // 计算lcs
    callback(stringA, stringB);
    time(&end_time);
    time_duration = difftime(end_time, start_time);
    printf("耗时:%fs\n", time_duration);
}

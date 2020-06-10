#include <stdio.h>
#include<time.h>

int fib(int n);

int main(int argc, char const *argv[]){
    int n = 64;
    int res;
    time_t start_time, end_time;
    double diff_time;

    for(int i = 0; i < n; i++){
        time(&start_time);
        res = fib(i);
        time(&end_time);
        diff_time = difftime(end_time, start_time);     
        printf("fib(%d) = %d, 耗时%fs\n", i, res, diff_time);
    }
}

int fib(int n){
    return (2 > n) ? n : fib(n-1) + fib(n-2);
}


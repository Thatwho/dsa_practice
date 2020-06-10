#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[]){
    time_t start_time, end_time;
    double time_diff;
    const int n = 64;
    for(int i = 1; i < n; i++){
        time(&start_time);

        int pre = 0;
        long int res = 1;
        int ope = i;
        while (0 < ope--) {
            res = res + pre;
            pre = res - pre;
        }

        time(&end_time);
        time_diff = difftime(end_time, start_time);
        printf("fib(%d) = %ld, 耗时%fs\n", i, res, time_diff);
    }

}

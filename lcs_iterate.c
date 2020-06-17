#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef size_c
#define size_c 200
#endif

#define EQUAL 1  // 两字符串有相同字符
#define UP    2
#define LEFT  3


int max(int m, int n, int i, int j);
int ptint(int i, int j);

int len_of_lcs(char *str_a, char *str_b, int **char_a, int **char_b);
void print_lcs(char *str, int **b, int i, int j);
void lcs(char *str_a, char *str_b);


int main(int *argc, int *argv[]){
    char str_a[size_c], str_b[size_c];

    printf("请输入第一个字符串:");
    scanf("%s", str_a);
    while(strlen(str_a)>200){
        printf("输出超长，请重新输入:");
        scanf("%s", str_a);
    }

    printf("请输入第二个字符串:");
    scanf("%s", str_b);
    while(strlen(str_b)>200){
        printf("输出超长，请重新输入:");
        scanf("%s", str_b);
    }

    lcs(str_a, str_b);
    return 0;
}


/*-----------------------最长公共子序列长度，迭代版-----------------------
 * 分别从两个字符串头部开始循环，当两字符一致时，长度为左上角+1，
 * 当两字符不一致时，长度为上方和左方较大的那一个值
 * ---------------------------------------------------------------------*/
int len_of_lcs(char *str_a, char *str_b, int **char_a, int **char_b){
    // 计算两字符串长度
    int len_of_a = strlen(str_a);
    int len_of_b = strlen(str_b);

    // 初始化两个二维数组
    int i, j;
    for(i = 0; i <= len_of_a; i++){
        char_a[i][0] = 0;
    }

    for(j = 0; j <= len_of_b; j ++){
        char_b[0][j] = 0;
    }

    for(i = 0; i < len_of_a; i ++){
        for(j = 0; j < len_of_b; j++){
            if(str_a[i] == str_b[j]){
                char_a[i+1][j+1] = char_a[i][j] + 1;
                char_b[i+1][j+1] = EQUAL;
            }
            else if(char_a[i-1][j] >= char_b[i][j-1]){
                char_a[i+1][j+1] = char_a[i][j+1];
                char_b[i+1][j+1] = UP;
            }
            else{
                char_a[i+1][j+1] = char_a[i+1][j];
                char_b[i+1][j+1] = LEFT;
            }
        }
    }
    return char_a[len_of_a][len_of_b];
}


/*----------------------最长公共子序列值，迭代版------------------------
 *接受两个字符串，输出他们的最长公共子序列的值
 * -------------------------------------------------------------------*/
void print_lcs(char *str, int **b, int i, int j){
    if(i == 0 || j == 0){
        return;
    }

    if(b[i][j] == EQUAL){
        print_lcs(str, b, i-1, j-1);
    }
    else if(b[i][j] == UP){
        print_lcs(str, b, i-1, j-1);
        printf("%c", str[i-1]);
    }
    else{
        print_lcs(str, b, i, j-1);
    }
}


/*------------------------最长公共子序列--------------------
 * 接受两个字符串，返回他们的最长公共在序列的长度，
 * 并打印出最长公共子序列
 * -------------------------------------------------------*/
void lcs(char *str_a, char *str_b){
    int i, j, length;
    int len_of_a = strlen(str_a);
    int len_of_b = strlen(str_b);

    // 申请二维数组
    int **char_a = (int **)malloc(sizeof(int *)*(len_of_a + 1));
    int **char_b = (int **)malloc(sizeof(int *)*(len_of_a + 1));
    for(i = 0; i <= len_of_a; i++){
        char_a[i] = (int *)malloc(sizeof(int) * (len_of_b + 1));
        char_b[i] = (int *)malloc(sizeof(int) * (len_of_b + 1));
    }

    // 初始化两数组为0
    for(i = 0; i <= len_of_a; i++){
        for(j = 0; j <= len_of_b; j++){
            char_a[i][j] = 0;
            char_b[i][j] = 0;
        }
    }
    length = len_of_lcs(str_a, str_b, char_a, char_b);
    printf("the length of longest common subsequence is %d\n", length);

    // 输出最长公共子序列
    printf("the longest common subsequence is:\n");
    print_lcs(str_a, char_b, len_of_a, len_of_b);
    printf("\n");

    // 释放内存
    for(i=0; i<=len_of_a; i++){
        free(char_a[i]);
        free(char_b[i]);
    }
    free(char_a);
    free(char_b);
}


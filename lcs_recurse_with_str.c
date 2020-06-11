#include <stdio.h>
#include <string.h>

char * lcs(char A[], char B[]);

int main(int argc, char const *argv[]){
    char A[] = "abc";
    char B[] = "adc";
    int res_max_len = strlen(A) > strlen(B) ? strlen(B) : strlen(A);
    char res[res_max_len];
    res = lcs(A, B);
    int len_of_s = strlen(res);
    printf("logest common sequence is:\n %s\n", res);
    printf("the length of lcs is %d", len_of_s);
}

/*---Longest Common-----------------------
 * lcs函数接受两个字符串为参数，
 * 找到两个字符串中最长的公共子序列并返回
*---------------------------------------*/
char * lcs(char A[], char B[]){
    int lenOfA = strlen(A);
    int lenOfB = strlen(B);
    char res[];
    if (lenOfA == 0 || lenOfB == 0){  
        // 当任一字符串长度为0，返回空数组
        res = '';
    }else if (A[lenOfA-1] == B[lenOfB-1]) { 
        // 当俩字符串末尾字符一致时，记录末尾字符
        char last[1] = A[lenOfA-1];
        // 截取两个字符串末位之前的字符继续比较
        char sliceA[];
        char sliceB[];
        strncpy(sliceA, A, lenOfA-1);
        strncpy(sliceB, B, lenOfB-1);
        res = strcat(lcs(A[], B[]), last);
    }else{
        // 当末位字符不一致时，
        // 分别截取A或B的末位字符与另一字符串比较，
        // 取较长的那个结果
        char sliceA[];
        char sliceB[];
        strncpy(sliceA, A, lenOfA-1);
        strncpy(sliceB, B, lenOfB-1);
        resA = lcs(sliceA, B);
        resB = lcs(sliceB, A);
        res = strlen(resA) > strlen(resB) ? resA : resB;
    }
    return res;
}


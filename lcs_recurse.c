#include <stdio.h>
#include <string.h>

int lcs(char A[], char B[]);
void * slice(char A[], int start, int end, char res[]);

int main(int argc, char const *argv[]){
    char A[] = "Tsinghua University";
    char B[] = "Peking University";
    int res;
    res = lcs(A, B);
    printf("the length of lcs is %d\n", res);
}

/*---Longest Common-----------------------
 * lcs函数接受两个字符串为参数，
 * 找到两个字符串中最长的公共子序列,
 * 返回该序列长度
*---------------------------------------*/
int lcs(char A[], char B[]){
    printf("Current String: \nA:%s\nB:%s\n>>>>>>\n", A, B);
    int lenOfA = strlen(A);
    int lenOfB = strlen(B);
    int res;
    if (lenOfA == 0 || lenOfB == 0){  
        // 当任一字符串长度为0，返回空数组
        res = 0;
    }else if (A[lenOfA-1] == B[lenOfB-1]) { 
        // 当俩字符串末尾字符一致时,迭代两个字符串截去末位后的值
        printf("Same Last Char:%c\n", A[lenOfA-1]);
        char ASlice[lenOfA];
        char BSlice[lenOfB];
        strncpy(ASlice, A, lenOfA-1);
        ASlice[lenOfA-1] = '\0';
        printf("Slice A\nA:%s\nASlice:%s\n", A, ASlice);
        strncpy(BSlice, B, lenOfB-1);
        BSlice[lenOfB-1] = '\0';
        printf("Slice B\nB:%s\nBSlice:%s\n", B, BSlice);
        res = lcs(ASlice, BSlice) + 1;
    }else{
        // 当末位字符不一致时，
        // 分别Slice A或B的末位字符与另一字符串比较，
        // 取较长的那个结果
        printf("Diff Last Char:%c&%c\n", A[lenOfA-1], B[lenOfB-1]);
        char ASlice[lenOfA];
        char BSlice[lenOfB];
        strncpy(ASlice, A, lenOfA-1);
        ASlice[lenOfA-1] = '\0';
        printf("Slice A\nA:%s\nASlice:%s\n", A, ASlice);
        strncpy(BSlice, B, lenOfB-1);
        BSlice[lenOfB-1] = '\0';
        printf("Slice B\nB:%s\nBSlice:%s\n", B, BSlice);
        int resA, resB;
        resA = lcs(ASlice, B);
        resB = lcs(A, BSlice);
        res = resA > resB ? resA : resB;
    }
    return res;
}

void * slice(char A[], int start, int end, char res[]){
    /* ---切片------------------------------
     * 接受字符串，切片的起始位置和终止位置
     * 指定位置的字符切片写入结果字符串
     * -----------------------------------*/
    int lenOfA = strlen(A);
    if (start > lenOfA || start > end){
         res = "";
    }else{
        for(int i = start; i < end; i++){
            res[i] = A[i];
        }
    }
}


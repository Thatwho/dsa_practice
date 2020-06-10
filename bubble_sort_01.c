#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int A[], int length);
void swap(int *A, int *B);
void print_array(int A[], int length);

int main(){
    int test_array[] = {1000, 15, 28, 456457, 123, 87, 214, 666, 809, 234, 89, };
    int length_of_array = sizeof(test_array)/sizeof(*test_array);
    bubble_sort(test_array, length_of_array);
    length_of_array = sizeof(test_array)/sizeof(*test_array);
    print_array(test_array, length_of_array);
}

void bubble_sort(int A[], int length) {
    // 起泡排序
    print_array(A, length);
    
    int loop_n = 1;  // 记录循环次

    for(bool sorted=false; sorted = !sorted; length--, loop_n++){
        printf("第%d轮循环, 检查前%d个元素\n", loop_n, length);
        for(int i=1; i<length; i++) {
            // 自左向右，追对检查A[0, n)内各相邻元素
            if (A[i-1]>A[i]){
                // 当前一个数大于后一个数时，交换两数，并标记数组为未排序
                swap(&A[i-1], &A[i]);
                sorted = false;
            }
            print_array(A, length);
            printf(">>>>> NEXT <<<<<\n");
        }
        sorted ? printf("排序完成:\n"): length ;
    }
}

void swap(int *A, int *B){
    // 交换两个整数
    int tmp = *B;
    *B = *A;
    *A = tmp;
}

void print_array(int A[], int length){
    // 接受数组和长度，打印出里面的元素
    printf("{");
    for(int i = 0; i < length; i++){
        printf("%d, ", A[i]);
    }
    printf("}\n");
}


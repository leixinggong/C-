//
//  main.c
//  (选择/冒泡/快速)快速排序
//
//  Created by 龚磊星 on 2018/11/25.
//  Copyright © 2018 龚磊星. All rights reserved.
//

#include <stdio.h>

void quickSort(int *arry,int low,int high)
{
    /// 只有当元素大于等于2的时候才进行排序
    if (low < high) {
        
        int pivot = arry[low];
        int l = low;
        int h = high;
        
        /// 如果下标 l 不小于 h  那么分片的数组 要么之后一个元素 或者没有元素
        while (l < h) {
            /// 当低位有空缺的时候 高位就开始和中轴开始比较 若高位大于或等于中轴那么 h-- 若高位小于中轴那么跳出循环 将高位赋值给低位空缺处
            while (arry[h] >= pivot && l < h)
                h--;
            arry[l] = arry[h];
            
            /// 当高位有空缺的时候 低位就开始和中轴开始比较 若低位小于或等于中轴那么 l++ 若低大于中轴那么跳出循环 将低位赋值给高位空缺处
            while (arry[l] <= pivot && l < h)
                l++;
            arry[h] = arry[l];
        }
        
        /**
         走到这里那么就说明 l = h 因为只有 l = h 时候外层循环才会结束
         */
        arry[l] = pivot;
        quickSort(arry, low, l-1);  //left 递归 将中轴左边的分片排序
        quickSort(arry, l+1, high); //right 递归将中轴右边的分片排序
    }
    
}


void selectSort(int * array, int len)
{
    int idx = 0;
    for (int i = 0; i < len - 1; i++) {
        idx = i;
        for (int j = i + 1; j < len; j++) {
            if (array[idx] > array[j]) {
                idx = j;
            }
        }
        
        if (idx != i)
        {
            array[idx] ^= array[i];
            array[i] ^= array[idx];
            array[idx] ^= array[i];
        }
    }
}


void popSort(int * array, int len)
{
    for (int i = 0; i < len; i++) {
        int flag = 0;
        for (int j = 0; j < len - i - 1; j++) {
            
            if (array[j] > array[j+1]) {
                flag = 1;
                array[j] ^= array[j+1];
                array[j+1] ^= array[j];
                array[j] ^= array[j+1];
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main(int argc, const char * argv[]) {

    
    int array[] = {12,3,5,76,34,87,2,7,26,90,91};
    
    int len = sizeof(array)/sizeof(array[0])                 ;
    //quickSort(array, 0, len - 1);
    //selectSort(array, len);
    popSort(array, len);
    
    for (int i = 0; i < len; i++)
    {
        printf("%d ",array[i]);
    }
    
    printf("\n");
    
    return 0;
}
